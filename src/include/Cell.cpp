#include "Cell.hpp"

Cell::Cell(char state, int x, int y)
    : _state(state), _coordinates({x, y})
{}

Cell::Cell(void)
    : _state(BLANK_STATE), _coordinates({0, 0})
{}

void Cell::CopyCell(Cell &cell) {
    cell.SetState(_state);
    cell.SetX(_coordinates.first);
    cell.SetY(_coordinates.second);
}

char Cell::GetState(void) const { return _state; }
void Cell::SetState(char state) { _state = state; }

int Cell::GetX(void) const { return _coordinates.first; }
void Cell::SetX(int x) { _coordinates.first = x;}

int Cell::GetY(void) const { return _coordinates.second; }
void Cell::SetY(int y) { _coordinates.second = y; }