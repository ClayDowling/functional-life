#include "../board.h"
#include "../board_iterator.h"
#include "../neighbor_board.h"
#include <check.h>

int test_generator(int x, int y, ptrToGetter getter) { return 1; }

START_TEST(boardIterator_byDefault_appliesGeneratorToEachCell) {
  board_init();
  neighbor_init();
  board_iterator(board_at, neighbor_set, test_generator);
  for (int x = 0; x < X_MAX; ++x) {
    for (int y = 0; y < Y_MAX; ++y) {
      ck_assert_int_eq(1, neighbor_at(x, y));
    }
  }
}
END_TEST

TCase *tcase_board_iterator(void) {
  TCase *tc;
  tc = tcase_create("board-iterator");
  tcase_add_test(tc, boardIterator_byDefault_appliesGeneratorToEachCell);

  return tc;
}

Suite *suite_iterator(void) {
  Suite *s;

  s = suite_create("iterator");
  suite_add_tcase(s, tcase_board_iterator());

  return s;
}
