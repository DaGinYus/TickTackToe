#include "board.h"
#include <iostream>


Board::Board()
{
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      setCell(i,j,'.');
    }
  }
}

void Board::setCell(int row, int col, char state)
{
  if(row < 3 && row >= 0 && col < 3 && col >=0)ttt_board[row][col] = state;
}

char Board::getCell()
{
  return ttt_board[row][col];
}

bool Board::isValidChar(char input)
{
  if(input == 'X' || input == 'O' || input == '.') return true;
  return false;
}