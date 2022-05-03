#pragma once
#include <utility>

#define BLANK_STATE '.'

class Cell{
    // states: x - o - blank as ' '
    char _state;
    std::pair <int, int>_coordinates;
public:
    Cell(char state, int x, int y)
        : _state(state), _coordinates({x, y})
    {}
    Cell(void)
        : _state(BLANK_STATE), _coordinates({0, 0})
    {}
    void CopyCell(Cell &cell) {
        cell.SetState(_state);
        cell.SetX(_coordinates.first);
        cell.SetY(_coordinates.second);
    }
    char GetState(void) const { return _state; }
    void SetState(char state) { _state = state; }

    int  GetX(void) const { return _coordinates.first; }
    void SetX(int x) { _coordinates.first = x;}

    int  GetY(void) const { return _coordinates.second; }
    void SetY(int y) { _coordinates.second = y; }
};
