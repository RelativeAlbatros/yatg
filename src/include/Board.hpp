#pragma once
#include "Cell.hpp"

#define LENGTH 3
#define WIDTH  3

class Board {
    Cell _board[LENGTH][WIDTH];
public:
    Board();
    Cell &GetCell(int x, int y);
    void DrawBoard() const;
    bool CheckTie() const;
    char CheckWin() const;
    char GetCellState(int x, int y) const;
    bool SetCellState(int x, int y, char state);
};
