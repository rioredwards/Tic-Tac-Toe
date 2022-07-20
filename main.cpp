#include "main.h"

int main()
{
    GameBoard myBoard;

    // Intro Screen
    PrintNewScreen();
    std::cout << "~               Welcome to Tic-Tac-Toe!\n";
    PrintNewlines(12);
    sleep(2);
    
    // Instructions Screen
    PrintNewScreen();
    std::cout << "~               Instructions:\n"
              << "~               When prompted, input your move, then press enter.\n"
              << "~               (Ex: \"a1\" \"enter\")\n";
    PrintNewlines(10);
    sleep(3);

    // Start Game
    while (myBoard.GetMoveNum() <= 9)
    {
        // User Move Prompt
        PrintNewScreen();
        myBoard.PrintGameBoard();
        PrintNewlines(5);
        std::cout << "~                  Your move:\n"
                  << "~                  > ";
        myBoard.UserMove();
        // User Move Print
        PrintNewScreen();
        myBoard.PrintGameBoard();
        PrintNewlines(6);
        sleep(1);
        if (myBoard.CheckWinState() == 1)
        {
            break;
        }
        // Computer Move Prompt
        PrintNewScreen();
        myBoard.PrintGameBoard();
        PrintNewlines(5);
        std::cout << "~                  Computer move:\n";
        sleep(1);
        // Computer Move Print
        PrintNewScreen();
        myBoard.CompMove();
        myBoard.PrintGameBoard();
        PrintNewlines(6);
        sleep(1);
        if (myBoard.CheckWinState() == 1)
        {
            break;
        }
    }

    // End Game
    myBoard.PrintEndState();

    return 0;
}

void PrintNewlines(int lines)
{
    for (int i = 0; i < lines; i++)
    {
        std::cout << "~\n";
    }
}

void PrintNewScreen()
{
    for (int i = 0; i < 30; i++)
    {
        std::cout << "~\n";
    }
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
