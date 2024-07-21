#ifndef VM_H
#define VM_H

#include "chunk.h"

class VM {
  Chunk *chunk;

public:
  VM();
  ~VM();
};

#endif
