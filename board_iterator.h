#ifndef _BOARD_ITERATOR_H_
#define _BOARD_ITERATOR_H_

typedef int(ptrToGetter(int, int));
typedef int(ptrToGenerator(int, int, ptrToGetter));
typedef void(ptrToSetter(int, int, int));

void board_iterator(ptrToGetter getter, ptrToSetter setter, ptrToGenerator generator);

#endif
