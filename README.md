# README #

Basic educational implementation of a hashtables in C. Keys are strings and
values are integers.

Two implementations are proposed in a seemingly object-oriented way:

- Open addressing with linear probing. Load factor is kept under 75%.
- Chaining with simple linked lists.

Possible operations are:

- Adding (and overriding) keys
- Lookup
- Remove (only for chaining HT)

The hash function is very straighforward and just sums all characters in the
key, and clip it to a correct range:


    char * c = key;
    int hash_val = 0;

    while(*c != '\0') {
      hash_val += *c;
      c++;
    }
    hash_val = hash_val % max;
