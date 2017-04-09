#include "../life_rules.h"
#include <check.h>

#define X 50
#define Y 27

struct neighbor_test_t {
  int neighbors;
  int life_result;
};

struct neighbor_test_t cases[] = {{0, 0}, {1, 0}, {2, 1}, {3, 1}, {4, 0},
                                  {5, 0}, {6, 0}, {7, 0}, {8, 0}};

int NEIGHBORS = 0;

int mock_getter(int x, int y) { return NEIGHBORS; }

START_TEST(life_givenNeighbors_returnsStatus) {
  NEIGHBORS = cases[_i].neighbors;
  ck_assert_int_eq(cases[_i].life_result, life(X, Y, mock_getter));
}
END_TEST

TCase *tcase_life_rules(void) {
  TCase *tc;

  tc = tcase_create("life-rules");
  tcase_add_loop_test(tc, life_givenNeighbors_returnsStatus, 0,
                      sizeof(cases) / sizeof(struct neighbor_test_t));

  return tc;
}

Suite *suite_life_rules(void) {
  Suite *s;

  s = suite_create("life-rules");
  suite_add_tcase(s, tcase_life_rules());

  return s;
}
