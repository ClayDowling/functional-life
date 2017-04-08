#include <assert.h>
#include <string.h>
#include "board.h"

bool board[X_MAX][Y_MAX];

void board_init()
{
  memset(board, 0, sizeof(board));
}

bool board_at(unsigned int x, unsigned int y)
{
        assert(x >= 0);

        if (x >= X_MAX) {
                x = x % X_MAX;
        }

        if (y >= Y_MAX) {
                return false;
        }

        return board[x][y];
}

void board_set(unsigned int x, unsigned int y, bool value)
{
        // Do nothing until we test this
}
