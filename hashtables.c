#include <stdlib.h>
#include <string.h>

#include "hashtables.h"
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
               int (*remove)(ht_t *, char *)
               ) {

  ht_t * ht = malloc(sizeof(ht_t));
  ht->size = size;
  ht->n_entries = 0;
  ht->data = malloc(sizeof(entry_t) * ht->size);
  // init all entry lists to NULL (normally done by malloc anyway)
  memset(ht->data, 0, sizeof(entry_t *) * ht->size); 
  ht->add = add;
  ht->lookup = lookup;
  ht->remove = remove;

  return ht;
}

int add_chaining(struct ht_t * ht, char * key, int val) {
  int index = 0;
  int key_exists = 0; /* 1 if key was already in ht */
  
  if((index = hash(key, ht->size)) == -1) {
    print_error("add_chaining", "invalid index");
    return -1;
  }

  key_exists = add_to_entry_list(&(ht->data[index]), key, val);
  if (key_exists == -1) {
    print_error("add_chaining", "could not add new entry");
    return -1;
  } else if(key_exists == 0) {
    ht->n_entries += 1;
  }

  return 0;
}

int lookup_chaining(struct ht_t * ht, char * key, int * ret) {
  return -1;
}

int remove_chaining(struct ht_t * ht, char * key) {
  return -1;
}

#include "hashtables.h"
