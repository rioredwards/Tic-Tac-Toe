#include "main.h"

int main()
{
    GameBoard myBoard;

    // Introduction
    PrintIntro();
    myBoard.PrintGameBoard();

    // Start playing?
    // if (ContinueOrQuit() == false)
    // {
    //     return 0;
    // }

    // Start Game
    while (myBoard.GetMoveNum() <= 9)
    {
        myBoard.UserMove();
        myBoard.CompMove();
    }

    // End Game
    myBoard.PrintEndState();

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

bool ContinueOrQuit()
{
    bool result = false;
    std::string playInput;

    std::cout << "~ Continue? (\"y\" or \"n\")\n";
    do
    {
        std::cout << "> ";
        getline(std::cin, playInput);
        if (playInput[0] == 'n')
        {
            std::cout << "~ Quitting...\n~\n"
                      << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
            result = false;
            break;
        }
        else if (playInput[0] == 'y')
        {
            std::cout << "~ Continuing...\n~\n";
            result = true;
            break;
        }
        else
        {
            std::cout << "~ Invalid entry. Try again:\n";
        }
    } while ((playInput[0] != 'n') || (playInput[0] != 'y'));

    return result;
}
