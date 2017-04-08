#include "neighbor.h"
#include "board.h"

int neighbors(int x, int y) {
  int count = 0;
  int i;
  int j;

  for (i = -1; i < 2; ++i) {
    for (j = -1; j < 2; ++j) {
      if (board_at(x + i, y + j) && !(0 == i && 0 == j)) {
        ++count;
      }
    }
  }
  return count;
}
