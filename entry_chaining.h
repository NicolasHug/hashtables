#ifndef ENTRY_CHAINING_H 
#define ENTRY_CHAINING_H

/* type of an entry in a hashtable using chaining for collision handling */
struct entry_chaining_t {
  int val;
  char * key;
  struct entry_chaining_t * next;
};
typedef struct entry_chaining_t entry_chaining_t;

/* add a value with given key to an entry list
 * return -1 on error, 0 if key did not exist, else 1 
 */
int add_to_entry_list(entry_chaining_t ** entry_list, char * key, int val);


/* look for entry with given key in entry_list and put its value in val
 * return -1 if key did not exist, else 0
 */
int lookup_in_entry_list(entry_chaining_t * entry_list, char * key, int * val);


/* remove entry with given key from entry_list
 * return -1 if key did not exist, else 0
 */
int remove_from_entry_list(entry_chaining_t ** entry_list, char * key);


#endif
