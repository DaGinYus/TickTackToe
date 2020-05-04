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

bool Board::setCell(int row, int col, char state)
{
  if(isValidChar(state) && (isEmpty(row, col) || ttt_board[row][col] == '.'))
  {
    if(row < 3 && row >= 0 && col < 3 && col >=0)ttt_board[row][col] = state;
    return true;
  }
  return false;
}

char Board::getCell(int row, int col)
{
  return ttt_board[row][col];
}

bool Board::isValidChar(char input)
{
  if(input == 'X' || input == 'O' || input == '.') return true;
  return false;
}

bool Board::isEmpty(int row, int col)
{
  if(ttt_board[row][col] == '.') return true;
  return false;
}

void Board::display()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << ttt_board[i][j];
        }
        std::cout << std::endl;
    }
}