#include "board.h"
#include <assert.h>
#include <string.h>

bool board[X_MAX][Y_MAX];

void board_init() { memset(board, 0, sizeof(board)); }

bool board_at(int x, int y) {

  if (x >= X_MAX) {
    x = x % X_MAX;
  }
  if (x < 0) {
    x = X_MAX + (x % X_MAX);
  }
  if (y >= Y_MAX) {
    return false;
  }
  return board[x][y];
}

void board_set(unsigned int x, unsigned int y, bool value) {
  board[x][y] = value;
}
