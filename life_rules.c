#include "life_rules.h"

int life(int x, int y, ptrToGetter getter) {
  int ncount = getter(x, y);
  if (2 == ncount || 3 == ncount) {
    return 1;
  }
  return 0;
}
