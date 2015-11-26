#ifndef HASHTABLES_H
#define HASHTABLES_H

/* type of an entry in a hashtable */
struct entry_t {
  int val;
  char * key;
  struct entry_t * next;
};
typedef struct entry_t entry_t;

/* hashtable type. Keys are strings and elements are integers */
struct ht_t {
  int size; /* size of the data field */
  int n_entries; /* number of entries in data field */
  entry_t * data; /* array of entries */
  int (*add)(struct ht_t * ht, char * key, int val);
  int (*lookup)(struct ht_t * ht, char * key, int * ret);
  int (*remove)(struct ht_t * ht, char * key);
};
typedef struct ht_t ht_t;

/* hash function. Return an index in [0, max - 1]*/
int hash(char * key, int max);

#endif
