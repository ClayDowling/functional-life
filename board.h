#ifndef _BOARD_H_
#define _BOARD_H_

#include <stdbool.h>

#define X_MAX 100
#define Y_MAX 100

void board_init();
int board_at(int x, int y);
void board_set(int x, int y, int value);

#endif
