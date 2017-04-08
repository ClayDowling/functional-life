#include "suites.h"
#include <check.h>

int main(int argc, char **argv) {
  SRunner *runner;
  int number_fails;

  runner = srunner_create(suite_board());
  srunner_add_suite(runner, suite_neighbor());
  srunner_add_suite(runner, suite_neighbor_board());
  srunner_add_suite(runner, suite_iterator());
  srunner_run_all(runner, CK_NORMAL);
  number_fails = srunner_ntests_failed(runner);
  srunner_free(runner);

  return number_fails;
}
