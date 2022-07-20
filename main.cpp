#include "main.h"

int main()
{
    GameBoard myBoard;

    // Intro Screen
    PrintNewScreen();
    std::cout << SPACES << "Welcome to Tic-Tac-Toe!\n";
    PrintNewlines(LINES - 4);
    sleep(2);

    // Start Game
    while (myBoard.GetMoveNum() <= 9)
    {
        // User Move Prompt
        PrintNewScreen();
        myBoard.PrintGameBoard();
        if (myBoard.GetMoveNum() == 1)
        {
            PrintNewlines(LINES - 11);
            std::cout << SPACES << "   Your move: \n"
                      << SPACES << "   Ex: \"a1\" \"enter\"\n"
                      << SPACES << "   > ";
        }
        else
        {
            PrintNewlines(LINES - 10);
            std::cout << SPACES << "    Your move:\n"
                      << SPACES << "    > ";
        }
        myBoard.UserMove();

        // User Move Print
        PrintNewScreen();
        myBoard.PrintGameBoard();
        PrintNewlines(LINES - 9);
        sleep(1);
        if (myBoard.CheckWinState() == 1)
        {
            break;
        }

        // Computer Move Prompt
        PrintNewScreen();
        myBoard.PrintGameBoard();
        PrintNewlines(LINES - 10);
        std::cout << SPACES << "   Computer move:\n";
        sleep(1);

        // Computer Move Print
        PrintNewScreen();
        myBoard.CompMove();
        myBoard.PrintGameBoard();
        PrintNewlines(LINES - 9);
        sleep(1);
        if (myBoard.CheckWinState() == 1)
        {
            break;
        }
    }

    // End Game
    PrintNewScreen();
    myBoard.PrintGameBoard();
    PrintNewlines(LINES - 10);
    std::cout << SPACES;
    PrintEndState(myBoard.GetEndState());
    sleep(2);

    return 0;
}

void PrintNewlines(int lines)
{
    for (int i = 0; i < lines; i++)
    {
        std::cout << "\n";
    }
}

void PrintNewScreen()
{
    for (int i = 0; i < 30; i++)
    {
        std::cout << "\n";
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
        std::cout << "Insert Neutral statement). It's a DRAW!\n";
    }
}