#include "chunk.h"
#include "debug.h"
using namespace std;

int main() {
  Chunk chunk;

  int constant = chunk.add_constant(1.2);
  chunk.write(OP_CONSTANT, 123);
  chunk.write(constant, 123);

  chunk.write(OP_RETURN, 123);
  disassemble_chunk(&chunk, "test chunk");
  return 0;
}
