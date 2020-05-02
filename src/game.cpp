#include <iostream>
#include <string>
#include <ctype.h>

#include "game.h"

void Game::run() {
  Player player1('X');
  Player player2('O');
  Player players[2] = {player1, player2};
  Board board();
  
  while (game_over == false) {
    for (int i = 0; i < 2; i++) {
      players[i].move(board);
      check_win(board);
    }
  }
}

void Game::check_win(Board &board) {
  std::string rows[3];
  std::string cols[3];
  std::string diag[2];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      rows[i] += board.getCell(i, j);
      cols[i] += board.getCell(j, i);
    }
    diag[0] += board.getCell(i, i);
    diag[1] += board.getCell(3 - i, 3 - j);
  }
}

Player::Player(char token) : player_token(token) { }
    
void Player::move(Board &board) {
  // asks player for move and updates board with player token
  std::string move;
  
  std::cout << "Enter move: ";
  std::cin >> move;
  if (move.size() == 2) {
    if (isalpha(move[0]) && isdigit(move[1])) {
      int row = tolower(move[0]) - 97; // converts letter row to index
      int col = move[1] - 1; // converts numerical column to index

      if (board.setCell(row, col, player_token)) {
	board.display();
      }
      else {
	std::cout << "Cell already occupied. Please pick another cell." << std::endl;
	move();
      }
    }
  }
  else {
    std::cout << "Expected input: one letter and one number. Please try again." << std::endl;
    move();
  }
}
  
