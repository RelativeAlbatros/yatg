#pragma once
#include "Cell.hpp"

#define LENGTH 3
#define WIDTH  3

class Board {
    Cell _board[LENGTH][WIDTH];
public:
    Board() {
        for (int i=0; i<LENGTH; ++i) {
            for (int j=0; j<WIDTH; ++j) {
                _board[i][j].SetX(i);
                _board[i][j].SetY(j);
                SetCellState(i, j, BLANK_STATE);
            }
        }
    }
    Cell &GetCell(int x, int y) { 
        return _board[x][y];
    }
    void draw_board() {
        for (int i=0; i<LENGTH; ++i) {
            for (int j=0; j<WIDTH; ++j) {
                std::cout << GetCellState(j, i);
            }
            std::cout << std::endl;
        }
    }
    char GetCellState(int x, int y) { 
        return _board[x][y].GetState();
    }
    void SetCellState(int x, int y, char state) { 
        _board[x][y].SetState(state);
    }
};