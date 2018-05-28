#include <iostream>
#include "game.h"

GamePiece::GamePiece(int x, int y, char type) {
  m_coord [2] = {x, y};
  m_type = type;
}
