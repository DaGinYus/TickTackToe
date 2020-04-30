#include <iostream>
#include <string>
#include <ctype.h>

#include "game.h"


void Player::move() {
  // asks player for move and updates board with player token
  std::string move;
  
  std::cout << "Enter move: ";
  std::cin >> move;
  if (move.size() == 2) {
    if (isalpha(move[0]) && isdigit(move[1])) {
	// code for updating board goes here
      break;
    }
  }
  else {
    std::cout << "Expected input: one letter and one number" << std::endl;
  }
}
  
