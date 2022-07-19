#include "main.h"

int main()
{
    GameBoard myBoard;

    myBoard.ClearScreen(40);
    // Introduction
    PrintIntro();
    myBoard.PrintGameBoard();

    // // Start playing?
    // if (ContinueOrQuit() == false)
    // {
    //     return 0;
    // }

    // Start Game
    while (myBoard.GetMoveNum() <= 9)
    {
        myBoard.UserMove();
        if (myBoard.CheckWinState() == 1)
        {
            break;
        }
        myBoard.CompMove();
        if (myBoard.CheckWinState() == 1)
        {
            break;
        }
    }

    // End Game
    myBoard.PrintEndState();

    return 0;
}

void PrintIntro()
{
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~\n"
              << "~          Welcome to Tic-Tac-Toe!\n~\n";
    sleep(2);
    std::cout << "~          Instructions:\n"
              << "~          When prompted, input your move, then press enter.\n"
              << "~          (Ex: \"a1\" \"enter\")\n"
              << "~\n";
    sleep(3);
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
