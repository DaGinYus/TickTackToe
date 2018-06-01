#include "game.h"
#include "display.h"

int main(int argc, char *argv[]) {
  WINDOW * board = createBoard();
  destroyBoard(board);
  return 0;
}
