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

static void game(int &x_score, int &o_score) {
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
        } catch(std::exception &e) {
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
            std::cout << "\nplayer x won!\n";
            x_score += 1;
            break;
        } else if (gamestate == 'o') {
            board.DrawBoard();
            std::cout << "\nplayer o won!\n";
            o_score += 1;
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
}

int main(int argc, char *argv[]) { 
    int o_score = 0;
    int x_score = 0;
    char play = 'y';
    do {
        game(x_score, o_score);
        std::cout << "x: " << x_score << " o: " << o_score << "\n";
        std::cout << "play again?\n> ";
        std::cin >> play;
        std::cout << std::endl;
    } while (play == 'y');
	return 0; 
} 
