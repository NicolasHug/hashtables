#ifndef HASHTABLES_H
#define HASHTABLES_H

/* hashtable type. Keys are strings and elements are integers */
struct ht_t {
  int size; /* size of the data field */
  int n_entries; /* number of entries in data field */
  void ** data; /* array of void pointers */
  int (*add)(struct ht_t * ht, char * key, int val);
  int (*lookup)(struct ht_t * ht, char * key, int * ret);
  int (*remove)(struct ht_t * ht, char * key);
  void (*print)(struct ht_t * ht);
};
typedef struct ht_t ht_t;

/* return an initialised hashtable */
ht_t * init_ht(int size, 
               int (*add)(ht_t *, char *, int),
               int (*lookup)(ht_t *, char *, int *),
               int (*remove)(ht_t *, char *),
               void (*print)(ht_t *)
               );


/* very basic hash function. 
 * key must be '\0' terminated
 * return an index in [0, max - 1], -1 on error 
 */
int hash(char * key, int max);

/* add an entry to ht with given value and key.
 * if key already exists, then the old value is overwritten
 * collisions are handled by chaining
 * return 0 on success, -1 on error
 */
int add_chaining(struct ht_t * ht, char * key, int val);

/* look for entry with given key in ht and put its value in val
 * collisions are handled by chaining
 * return 0 on success, -1 on error 
 */
int lookup_chaining(struct ht_t * ht, char * key, int * val);

/* remove entry with given key from ht
 * collisions are handled by chaining
 * return 0 on success, -1 on error
 */
int remove_chaining(struct ht_t * ht, char * key);

/* print all the entries in ht : key -> val 
 * collisions are handled by chaining
 */
void print_chaining(struct ht_t * ht);

/* add an entry to ht with given value and key.
 * if key already exists, then the old value is overwritten
 * implementation strategy is based on open addressing
 * return 0 on success, -1 on error
 */
int add_oa(struct ht_t * ht, char * key, int val);

/* look for entry with given key in ht and put its value in val
 * implementation strategy is based on open addressing
 * return 0 on success, -1 on error 
 */
int lookup_oa(struct ht_t * ht, char * key, int * val);

/* remove entry with given key from ht
 * implementation strategy is based on open addressing
 * return 0 on success, -1 on error
 */
int remove_oa(struct ht_t * ht, char * key);

/* print all the entries in ht : key -> val 
 * implementation strategy is based on open addressing
 */
void print_oa(struct ht_t * ht);

#endif
