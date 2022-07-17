#include "main.h"

int main()
{
    // int endState = 0;            // 1 = Win, 2 = Lose, 3 = Tie
    // int turnNum = 0;             // incriments every turn. should end at 9
    // int gameState = 0;
    // Tile gameBoard[9] = {a1, b1, c1, a2, b2, c2, a3, b3, c3}
    // char moveInput[2]            // Ex: a1
    // char xInput;                 // a,b,c
    // char yInput;                 // 1,2,3
    char endState = 'd';            // w = win, l = lose, d = draw
    char inX = '1';
    char inY = 'a';
    Tile gameBoard[9];

    // Introduction to game
    PrintIntro();

    // Start playing?
    if (ContinueOrQuit() == false)
    {
        return 0;
    }

    // Start Game
    // Construct gameBoard
    for (int i = 0; i < 9; i++)
    {
        gameBoard[i].SetXPos(inX++);
        gameBoard[i].SetYPos(inY++);
    }

    // for (int i = 0; i < 9; i++)
    // {
    //     std::cout << gameBoard[i].GetXPos()
    //               << gameBoard[i].GetYPos() << " "
    //               << gameBoard[i].GetValue() << "\n";
    // }

    PrintGameBoard();

    // End Game
    PrintEndState(endState);

    return 0;
}

void PrintIntro()
{
    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~\n"
              << "~ Welcome to Tic-Tac-Toe!\n~\n"
              << "~ Instructions:\n"
              << "~ When prompted, input your move, then press enter.\n"
              << "~ (Ex: \"a1\" \"enter\")\n";
}

// Prompts user to continue playing game. Returns a bool.
bool ContinueOrQuit()
{
    bool result = false;
    char playInput;

    std::cout << "~ Continue? (\"y\" or \"n\")\n";
    do
    {
        std::cout << "> ";
        std::cin >> playInput;
        if (playInput == 'n')
        {
            std::cout << "~ Quitting...\n~\n"
                      << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
            result = false;
            break;
        }
        else if (playInput == 'y')
        {
            std::cout << "~ Continuing...\n~\n";
            result = true;
            break;
        }
        else
        {
            std::cout << "~ Invalid entry. Try again:\n";
        }
    } while ((playInput != 'n') || (playInput != 'y'));

    return result;
}

// TODO Add gameBoard parameter
void PrintGameBoard()
{
    std::cout << "____________________\n\n"
              << "    a   b   c\n\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << i + 1 << "   "
                  << "O"
                  << " | "
                  << "O"
                  << " | "
                  << "O"
                  << "\n";
        if (i < 2)
        {
            std::cout << "   ---+---+---\n";
        }
    }
    std::cout << "\n\n";
}

void PrintEndState(char endState)
{
    if (endState == 'w')
    {
        std::cout << "Congrats! You are a WINNER!\n";
    }
    else if (endState == 'l')
    {
        std::cout << "Uh oh! Looks like you're a LOSER!\n";
    }
    else
    {
        std::cout << "(Insert Neutral statement). It's a DRAW!\n";
    }
}