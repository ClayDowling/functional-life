#include "../board.h"
#include "../neighbor.h"
#include <check.h>

#define TEST_X 1
#define TEST_Y 1

#define LEFT_X 0
#define CENTER_X 1
#define RIGHT_X 2

#define UPPER_Y 0
#define CENTER_Y 1
#define LOWER_Y 2

START_TEST(neighbors_onEmptyBoard_returnsZero) {
  board_init();
  ck_assert_int_eq(0, neighbors(TEST_X, TEST_Y, board_at));
}
END_TEST

START_TEST(neighbors_upperLeft_returnsOne) {
  board_init();
  board_set(LEFT_X, UPPER_Y, true);
  ck_assert_int_eq(1, neighbors(TEST_X, TEST_Y, board_at));
}
END_TEST

START_TEST(neighbors_upperLeftAndLowerRight_returnsTwo) {
  board_init();
  board_set(LEFT_X, UPPER_Y, true);
  board_set(RIGHT_X, LOWER_Y, true);
  ck_assert_int_eq(2, neighbors(TEST_X, TEST_Y, board_at));
}
END_TEST

START_TEST(neighbors_allNeighbors_returnsEight) {
  board_init();
  board_set(LEFT_X, UPPER_Y, true);
  board_set(LEFT_X, CENTER_Y, true);
  board_set(LEFT_X, LOWER_Y, true);
  board_set(CENTER_X, UPPER_Y, true);
  board_set(CENTER_X, LOWER_Y, true);
  board_set(RIGHT_X, UPPER_Y, true);
  board_set(RIGHT_X, CENTER_Y, true);
  board_set(RIGHT_X, LOWER_Y, true);
  ck_assert_int_eq(8, neighbors(TEST_X, TEST_Y, board_at));
}
END_TEST

START_TEST(neighbors_allNeighborsPlusSelf_returnsEight) {
  board_init();
  board_set(LEFT_X, UPPER_Y, true);
  board_set(LEFT_X, CENTER_Y, true);
  board_set(LEFT_X, LOWER_Y, true);
  board_set(CENTER_X, UPPER_Y, true);
  board_set(CENTER_X, LOWER_Y, true);
  board_set(RIGHT_X, UPPER_Y, true);
  board_set(RIGHT_X, CENTER_Y, true);
  board_set(RIGHT_X, LOWER_Y, true);
  board_set(CENTER_X, CENTER_Y, true);
  ck_assert_int_eq(8, neighbors(TEST_X, TEST_Y, board_at));
}
END_TEST

START_TEST(neighbors_inBeacon_produceAlternateBeacon) {
  board_init();
  board_set(LEFT_X, UPPER_Y, true);
  board_set(CENTER_X, CENTER_Y, true);

  ck_assert_int_eq(1, neighbors(LEFT_X, UPPER_Y, board_at));
  ck_assert_int_eq(2, neighbors(CENTER_X, UPPER_Y, board_at));
  ck_assert_int_eq(2, neighbors(LEFT_X, CENTER_Y, board_at));
  ck_assert_int_eq(1, neighbors(CENTER_X, CENTER_Y, board_at));
}
END_TEST

TCase *tcase_neighbor(void) {
  TCase *tc;

  tc = tcase_create("neighbors");
  tcase_add_test(tc, neighbors_onEmptyBoard_returnsZero);
  tcase_add_test(tc, neighbors_upperLeft_returnsOne);
  tcase_add_test(tc, neighbors_upperLeftAndLowerRight_returnsTwo);
  tcase_add_test(tc, neighbors_allNeighbors_returnsEight);
  tcase_add_test(tc, neighbors_allNeighborsPlusSelf_returnsEight);
  tcase_add_test(tc, neighbors_inBeacon_produceAlternateBeacon);

  return tc;
}

Suite *suite_neighbor(void) {
  Suite *s;

  s = suite_create("neighbors");
  suite_add_tcase(s, tcase_neighbor());

  return s;
}
