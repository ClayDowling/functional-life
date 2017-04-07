#include <check.h>
#include "../board.h"

START_TEST(board_init_setsAllFieldsFalse)
{
  int x;
  int y;
  bool foundAlive = false;

  board[0][0] = true;
  init_board();

  for(x=0; x < X_MAX; ++x) {
    for(y=0; y < Y_MAX; ++y) {
      if (board[x][y]) {
        foundAlive = true;
      }
    }
  }

  ck_assert_int_eq(foundAlive, false);
}
END_TEST

TCase *tcase_board(void) {
  TCase *tc;

  tc = tcase_create("board");
  tcase_add_test(tc, board_init_setsAllFieldsFalse);

  return tc;
}

Suite *suite_board(void) {
  Suite *s;

  s = suite_create("board");
  suite_add_tcase(s, tcase_board());

  return s;
}
