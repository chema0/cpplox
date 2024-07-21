#ifndef cpplox_vm_h
#define cpplox_vm_h

#include "chunk.h"

typedef struct {
  Chunk *chunk;
} VM;

void init_vm();
void free_vm();

#endif
