#include "../board.h"
#include "../game.h"
#include <check.h>

START_TEST(gameGeneration_withTwoNeighbors_MutatesCellToBeLive) {
  board_set(0, 1, true);
  board_set(1, 0, true);
  game_generation();
  ck_assert_int_eq(1, board_at(0, 0));
  ck_assert_int_eq(1, board_at(1, 1));
  ck_assert_int_eq(0, board_at(1, 0));
  ck_assert_int_eq(0, board_at(0, 1));
}
END_TEST

TCase *tcase_generation(void) {
  TCase *tc;
  tc = tcase_create("game-generation");
  tcase_add_test(tc, gameGeneration_withTwoNeighbors_MutatesCellToBeLive);

  return tc;
}

Suite *suite_generation(void) {
  Suite *s;

  s = suite_create("game-generation");
  suite_add_tcase(s, tcase_generation());

  return s;
}
