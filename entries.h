#ifndef ENTRIES_H 
#define ENTRIES_H

/* type of an entry in a hashtable */
struct entry_t {
  int val;
  char * key;
  struct entry_t * next;
};
typedef struct entry_t entry_t;

/* add a value with given key to an entry list
 * return -1 on error, 0 if key did not exist, else 1 
 */
int add_to_entry_list(entry_t ** entry_list, char * key, int val);


#endif
