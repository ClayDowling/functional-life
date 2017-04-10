#include "../board_iterator.h"
#include "../board.h"
#include "../neighbor.h"
#include "../neighbor_board.h"

#include <check.h>

START_TEST(neighbors_withBeacon_returnsTwoNeighborsForEmptyCells)
{
        board_init();
        neighbor_init();
        board_set(1, 0, true);
        board_set(0, 1, true);

        board_iterator(board_at, neighbor_set, neighbors);

        ck_assert_int_eq(2, board_at(0, 0));
        ck_assert_int_eq(2, board_at(1, 1));
        ck_assert_int_eq(0, board_at(0, 1));
        ck_assert_int_eq(0, board_at(1, 0));
}
END_TEST

TCase *tcase_boardneighbor_integration(void) {
        TCase *tc;

        tc = tcase_create("board-neighbor-integration");
        tcase_add_test(tc, neighbors_withBeacon_returnsTwoNeighborsForEmptyCells);

        return tc;
}

Suite *suite_integration(void)
{
        Suite *s;

        s = suite_create("integration");
        suite_add_tcase(s, tcase_boardneighbor_integration());

        return s;
}
