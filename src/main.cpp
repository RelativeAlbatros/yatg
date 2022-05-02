#include <iostream> 
#include "Board.hpp"

void help_message(void) {
    std::cout << "> [type][x][y]" << std::endl
              << "example: x12" << std::endl;
};

int main(int argc, char *argv[]) { 
    Board b;
    b.SetCellState(1, 2, 'x');
    b.SetCellState(1, 1, 'o');
    b.draw_board();
	return 0; 
} 