#include "../board.h"
#include <check.h>

START_TEST(board_init_setsAllFieldsFalse) {
  unsigned int x;
  unsigned int y;
  bool foundAlive = false;

  board_set(0, 0, true);
  board_init();

  for (x = 0; x < X_MAX; ++x) {
    for (y = 0; y < Y_MAX; ++y) {
      if (board_at(x, y)) {
        foundAlive = true;
      }
    }
  }

  ck_assert_int_eq(foundAlive, false);
}
END_TEST

START_TEST(boardAt_withLocationTrue_returnsTrue) {
  board_init();
  board_set(1, 1, true);

  ck_assert_int_eq(true, board_at(1, 1));
}
END_TEST

START_TEST(boardAt_withLocationFalse_returnsFalse) {
  board_init();
  board_set(1, 1, false);

  ck_assert_int_eq(false, board_at(1, 1));
}
END_TEST

START_TEST(boardAt_wrapsOnXAxis) {
  board_init();
  board_set(0, 0, true);
  ck_assert_int_eq(true, board_at(X_MAX, 0));
}
END_TEST

START_TEST(boardAt_withYOverMax_returnsFalse) {
  board_init();
  for (unsigned int x = 0; x < X_MAX; ++x) {
    for (unsigned int y = 0; y < Y_MAX; ++y) {
      board_set(x, y, true);
    }
  }
  ck_assert_int_eq(false, board_at(0, Y_MAX));
}
END_TEST

START_TEST(boardSet_toTrue_retrievesTrue) {
  board_init();
  board_set(50, 50, true);
  ck_assert_int_eq(true, board_at(50, 50));
}
END_TEST

START_TEST(boardSet_toFalse_retrievesFalse) {
  board_init();
  for (unsigned int x = 0; x < X_MAX; ++x) {
    for (unsigned int y = 0; y < Y_MAX; ++y) {
      board_set(x, y, true);
    }
  }
  ck_assert_int_eq(true, board_at(50, 50));
  board_set(50, 50, false);
  ;
  ck_assert_int_eq(false, board_at(50, 50));
}
END_TEST

TCase *tcase_board(void) {
  TCase *tc;

  tc = tcase_create("board");
  tcase_add_test(tc, board_init_setsAllFieldsFalse);
  tcase_add_test(tc, boardAt_withLocationTrue_returnsTrue);
  tcase_add_test(tc, boardAt_withLocationFalse_returnsFalse);
  tcase_add_test(tc, boardAt_wrapsOnXAxis);
  tcase_add_test(tc, boardAt_withYOverMax_returnsFalse);
  tcase_add_test(tc, boardSet_toTrue_retrievesTrue);
  tcase_add_test(tc, boardSet_toFalse_retrievesFalse);

  return tc;
}

Suite *suite_board(void) {
  Suite *s;

  s = suite_create("board");
  suite_add_tcase(s, tcase_board());

  return s;
}
