#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hashtables.h"
#include "entry_chaining.h"
#include "entry_oa.h"
#include "common.h"

/* Just sum all chars in keys and map it to [0, max - 1] by modulo */
int hash(char * key, int max) {
  char * c = key;
  int hash_val = 0;

  if (c == NULL) {
    print_error("hash", "key is NULL");
    return -1;
  }

  while(*c != '\0') {
    hash_val += *c;
    c++;
  }
  hash_val = hash_val % max;

  return hash_val;
}

/* return an initialised hashtable */
ht_t * init_ht(int size, 
               int (*add)(ht_t *, char *, int),
               int (*lookup)(ht_t *, char *, int *),
               int (*remove)(ht_t *, char *),
               void (*print)(ht_t *)
               ) {

  ht_t * ht = malloc(sizeof(ht_t));
  ht->size = size;
  ht->n_entries = 0;
  ht->data = malloc(sizeof(void *) * ht->size);
  // init all entry lists to NULL (normally done by malloc anyway)
  memset(ht->data, 0, sizeof(void *) * ht->size); 
  ht->add = add;
  ht->lookup = lookup;
  ht->remove = remove;
  ht->print = print;

  return ht;
}

int add_chaining(struct ht_t * ht, char * key, int val) {
  int index = 0;
  int key_exists = 0; /* 1 if key was already in ht else 0 */
  
  if((index = hash(key, ht->size)) == -1) {
    print_error("add_chaining", "invalid index");
    return -1;
  }

  key_exists = add_to_entry_list((entry_chaining_t **)&(ht->data[index]),
                                  key, 
                                  val);
  if (key_exists == -1) {
    print_error("add_chaining", "could not add new entry");
    return -1;
  } else if(key_exists == 0) {
    ht->n_entries += 1;
  }

  return 0;
}

int lookup_chaining(struct ht_t * ht, char * key, int * val) {
  int index = 0;
  
  if((index = hash(key, ht->size)) == -1) {
    print_error("lookup_chaining", "invalid index");
    return -1;
  }

  if(lookup_in_entry_list((entry_chaining_t *)ht->data[index], 
                           key, 
                           val) == -1) {
    print_error("lookup_chaining", "key not found");
    return -1;
  }

  return 0;
}

int remove_chaining(struct ht_t * ht, char * key) {
  int index = 0;
  
  if((index = hash(key, ht->size)) == -1) {
    print_error("remove_chaining", "invalid index");
    return -1;
  }

  if(remove_from_entry_list((entry_chaining_t **)&(ht->data[index]), 
                             key) == -1) {
    print_error("remove_chaining", "key not found");
    return -1;
  } else {
    ht->n_entries -= 1;
  }
  return 0;
}

void print_chaining(struct ht_t * ht) {
  int i = 0;
  entry_chaining_t * aux = NULL;

  for (i = 0; i < ht->size; i++) {
    aux = (entry_chaining_t *)ht->data[i];
    while(aux != NULL) {
      printf("%s -> %d\n", aux->key, aux->val);
      aux = aux->next;
    }
  }
}

int add_oa(struct ht_t * ht, char * key, int val) {
  int index = 0;
  entry_oa_t * new_entry = NULL;
  
  if((index = hash(key, ht->size)) == -1) {
    print_error("add_chaining", "invalid index");
    return -1;
  }
  if(ht->data[index] == NULL) {
    ht->data[index] = malloc(sizeof(entry_oa_t));
    new_entry = (entry_oa_t *)ht->data[index];
    new_entry->state = OCCUPIED;
    new_entry->val = val;
  }

  return -1;
}

int lookup_oa(struct ht_t * ht, char * key, int * val) {
  return -1;
}

int remove_oa(struct ht_t * ht, char * key) {
  return -1;
}

void print_oa(struct ht_t * ht) {
}

#include "hashtables.h"
