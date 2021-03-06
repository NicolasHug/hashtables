#include <stdio.h>

#include "hashtables.h"
#include "entry_oa.h"

void test_1() {
  /* Build a chained HT, override some keys, remove some, etc... */

  int i = 0;
  const int n_keys = 4;
  const int size = 32;
  char * keys [] = {"key1",
                    "key2",
                    "collision",
                    "collisino",
                   };
  ht_t * ht = init_ht(size,
                      init_data_chaining,
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
  /* Build a chaining HT of size 8 and add 16 keys.*/

  const int size = 8;
  ht_t * ht = init_ht(size,
                      init_data_chaining,
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
  /* Build an open adressing HT of size 8 and add 16 keys. HT will be
   * resized. */

  const int size = 8;
  ht_t * ht = init_ht(size,
                      init_data_oa,
                      add_oa,
                      lookup_oa,
                      remove_oa,
                      print_oa
                      );
  int ret = 0;
  int i = 0;
  char key [10];

  /* collisions are inevitable here + need to resize */
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

int main() {
  printf("Test_1\n");
  test_1();
  printf("\nTest_2\n");
  test_2();
  printf("\nTest_3\n");
  test_3();

  return 0;
}
