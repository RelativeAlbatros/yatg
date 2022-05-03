#include <iostream> 
#include <string>
#include <cstdlib>
#include "Board.hpp"

void help_message(void) {
    std::cout << "> [x][y]" << std::endl
              << "example: 12" << std::endl;
};

int char_to_int(char c) {
    if (c < '1' || c > '3') {
        std::cerr << c << " is not an int" << std::endl;
        throw std::invalid_argument("invalid conversion of char");
    }
    return (c - '0');
}

int main(int argc, char *argv[]) { 
    char c;
    char turn = 'x';
    int x, y;
    std::string input;
    Board board;
    while (true) {
        std::cout << "turn: " << turn << std::endl;
        board.DrawBoard();
        std::cout << std::endl << "> ";
        std::cin >> input;
        x = char_to_int(input[0]);
        y = char_to_int(input[1]);
        if (input == "quit" || input == "exit") {
            break;
        } else if (input == "help") {
            help_message();
            continue;
        }
        if (board.SetCellState(x-1, y-1, turn) == 1) {
            continue;
        }
        char gamestate = board.CheckWin();
        if (gamestate == 'x') {
            board.DrawBoard();
            std::cout << "player x won!" << std::endl;
            break;
        } else if (gamestate == 'o') {
            board.DrawBoard();
            std::cout << "player o won!" << std::endl;
            break;
        } else if (gamestate == 't') {
            board.DrawBoard();
            std::cout << "it's a tie." << std::endl;
            break;
        }
        if (turn == 'x')
            turn = 'o';
        else if (turn == 'o')
            turn = 'x';
    }
	return 0; 
} 
