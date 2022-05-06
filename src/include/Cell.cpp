#include "Cell.hpp"

Cell::Cell(char state, int x, int y)
    : _state(state), _coordinates({x, y})
{}

Cell::Cell(void)
    : _state(BLANK_STATE), _coordinates({0, 0})
{}

Cell::CopyCell(Cell &cell) {
    cell.SetState(_state);
    cell.SetX(_coordinates.first);
    cell.SetY(_coordinates.second);
}

Cell::GetState(void) const { return _state; }
Cell::SetState(char state) { _state = state; }

Cell::GetX(void) const { return _coordinates.first; }
Cell::SetX(int x) { _coordinates.first = x;}

Cell::GetY(void) const { return _coordinates.second; }
Cell::SetY(int y) { _coordinates.second = y; }