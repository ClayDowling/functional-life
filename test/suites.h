#ifndef _SUITES_H_
#define _SUITES_H_

#include <check.h>

Suite *suite_neighbor(void);
Suite *suite_board(void);
Suite *suite_neighbor_board(void);
Suite *suite_iterator(void);
Suite *suite_life_rules(void);
Suite *suite_generation(void);
Suite *suite_integration(void);

#endif
