#ifndef _BOARD_ITERATOR_H_
#define _BOARD_ITERATOR_H_

typedef int(ptrToGetter(int, int));

#define board_iterator(GETTER, SETTER, GENERATOR)                              \
  for (int _x = 0; _x < X_MAX; ++_x) {                                         \
    for (int _y = 0; _y < Y_MAX; ++_y) {                                       \
      SETTER(_x, _y, GENERATOR(_x, _y, GETTER));                               \
    }                                                                          \
  }

#endif
