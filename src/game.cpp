#include <iostream>
#include <vector>
#include "game.h"

GamePiece::GamePiece(int x, int y, char type) {
  m_coord [2] = {x, y};
  m_type = type;
}

Game::Game() {
  // start with all blank spaces
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      board [i][j] = ' ';
    }
  }
}

void Game::refreshBoard() {
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      std::cout << '|' << board [i][j];
    }
    std::cout << std::endl;
  }
}
