#ifndef GAME_H
#define GAME_H

#include "board.h"

class Player {
  char player_token;
public:
  Player(char);
  void move(Board &board);
  char get_token();
};

class Game {
  bool game_over;
  int winner; // 1 or 2
public:
  Game();
  void run();
  int check_win(Board &board, Player player1, Player player2);
};

#endif // GAME_H
