#ifndef Board_h
#define Board_h

class Board
{
public:
    Board();

    void setCell(int row, int col, char state);

    char getCell(int row, int col);

    bool isValidChar(char input);

    bool isEmpty(int row, int col);

    void display();


private:
    char ttt_board[3][3];

};

#endif /* Board_h */