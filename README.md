# Hashtables #

A basic educational implementation of a hashtables in C. Keys are strings and
values are integers. See `main.c` file for examples.

Two implementations are proposed in a seemingly object-oriented way:

- Open addressing with linear probing. Load factor is kept under 75%.
- Chaining with simple linked lists.

Possible operations are:

- Adding (and overriding) keys
- Lookup
- Remove (only for chaining HT)

The hash function is very straighforward. It just sums all characters in the
key, and clips it to a correct range:


``` C
char * c = key;
int hash_val = 0;

while(*c != '\0') {
  hash_val += *c;
  c++;
}
hash_val = hash_val % max;
```
