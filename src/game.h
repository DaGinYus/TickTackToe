#ifndef GAME_H
#define GAME_H

#include <vector>

class GamePiece {
 private:
  int m_coord [2]; // stored in x,y array
  char m_type;

 public:
  GamePiece(int x, int y, char type);
};

class Game {
 private:
  std::vector<GamePiece> moveList;

 public:
  Game();
};

#endif // GAME_H
