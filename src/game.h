#ifndef GAME_H
#define GAME_H

#include <vector>

class GamePiece {
 private:
  int m_coord[2]; // stored in x,y array
  char m_type; // x or o

 public:
  GamePiece(int x, int y, char type);
};

class Game {
 private:
  char board[3][3];
  std::vector<GamePiece> moveList; // remembers moves

 public:
  Game(); // creates new board and starts game
  void refreshBoard(); // updates and draws to screen
};

#endif // GAME_H
