#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game {
  bool game_over = false;
public:
  void run();
  void check_win();
}

class Player {
  char player_token;
public:
  Player(char);
  void move(Game, Board);
};

#endif // GAME_H
