#ifndef cpplox_memory_h
#define cpplox_memory_h

#include "common.h"

// Calculates a new capacity based on a given current capacity. It scales
// based on the old size. Grows by a factor of two (1.5x).
#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, old_count, new_count)                        \
  (type *)reallocate(pointer, sizeof(type) * (old_count),                      \
                     sizeof(type) * (new_count))

void *reallocate(void *pointer, size_t old_size, size_t new_size);

#endif
