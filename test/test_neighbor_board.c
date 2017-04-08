#include "../neighbor_board.h"
#include <check.h>

START_TEST(neighborInit_byDefault_setsAllCellsToZero) {
  neighbor_init();
  for (int x = 0; x < X_MAX; ++x) {
    for (int y = 0; y < Y_MAX; ++y) {
      ck_assert_int_eq(0, neighbor_at(x, y));
    }
  }
}
END_TEST

START_TEST(neighborAt_afterneighborSet_returnsValueSet) {
  neighbor_init();
  neighbor_set(23, 23, 67);
  ck_assert_int_eq(67, neighbor_at(23, 23));
}
END_TEST

START_TEST(neighborAt_xLessThanZero_returns0) {
  neighbor_init();
  neighbor_set(-1, 0, 23);
  ck_assert_int_eq(0, neighbor_at(-1, 0));
}
END_TEST

START_TEST(neighborAt_xGreaterThanMax_returns0) {
  neighbor_init();
  neighbor_set(X_MAX + 1, 0, 67);
  ck_assert_int_eq(0, neighbor_at(X_MAX + 1, 0));
}
END_TEST

START_TEST(neighborAt_yLessThanZero_returns0) {
  neighbor_init();
  neighbor_set(0, -1, 23);
  ck_assert_int_eq(0, neighbor_at(0, -1));
}
END_TEST

START_TEST(neighborAt_yGreaterThanMax_returns0) {
  neighbor_init();
  neighbor_set(0, Y_MAX + 1, 67);
  ck_assert_int_eq(0, neighbor_at(0, Y_MAX + 1));
}
END_TEST

TCase *tcase_neighborboard(void) {
  TCase *tc;
  tc = tcase_create("neighbor-board");
  tcase_add_test(tc, neighborAt_afterneighborSet_returnsValueSet);
  tcase_add_test(tc, neighborInit_byDefault_setsAllCellsToZero);
  tcase_add_test(tc, neighborAt_xLessThanZero_returns0);
  tcase_add_test(tc, neighborAt_xGreaterThanMax_returns0);
  tcase_add_test(tc, neighborAt_yLessThanZero_returns0);
  tcase_add_test(tc, neighborAt_yGreaterThanMax_returns0);

  return tc;
}

Suite *suite_neighbor_board(void) {
  Suite *s;

  s = suite_create("neighbor-board");
  suite_add_tcase(s, tcase_neighborboard());

  return s;
}
