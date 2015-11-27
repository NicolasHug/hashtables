#ifndef ENTRY_OA_H
#define ENTRY_OA_H

enum entry_oa_state_t {OCCUPIED, FREE};
typedef enum entry_oa_state_t entry_oa_state_t;

struct entry_oa_t {
  int val;
  entry_oa_state_t state;
};
typedef struct entry_oa_t entry_oa_t;

#endif
