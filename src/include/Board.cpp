#include <iostream>

Board::Board()  {
    for (int i=0; i<LENGTH; ++i) {
        for (int j=0; j<WIDTH; ++j) {
            _board[i][j].SetX(i);
            _board[i][j].SetY(j);
            SetCellState(i, j, BLANK_STATE);
        }
    }
}

Board::GetCell(int x, int y) { 
        return _board[x][y];
}

Board::DrawBoard() {
    for (int i=0; i<LENGTH; ++i) {
        std::cout << "\n\t";
        for (int j=0; j<WIDTH; ++j) {
            if (j == 1)
                std::cout << " | " << GetCellState(j, i) << " | ";
            else
                std::cout << GetCellState(j, i);
        }
    }
}

// return false if there's still a blank cell
Board::CheckTie() {
    for (int i=0; i<LENGTH; ++i) {
        for (int j=0; j<WIDTH; ++j) {
            if (GetCellState(i, j) == BLANK_STATE)
                return false;
        }
    }
    return true;
}

Board::CheckWin() {
    // Horizontal from top left
    if (GetCellState(0,0) == GetCellState(1,0) && GetCellState(0,0) == GetCellState(2,0)) {
        return GetCellState(0,0);
    }
    // Horizontal from middle left
    else if (GetCellState(0,1) == GetCellState(1,1) && GetCellState(0,1) == GetCellState(2,1)) {
        return GetCellState(0,1);
    }
    // Horizontal from bottom left
    else if (GetCellState(0,2) == GetCellState(1,2) && GetCellState(0,2) == GetCellState(2,2)) {
        return GetCellState(0,2);
    }
    // Vertical from top left
    else if (GetCellState(0,0) == GetCellState(0,1) && GetCellState(0,0) == GetCellState(0,2)) {
        return GetCellState(0,0);
    }
    // Vertical from upper middle
    else if (GetCellState(1,0) == GetCellState(1,1) && GetCellState(1,0) == GetCellState(1,2)) {
        return GetCellState(1,0);
    }
    // Vertical from top right
    else if (GetCellState(2,0) == GetCellState(2,1) && GetCellState(2,0) == GetCellState(2,2)) {
        return GetCellState(2,0);
    }
    // diagonal from top left
    else if (GetCellState(0,0) == GetCellState(1,1) && GetCellState(0,0) == GetCellState(2,2)) {
        return GetCellState(0,0);
    }
    // diagonal from top right
    else if (GetCellState(2,0) == GetCellState(1,1) && GetCellState(2,0) == GetCellState(0,2)) {
        return GetCellState(2,0);
    }
    else if (CheckTie()){
        return 't';
    }
    else {
        return 'n';
    }
}
    
Board::GetCellState(int x, int y) const { 
    return _board[x][y].GetState();
}

Board::SetCellState(int x, int y, char state) { 
    if (x < 0 || x > 3 || y < 0 || y > 3) {
        std::cerr << "x and y coordinates must be between 0 and 2";
        return 1;
    } else if (GetCellState(x, y) != BLANK_STATE) {
        std::cerr << "Invalid Input: Cell is not blank\n";
        return 1;
    }
    _board[x][y].SetState(state);
    return 0;
}