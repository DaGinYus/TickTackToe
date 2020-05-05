#ifndef Board_h
#define Board_h

class Board
{
public:
    Board();

    bool setCell(int row, int col, char state);

    char getCell(int row, int col);

    bool isValidChar(char input);

    void display();


private:
    char ttt_board[3][3];
};

#endif /* Board_h */
