#include "board_iterator.h"
#include "board.h"

void board_iterator(ptrToGetter getter, ptrToSetter setter,
                    ptrToGenerator generator) {
  for (int i = 0; i < X_MAX; ++i) {
    for (int j = 0; j < Y_MAX; ++j) {
      setter(i, j, generator(i, j, getter));
    }
  }
}
