#include <iostream> 
#include <string>
#include <cstdlib>
#include "include/Board.hpp"

static void help_message(void) {
    std::cout << "> [x][y]\n"
              << "example: 12\n";
};

static int char_to_int(char c) {
    if (c < '1' || c > '3') {
        throw std::invalid_argument("char_to_int: char must be between 1 and 3");
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
        std::cout << "turn: " << turn << "\n";
        board.DrawBoard();
        std::cout << "\n> ";
        std::cin >> input;
        try {
            x = char_to_int(input[0]);
            y = char_to_int(input[1]);
        } catch(exception &e) {
            std::cout << "invalid argument.\n";
            continue;
        }
        if (x == 9 || y == 9)
            continue;
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
            std::cout << "\nplayer x won!\n"
            break;
        } else if (gamestate == 'o') {
            board.DrawBoard();
            std::cout << "\nplayer o won!\n"
            break;
        } else if (gamestate == 't') {
            board.DrawBoard();
            std::cout << "\nit's a tie.\n";
            break;
        }
        if (turn == 'x')
            turn = 'o';
        else if (turn == 'o')
            turn = 'x';
    }
	return 0; 
} 
