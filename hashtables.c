#include <stdlib.h>
#include <string.h>

#include "hashtables.h"


/* Just sum all chars in keys and map it to [0, max - 1] by modulo */
int hash(char * key, int max) {
  char * c = key;
  int hash_val = 0;

  if (c == NULL) {
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
  return -1;
}

int lookup_chaining(struct ht_t * ht, char * key, int * ret) {
  return -1;
}

int remove_chaining(struct ht_t * ht, char * key) {
  return -1;
}

#include "hashtables.h"
