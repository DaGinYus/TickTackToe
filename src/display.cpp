#include "display.h"

Board::Board() {
  startln = 2;
  startcol = 3;
  height = 5;
  width = 9;
}

void Board::create() {
  // ncurses options
  initscr();
  cbreak();
  noecho();

  // draw 3x3 box (width of each box is 9 and height is 5)
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      WINDOW * win = newwin(height, width, startln + (i * 4), startcol + (j * 8));
      refresh();
      board[i][j] = win;
      box(board[i][j], 0, 0);
      wrefresh(board[i][j]);
    }
  }
}

void Board::destroy() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      delwin(board[i][j]);
      refresh();
    }
  }
  getch();
  endwin();
}
