#ifndef cpplox_vm_h
#define cpplox_vm_h

#include "chunk.h"

struct VM {
  Chunk *chunk;
};

void init_vm();
void free_vm();

#endif
