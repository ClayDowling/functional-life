#include "neighbor.h"
#include "board.h"

int neighbors(int x, int y, ptrToGetter getter) {
  int count = 0;

  if (getter(x - 1, y - 1))
    ++count;
  if (getter(x, y - 1))
    ++count;
  if (getter(x + 1, y - 1))
    ++count;
  if (getter(x - 1, y))
    ++count;
  if (getter(x + 1, y))
    ++count;
  if (getter(x - 1, y + 1))
    ++count;
  if (getter(x, y + 1))
    ++count;
  if (getter(x + 1, y + 1))
    ++count;

  return count;
}
