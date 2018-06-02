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
  std::vector<GamePiece> move_history;
  char board_logic[3][3];
  int player;
  bool game_end;

 public:
  Game();
  void startGame();
  void startTurn();
  void detectWin();
};

#endif // GAME_H
