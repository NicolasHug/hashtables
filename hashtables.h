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
  entry_t ** data; /* array of lists of entries */
  int (*add)(struct ht_t * ht, char * key, int val);
  int (*lookup)(struct ht_t * ht, char * key, int * ret);
  int (*remove)(struct ht_t * ht, char * key);
};
typedef struct ht_t ht_t;

/* return an initialised hashtable */
ht_t * init_ht(int size, 
               int (*add)(ht_t *, char *, int),
               int (*lookup)(ht_t *, char *, int *),
               int (*remove)(ht_t *, char *)
               );


/* very basic hash function. 
 * key must be '\0' terminated
 * return an index in [0, max - 1], -1 on error 
 */
int hash(char * key, int max);

/* add an entry to ht with given value and key
 * collisions are handled by chaining
 * return 0 on success, -1 on error
 */
int add_chaining(struct ht_t * ht, char * key, int val);

/* look for entry with given key in ht and put its value in ret
 * collisions are handled by chaining
 * return 0 on success, -1 on error 
 */
int lookup_chaining(struct ht_t * ht, char * key, int * ret);

/* remove entry with given key from ht
 * collisions are handled by chaining
 * return 0 on success, -1 on error
 */
int remove_chaining(struct ht_t * ht, char * key);

#endif
