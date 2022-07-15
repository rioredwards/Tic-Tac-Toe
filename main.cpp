#include "main.h"

int main() {
    char playInput;              // "\n" = continue, "q" = quit

    // int endState = 0;            // 1 = Win, 2 = Lose, 3 = Tie
    // int turnNum = 0;             // incriments every turn. should end at 9
    // int gameState = 0;
    // tile gameBoard[9] = {a1, b1, c1, a2, b2, c2, a3, b3, c3}
    // char moveInput[2]            // Ex: a1
    // char xInput;                 // a,b,c
    // char yInput;                 // 1,2,3

    // PlayOrQuit()
    std::cout   << "Welcome to Tic-Tac-Toe!\n"
                << "Instructions: When prompted, input your move (Ex: \"a1\") and press \"enter\".\n"
                << "Continue? (\"y\" or \"n\")\n";
    std::cin >> playInput;
    

    PrintGameBoard();

    return 0;
}
// TODO Add gameBoard parameter
void PrintGameBoard() {
    std::cout   << "____________________\n\n"
                << "    a   b   c\n\n";
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << "   " << "O" << " | " << "O" << " | " << "O" << "\n";
        if (i < 2) {
            std::cout << "   ---+---+---\n";
        }
    }
    std::cout << "\n\n";
}