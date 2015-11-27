#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "entries.h"

int add_to_entry_list(entry_t ** entry_list, char * key, int val) {
  int exists = 0;
  entry_t * aux = *entry_list;
  while (aux != NULL && !exists) {
    if(strcmp(key, aux->key) == 0){
      exists = 1;
      aux->val = val; /* simply update the val field */
    }
    aux = aux->next;
  }
  if (!exists) {
    aux = malloc(sizeof(entry_t));
    /* set new entry key */
    aux->key = malloc(sizeof(char) * strlen(key));
    strcpy(aux->key, key);
    /* set new entry value */
    aux->val = val;
    /* add new entry to entry list */
    aux->next = *entry_list;
    *entry_list = aux;
  }

  return exists;
}
