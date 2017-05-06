#include "life_rules.h"
#include "board.h"

int life(int x, int y, ptrToGetter getter) {
  int ncount = getter(x, y);
  bool isalive = board_at(x, y);
  if (isalive) {
    if (2 == ncount || 3 == ncount) {
      return 1;
    }
  } else {
    if (3 == ncount) {
      return 1;
    }
  }
  return 0;
}
