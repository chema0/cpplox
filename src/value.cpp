#include <stdio.h>

#include "memory.h"
#include "value.h"

ValueArray::ValueArray() {
  values = nullptr;
  capacity = 0;
  count = 0;
}

// ValueArray::~ValueArray() { FREE_ARRAY(Value, values, capacity); }
ValueArray::~ValueArray() {}

void ValueArray::write(Value value) {
  if (capacity < count + 1) {
    int old_capacity = capacity;
    capacity = GROW_CAPACITY(old_capacity);
    values = GROW_ARRAY(Value, values, old_capacity, capacity);
  }

  values[count] = value;
  count++;
}

/* Getters and setters */

int ValueArray::get_capacity() { return capacity; }
int ValueArray::get_count() { return count; }
Value *ValueArray::get_values() { return values; }

void print_value(Value value) { printf("%g", value); }
