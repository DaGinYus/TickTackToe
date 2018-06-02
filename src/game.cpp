#include <iostream>
#include "game.h"

GamePiece::GamePiece(int x, int y, char type) {
  m_coord[0] = x;
  m_coord[1] = y;
  m_type = type;
}

Game::Game() {
  m_game_end = false;
}

void Game::startGame() {
  /* the main game function. it randomly decides who goes first
     then also ends the game */
  
  // fills board with empty spaces
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      m_board[i][j] = ' ';
    }
  }
}

void Game::startTurn() {
  /* a recursive function that allows player to choose
     then modifies the game board. once the player finishes
     his turn, it calls itself for the next player */
}

void Game::detectWin() {
  /* detects if a player has won. called inside startTurn() function */
}
