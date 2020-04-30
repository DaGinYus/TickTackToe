#ifndef "board.h"
#define "board.h"

class Board
{
public:
  Board();
  ~Board();

  int rows() const;
  int cols() const;
  
  void setCell(int row, int col, char state);

  bool isValidChar(char input);

  bool isEmpty(int row, int col);


private:
  char ttt_board[3][3];
  
}

#endif /* board_h */