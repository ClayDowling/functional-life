#include "../board.h"
#include "../board_iterator.h"
#include "../neighbor.h"
#include "../neighbor_board.h"

#include <check.h>

START_TEST(neighbors_withBeacon_returnsTwoNeighborsForEmptyCells) {
  board_init();
  neighbor_init();
  board_set(5, 5, true);
  board_set(6, 6, true);

  board_iterator(board_at, neighbor_set, neighbors);

  ck_assert_int_eq(1, neighbor_at(5, 5));
  ck_assert_int_eq(1, neighbor_at(6, 6));
  ck_assert_int_eq(2, neighbor_at(5, 6));
  ck_assert_int_eq(2, neighbor_at(6, 5));
}
END_TEST

TCase *tcase_boardneighbor_integration(void) {
  TCase *tc;

  tc = tcase_create("board-neighbor-integration");
  tcase_add_test(tc, neighbors_withBeacon_returnsTwoNeighborsForEmptyCells);

  return tc;
}

Suite *suite_integration(void) {
  Suite *s;

  s = suite_create("integration");
  suite_add_tcase(s, tcase_boardneighbor_integration());

  return s;
}
