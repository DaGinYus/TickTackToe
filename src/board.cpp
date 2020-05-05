#include "board.h"
#include <iostream>


Board::Board()
{
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      ttt_board[i][j] = '.';
    }
  }
}

bool Board::setCell(int row, int col, char state)
{
  if (isValidChar(state) && ttt_board[row][col] == '.')
  {
    if (row < 3 && row >= 0 && col < 3 && col >= 0) ttt_board[row][col] = state;
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
  if (input == 'X' || input == 'O') return true;
  return false;
}

void Board::display()
{
  std::cout << '\n';
  std::cout << "  1 2 3\n";
  for (int i = 0; i < 3; i++)
  {
    std::cout << (char)(i + 97) << " ";
    for (int j = 0; j < 3; j++)
    {
      std::cout << ttt_board[i][j] << " ";
    }
    std::cout << '\n';
  }
}
