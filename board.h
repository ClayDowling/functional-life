#ifndef _BOARD_H_
#define _BOARD_H_

#include <stdbool.h>

#define X_MAX 100
#define Y_MAX 100

extern bool board[X_MAX][Y_MAX];

void init_board();

#endif
