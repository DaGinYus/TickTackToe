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
  keypad(stdscr, TRUE);

  // draw the board
  WINDOW * temp_board = newwin(13, 25, startln, startcol);
  refresh();
  box(temp_board, 0, 0);
  
  for (int a = 1; a < 3; a++) {
    mvwvline(temp_board, 1, a * 8, ACS_VLINE, 11);
    mvwhline(temp_board, a * 4, 1, ACS_HLINE, 23);
  }
  mvwaddch(temp_board, 4, 16, ACS_HLINE);

  wrefresh(temp_board);
  delwin(temp_board);

  // make 9 windows so assigning x or o is easier
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      WINDOW * win = newwin(height, width, startln + (i * 4), startcol + (j * 8));
      refresh();
      board[i][j] = win;
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
