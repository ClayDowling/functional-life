#ifndef _BOARD_H_
#define _BOARD_H_

#include <stdbool.h>

#define X_MAX 100
#define Y_MAX 100

void board_init();
bool board_at(unsigned int x, unsigned int y);
void board_set(unsigned int x, unsigned int y, bool value);

#endif
