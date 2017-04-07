#include <string.h>
#include "board.h"

bool board[X_MAX][Y_MAX];

void init_board()
{
  memset(board, 0, sizeof(board));
}
