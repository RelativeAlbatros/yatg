#pragma once
#include <utility>

#define BLANK_STATE '.'

class Cell{
    // states: x - o - blank as ' '
    char _state;
    std::pair <int, int>_coordinates;
public:
    Cell(char state, int x, int y);
    Cell(void);
    void CopyCell(Cell &cell);
    char GetState(void) const;
    void SetState(char state);

    int  GetX(void) const;
    void SetX(int x);

    int  GetY(void) const;
    void SetY(int y);
};
