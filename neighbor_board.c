#include "neighbor_board.h"
#include <limits.h>
#include <string.h>

uint8_t board[X_MAX][Y_MAX];

void neighbor_init(void) { memset(board, 0, sizeof(board)); }

uint8_t neighbor_at(int x, int y) {
  if (x < 0 || x >= X_MAX)
    return 0;
  if (y < 0 || y >= Y_MAX)
    return 0;
  return board[x][y];
}

void neighbor_set(int x, int y, uint8_t value) {

  if (x < 0)
    return;
  if (x >= X_MAX)
    return;
  if (y < 0)
    return;
  if (y >= Y_MAX)
    return;

  board[x][y] = value;
}
