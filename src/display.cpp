#include "display.h"

/* WINDOW * createBoard() {
  initscr(); // initialize with one character at a time and echo suppression
  cbreak();
  noecho();
  keypad(stdscr, TRUE); // allows arrow key usage

  // start coordinates for screen
  startln = 2;
  startcol = 3;
  height = 13;
  width = 25;

  
  WINDOW * board = newwin(height, width, startln, startcol);
  refresh();

  box(board, 0, 0); // border

  wchar_t ch = 0x2502;
    
  // draw the board
  wmove(board, 1, 8);
  wvline(board, ch, 11);
  
  wrefresh(board);
  return board;
}

int * selectBox() {
  return 0;
}
  

void destroyBoard(WINDOW * board) {
  wrefresh(board);
  getch();
  endwin();
}
*/

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
