#include <stdio.h>

#include "chunk.h"
#include "debug.h"
#include "value.h"

void disassemble_chunk(Chunk *chunk, const char *name) {
  printf("== %s ==\n", name);

  for (int offset = 0; offset < chunk->get_count();) {
    offset = disassemble_instruction(chunk, offset);
  }
}

static int simple_instruction(const char *name, int offset) {
  printf("%s\n", name);
  return offset + 1;
}

static int constant_instruction(const char *name, Chunk *chunk, int offset) {
  uint8_t constant = chunk->get_code()[offset + 1];
  printf("%-16s %4d '", name, constant);
  Value *constants = chunk->get_constants().get_values();
  print_value(constants[constant]);
  printf("'\n");
  return offset + 2;
}

int disassemble_instruction(Chunk *chunk, int offset) {
  printf("%04d ", offset);
  if (offset > 0 &&
      chunk->get_lines()[offset] == chunk->get_lines()[offset - 1]) {
    printf("   | ");
  } else {
    printf("%4d ", chunk->get_lines()[offset]);
  }

  uint8_t instruction = chunk->get_code()[offset];
  switch (instruction) {
  case OP_CONSTANT:
    return constant_instruction("OP_CONSTANT", chunk, offset);
  case OP_RETURN:
    return simple_instruction("OP_RETURN", offset);
  default:
    printf("Unknown opcode %d\n", instruction);
    return offset + 1;
  }
}
