#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h>

class Board {
 private:
  WINDOW * board[3][3];
  int width;
  int height;
  int startln;
  int startcol;

 public:
  Board();
  void create();
  int * move();
  void destroy();
};
   
 
WINDOW * createBoard();
int * selectBox();
void destroyBoard(WINDOW * win);

#endif // DISPLAY_H
