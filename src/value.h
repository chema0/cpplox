#ifndef cpplox_value_h
#define cpplox_value_h

#include "common.h"

using Value = double;

struct ValueArray {
  int capacity;
  int count;
  Value *values;
};

void init_value_array(ValueArray *array);
void write_value_array(ValueArray *array, Value value);
void free_value_array(ValueArray *array);
void print_value(Value value);

#endif
