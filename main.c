#include <stdio.h>

#include "hashtables.h"

#define SIZE 1024

int main () {
  int i = 0;
  const int n_keys = 4;
  char * keys [] = {"key1",
                    "key2", 
                    "collision", 
                    "collisino",
                   };

  ht_t * ht = init_ht(SIZE,
                      add_chaining,
                      lookup_chaining,
                      remove_chaining,
                      print_chaining
                      ); 
  int ret = 0;

  for (i = 0; i < n_keys; i++) {
    ht->add(ht, keys[i], i);
  }

  for (i = 0; i < n_keys; i++) {
    ht->lookup(ht, keys[i], &ret);
    printf("%s -> %d\n", keys[i], ret);
  }

  printf("let's overwrite some keys and add some new ones\n");
  ht->add(ht, "key1", 20);
  ht->add(ht, "collision", 30);
  ht->add(ht, "key3", 40);
  ht->add(ht, "3key", 41);

  ht->print(ht);

  return 0;
}
