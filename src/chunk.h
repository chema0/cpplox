#ifndef CHUNK_H
#define CHUNK_H

#include "common.h"
#include "value.h"

enum OpCode { OP_CONSTANT, OP_RETURN };

class Chunk {
  int count;
  int capacity;
  uint8_t *code;
  int *lines;
  ValueArray constants;

public:
  Chunk();
  ~Chunk();

  void write(uint8_t byte, int line);
  int add_constant(Value value);

  int get_count();
  int get_capacity();
  uint8_t *get_code();
  int *get_lines();
  ValueArray get_constants();
};

#endif
