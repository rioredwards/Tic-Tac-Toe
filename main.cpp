#include "main.h"

int main()
{
    char endState = 'd'; // w = win, l = lose, d = draw
    std::string xyInput = "";
    int tileID = 0;
    Tile gameBoard[9];

    // Introduction
    PrintIntro();
    PrintGameBoard(gameBoard);

    // Start playing?
    if (ContinueOrQuit() == false)
    {
        return 0;
    }

    // Construct gameBoard
    for (int i = 0; i < 9; i++)
    {
        gameBoard[i].SetID(i + 1);
    }

    // Start Game
    for (int turn = 1; turn <= 9; turn++)
    {
        // Your Move: Prompt -> Input -> Convert -> Place Tile
        std::cout << "~ Your move:\n> ";
        while (true) {
            getline(std::cin, xyInput);
            tileID = XYtoID(xyInput);
            if (tileID == -1) {
                std::cout << "Invalid Input. Please Try Again...\n";
                std::cout << "> ";
                continue;
            }
            if (gameBoard[tileID - 1].GetValue() != 'e') {
                std::cout << "Tile Not Available. Please Try Again...\n";
                std::cout << "> ";
            }
            else {
                break;
            }
        }
        PlaceTile(gameBoard, tileID, 'x');
        PrintGameBoard(gameBoard);
    }

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

void PrintGameBoard(Tile gameBoard[])
{
    std::cout << "____________________\n\n"
              << "    a   b   c\n\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << i + 1 << "   ";
        std::cout << gameBoard[i].PrintValue()
                  << " | "
                  << gameBoard[i + 3].PrintValue()
                  << " | "
                  << gameBoard[i + 6].PrintValue()
                  << "\n";
        if (i < 2)
        {
            std::cout << "   ---+---+---\n";
        }
    }
    std::cout << "\n\n";
}

void PlaceTile(Tile gameBoard[], int tileID, char inputVal)
{
    gameBoard[tileID - 1].SetValue(inputVal);
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
        else {
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
        else {
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
        else {
            tileID = -1;
        }
    }
    else
    {
        tileID = -1;
    }
    return tileID;
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

void LogTiles(Tile gameBoard[])
{
    for (int i = 0; i < 9; i++)
    {
        std::cout << gameBoard[i].GetID()
                  << gameBoard[i].GetValue() << "\n";
    }
}