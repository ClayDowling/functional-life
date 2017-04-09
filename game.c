#include "game.h"
#include "board.h"
#include "board_iterator.h"
#include "life_rules.h"
#include "neighbor.h"
#include "neighbor_board.h"

void game_generation(void) {
  board_iterator(board_at, neighbor_set, neighbors);
  board_iterator(neighbor_at, board_set, life);
}
