#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "entry_chaining.h"

int add_to_entry_list(entry_chaining_t ** entry_list, char * key, int val){
  int exists = 0;
  entry_chaining_t * aux = *entry_list;
  while (aux != NULL && !exists) {
    if(strcmp(key, aux->key) == 0){
      exists = 1;
      aux->val = val; /* simply update the val field */
    }
    aux = aux->next;
  }
  if (!exists) {
    aux = malloc(sizeof(entry_chaining_t));
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

int lookup_in_entry_list(entry_chaining_t * entry_list, char * key, int * val) {
  int found = 0;
  entry_chaining_t * aux = entry_list;
  while (aux != NULL && !found) {
    if(strcmp(key, aux->key) == 0){
      found = 1;
      *val = aux->val;
    }
    aux = aux->next;
  }
  return found ? 0 : -1;
}

int remove_from_entry_list(entry_chaining_t ** entry_list, char * key) {
  int found = 0;
  entry_chaining_t * aux = *entry_list;
  entry_chaining_t * pred = *entry_list;

  /* handle special case where entry to remove is the first one */
  if(aux && strcmp(aux->key, key) == 0) {
    found = 1;
    *entry_list = aux->next;
    free(aux);
  }

  /* general case */
  while(aux != NULL && !found) {
    if (strcmp(aux->key, key) == 0) {
      found = 1;
      pred->next = aux->next;
      free(aux);
    }
    pred = aux;
    aux = aux->next;
  }

  return found ? 0 : -1;
}
