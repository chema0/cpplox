#include "chunk.h"
#include "memory.h"
#include "value.h"

Chunk::Chunk() {
  count = 0;
  capacity = 0;
  code = nullptr;
  lines = nullptr;
  constants = ValueArray();
}

Chunk::~Chunk() {
  FREE_ARRAY(uint8_t, code, capacity);
  FREE_ARRAY(int, lines, capacity);
}

void Chunk::write(uint8_t byte, int line) {
  if (capacity < count + 1) {
    int old_capacity = capacity;
    capacity = GROW_CAPACITY(old_capacity);
    code = GROW_ARRAY(uint8_t, code, old_capacity, capacity);
    lines = GROW_ARRAY(int, lines, old_capacity, capacity);
  }

  code[count] = byte;
  lines[count] = line;
  count++;
}

int Chunk::add_constant(Value value) {
  constants.write(value);
  return constants.get_count();
}

/* Getters and setters */

int Chunk::get_count() { return count; }
int Chunk::get_capacity() { return capacity; }
uint8_t *Chunk::get_code() { return code; }
int *Chunk::get_lines() { return lines; }
ValueArray Chunk::get_constants() { return constants; }
