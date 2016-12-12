#ifndef ENTRY_OA_H
#define ENTRY_OA_H

enum entry_oa_state_t {OCCUPIED, FREE};
typedef enum entry_oa_state_t entry_oa_state_t;

struct entry_oa_t {
  int val;
  char * key;
  entry_oa_state_t state;
};
typedef struct entry_oa_t entry_oa_t;

/* add a value with given key to an open addressing array of size s
 * linear probing starts at given index
 * return -1 if array is full, 0 if key did not exist, else 1
 */
int add_to_oa_array(entry_oa_t * array, int s, int index, char * key, int val);

/* look for entry with given key in oa array of size s and put its value in val
 * linear probing starts at given index
 * return -1 if key did not exist, else 0
 */
int lookup_in_oa_array(entry_oa_t * array, int s, int index, char * key,
                       int * val);

/* not implemented. Use chaining remove is needed
 * return -1
 */
int remove_from_oa_array(entry_oa_t * array, char * key);

#endif
