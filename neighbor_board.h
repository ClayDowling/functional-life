#ifndef _NEIGHBOR_BOARD_H_
#define _NEIGHBOR_BOARD_H_

#include "board.h"
#include <stdint.h>

void neighbor_init(void);
int neighbor_at(int x, int y);
void neighbor_set(int x, int y, int value);

#endif
