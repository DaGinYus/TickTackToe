#include "display.h"

WINDOW * createBoard() {
  initscr(); // initialize with one character at a time and echo suppression
  cbreak();
  noecho();
  keypad(stdscr, TRUE); // allows arrow key usage

  // start coordinates for screen
  
  WINDOW * win = newwin(LINES, COLS, 0, 0);
  refresh();
  
  // draw the board
  for (int i=0; i<5; i++) {
    if (i % 2 == 0) {
      for (int j=1; j<3; j++) {
	mvwaddch(win, i, (j * 4), '|');
      }
    }
    else if (i % 2 != 0) {
      for (int j=1; j<12; j++) {
	if (j % 4 == 0) {
	  mvwaddch(win, i, j, '+');
	}
	else if (j % 4 != 0) {
	  mvwaddch(win, i, j, '-');
	}
      }
    }
  }

  wrefresh(win);
  return win;
}

void destroyBoard(WINDOW * win) {
  wrefresh(win);
  getch();
  endwin();
}
