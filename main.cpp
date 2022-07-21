#include "main.h"

int main()
{
    // Intro Screen
    PrintNewScreen();
    std::cout << SPACES << "Welcome to Tic-Tac-Toe!\n";
    PrintNewlines(LINES - 4);
    sleep(2);

    // Start Game
    while (true)
    {
        GameBoard myBoard;
        std::string userInput = "";
        int tileID = 0;

        while (myBoard.GetMoveNum() <= 9)
        {
            // User Move Prompt
            PrintNewScreen();
            myBoard.PrintGameBoard();
            if (myBoard.GetMoveNum() == 1)
            {
                PrintNewlines(LINES - 9);
                std::cout << SPACES << "   Your move: \n"
                          << SPACES << "   Ex: a1 enter\n"
                          << SPACES << "   > ";
            }
            else
            {
                PrintNewlines(LINES - 8);
                std::cout << SPACES << "    Your move:\n"
                          << SPACES << "    > ";
            }
            while (true)
            {
                getline(std::cin, userInput);
                tileID = XYtoID(userInput);
                if (tileID == -1)
                {
                    PrintNewScreen();
                    myBoard.PrintGameBoard();
                    PrintNewlines(LINES - 10);
                    std::cout << SPACES << "    Invalid Input\n"
                              << SPACES << "    Try Again...\n"
                              << SPACES << "    Ex: a1 enter\n"
                              << SPACES << "    > ";
                    continue;
                }
                if (myBoard.GetTileValueAt(tileID - 1) != 'e')
                {
                    PrintNewScreen();
                    myBoard.PrintGameBoard();
                    PrintNewlines(LINES - 10);
                    std::cout << SPACES << "    Tile Not Available\n"
                              << SPACES << "    Try Again...\n"
                              << SPACES << "    Ex: a1 enter\n"
                              << SPACES << "    > ";
                }
                else
                {
                    break;
                }
            }
            myBoard.UserMove(tileID);

            // User Move Print
            PrintNewScreen();
            myBoard.PrintGameBoard();
            PrintNewlines(LINES - 7);
            sleep(1);
            if (myBoard.CheckWinState() == 1)
            {
                break;
            }

            // Computer Move Prompt
            PrintNewScreen();
            myBoard.PrintGameBoard();
            PrintNewlines(LINES - 8);
            std::cout << SPACES << "   Computer move:\n";
            sleep(1);

            // Computer Move Print
            PrintNewScreen();
            myBoard.CompMove();
            myBoard.PrintGameBoard();
            PrintNewlines(LINES - 7);
            sleep(1);
            if (myBoard.CheckWinState() == 1)
            {
                break;
            }
        }

        // End Game
        for (int i = 0; i < 5; i++)
        {
            PrintNewScreen();
            std::cout << SPACES;
            PrintEndScreen(myBoard.GetEndState());
            PrintNewlines(LINES - 4);
            if (i == 0)
            {
                sleep(2);
            }
            usleep(100000);
            PrintNewScreen();
            usleep(100000);
        }

        // Play Again Screen
        while (true)
        {
            PrintNewScreen();
            std::cout << SPACES << "    Play Again?\n";
            PrintNewlines(LINES - 4);
            sleep(1);
            PrintNewScreen();
            std::cout << SPACES << "    Play Again?\n";
            PrintNewlines(LINES - 5);
            std::cout << SPACES << "    (y or n)\n"
                      << SPACES << "    > ";
            getline(std::cin, userInput);
            if (userInput[0] == 'n')
            {
                PrintNewScreen();
                std::cout << SPACES << "    Thanks For Playing!\n";
                PrintNewlines(LINES - 4);
                sleep(2);
                PrintNewScreen();
                return 0;
            }
            else if (userInput[0] == 'y')
            {
                PrintNewScreen();
                std::cout << SPACES << "    Continuing...\n";
                PrintNewlines(LINES - 4);
                sleep(2);
                break;
            }
            else
            {
                PrintNewScreen();
                std::cout << SPACES << "    Invalid Input\n"
                          << SPACES << "    Try Again...\n";
                PrintNewlines(LINES - 5);
                sleep(2);
            }
        }
    }

    return 0;
}

int XYtoID(std::string inputXY)
{
    int tileID;

    if (inputXY[0] == 'a')
    {
        if (inputXY[1] == '1')
        { // a1 = 1
            tileID = 1;
        }
        else if (inputXY[1] == '2')
        { // a2 = 4
            tileID = 4;
        }
        else if (inputXY[1] == '3')
        { // a3 = 7
            tileID = 7;
        }
        else
        {
            tileID = -1;
        }
    }
    else if (inputXY[0] == 'b')
    {
        if (inputXY[1] == '1')
        { // b1 = 2
            tileID = 2;
        }
        else if (inputXY[1] == '2')
        { // b2 = 5
            tileID = 5;
        }
        else if (inputXY[1] == '3')
        { // b3 = 8
            tileID = 8;
        }
        else
        {
            tileID = -1;
        }
    }
    else if (inputXY[0] == 'c')
    {
        if (inputXY[1] == '1')
        { // c1 = 3
            tileID = 3;
        }
        else if (inputXY[1] == '2')
        { // c2 = 6
            tileID = 6;
        }
        else if (inputXY[1] == '3')
        { // c3 = 9
            tileID = 9;
        }
        else
        {
            tileID = -1;
        }
    }
    else
    {
        tileID = -1;
    }
    return tileID;
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

void PrintEndScreen(char endState)
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
        std::cout << "Neutral statement! It's a DRAW!\n";
    }
}