#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

#include "game.h"


Player::Player(char token) : player_token(token) { }

char Player::get_token() {
  return player_token;
}

void Player::move(Board &board) {
  // asks player for move and updates board with player token
  std::string move;
  
  std::cout << "Enter move: ";
  std::cin >> move;
  if (move.size() == 2) {
    int row = tolower(move[0]) - 97; // converts ascii
    int col = move[1] - 49;
    // restrict to A-C, 1-3
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
      if (!board.setCell(row, col, player_token)) {
	std::cout << "Cell already occupied. Please pick another cell.\n";
	Player::move(board);
      }
    }
    else {
      std::cout << "Expected input: one letter (a-c) and one number (1-3). Please try again.\n";
      Player::move(board);
    }
  }
  else {
    std::cout << "Expected input: one letter (a-c) and one number (1-3). Please try again.\n";
    Player::move(board);
  }
}

Game::Game() {
  game_over = false;
}

void Game::run() {
  int winner;
  Player player1('X');
  Player player2('O');
  Player players[2] = {player1, player2};
  Board board;
  
  while (game_over == false) {
    for (int i = 0; i < 2; i++) {
      board.display();
      players[i].move(board);
      winner = check_win(board, player1, player2);
      if (winner != 0) {
	game_over = true;
	board.display();
	break;
      }
    }
  }
  if (winner == 3) {
    std::cout << "Tie!\n";
  }
  else {
    std::cout << "Winner is player " << winner << "!\n";
  }
}

int Game::check_win(Board &board, Player player1, Player player2) {
  std::string board_str; // convert board to string form for searching
  std::string ldiag;
  std::string rdiag;
  for (int i = 0; i < 3; i++) {
    std::string row = ""; // reset for every row
    std::string col = "";
    for (int j = 0; j < 3; j++) {
      row += board.getCell(i, j);
      col += board.getCell(j, i);
    }
    ldiag += board.getCell(i, i);
    rdiag += board.getCell(2 - i, i);
    
    board_str += row;
    board_str += col;
  }
  board_str += ldiag;
  board_str += rdiag;

  std::string p1wincon(3, player1.get_token());
  std::string p2wincon(3, player2.get_token());
  for (int i = 0; i < board_str.length(); i += 3) {
    std::string s = board_str.substr(i, 3);
    if (s == p1wincon) {
      winner = 1;
      return winner;
    }
    else if (s == p2wincon) {
      winner = 2;
      return winner;
    }
  }
  if (board_str.find('.') == std::string::npos) {
    return 3; // return 3 in case of tie
  }
  return 0;
}
  
