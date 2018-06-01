#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h>

WINDOW * createBoard();
void destroyBoard(WINDOW * win);

#endif // DISPLAY_H
