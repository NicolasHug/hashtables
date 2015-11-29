#include <string.h>
#include <stdlib.h>

#include "entry_oa.h"
#include "common.h"

int add_to_oa_array(entry_oa_t * array, int s, int index, char * key, int val)
{
  int found_spot = 0;
  int exists = 0;
  int i = index;

  while(!found_spot) {
    if(array[i].state == FREE){
      found_spot = 1;
    } else if (strcmp(array[i].key, key) == 0){
      found_spot = 1;
      exists = 1;
    }

    i = (i + 1) % s; /* linear probing */
    if (i == index) {
      return - 1;
    }
  }

  /* decrement i */
  i = (i == 0) ? s - 1 : i - 1;

  array[i].state = OCCUPIED;
  if(!exists) {
    array[i].key = malloc(sizeof(char) * strlen(key));
  }
  strcpy(array[i].key, key);
  array[i].val = val;

  return exists;
}

int lookup_in_oa_array(entry_oa_t * array, int s, int index, char * key, int *
val) {
  int found = 0;
  int stop = 0;
  int i = index;

  while(!found && !stop) {
    if(array[i].state == FREE) {
      stop = 1;
    } else if(strcmp(array[i].key, key) == 0) {
      found = 1;
      *val = array[i].val;
    }

    i = (i + 1) % s;
    if (i == index) {
      stop = 1;
    }
  }

  return found ? 0 : -1;
}

int remove_from_oa_array(entry_oa_t * array, char * key) {
  print_error("remove_from_oa_array", "not implemented");
  return -1;
}
