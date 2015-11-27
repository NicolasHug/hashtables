#include <stdio.h>

#include "hashtables.h"

void test_1() {
  int i = 0;
  const int n_keys = 4;
  const int size = 32;
  char * keys [] = {"key1",
                    "key2", 
                    "collision", 
                    "collisino",
                   };

  ht_t * ht = init_ht(size,
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

  printf("n_entries : %d\n", ht->n_entries);

  printf("\nlet's overwrite some keys and add some new ones\n");
  ht->add(ht, "key1", 20);
  ht->add(ht, "collision", 30);
  ht->add(ht, "clolision", 31);

  ht->print(ht);

  printf("\nand now let's remove some keys\n");
  ht->remove(ht, "key1");
  ht->remove(ht, "collisino");
  ht->remove(ht, "does_not_exist");

  ht->print(ht);

  printf("n_entries : %d\n", ht->n_entries);
}

void test_2() {
  const int size = 8;
  ht_t * ht = init_ht(size,
                      add_chaining,
                      lookup_chaining,
                      remove_chaining,
                      print_chaining
                      ); 
  int ret = 0;
  int i = 0;
  char key [10];

  /* collisions are inevitable here */
  for (i = 0; i < size * 2; i++) {
    sprintf(key, "%d", i);
    ht->add(ht, key, i);
  }

  for (i = 0; i < size * 2; i++) {
    sprintf(key, "%d", i);
    ht->lookup(ht, key, &ret);
    printf("%d -> %d\n", i, ret);
  }
}

void test_3() {
  const int size = 8;
  ht_t * ht = init_ht(size,
                      add_chaining,
                      lookup_oa,
                      remove_oa,
                      print_oa
                      ); 
  //int ret = 0;
  int i = 0;
  char key [10];

  for (i = 0; i < size; i++) {
    sprintf(key, "%d", i);
    ht->add(ht, key, i);
  }
}

int main() {
  test_3();

  return 0;
}
