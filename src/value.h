#ifndef VALUE_H
#define VALUE_H

#include "common.h"

using Value = double;

void print_value(Value value);

class ValueArray {
  int capacity;
  int count;
  Value *values;

public:
  ValueArray();
  ~ValueArray();

  void write(Value value);

  int get_capacity();
  int get_count();
  Value *get_values();
};

#endif
