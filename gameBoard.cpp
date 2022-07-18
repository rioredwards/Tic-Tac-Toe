#include "gameBoard.h"

// Default Constructor
GameBoard::GameBoard()
{
    for (int i = 0; i < 9; i++)
    {
        tileArray[i].SetID(i + 1);
    }
}

const void GameBoard::PrintGameBoard()
{
    std::cout << "____________________\n\n"
              << "    a   b   c\n\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << i + 1 << "   ";
        std::cout << tileArray[i].PrintValue()
                  << " | "
                  << tileArray[i + 3].PrintValue()
                  << " | "
                  << tileArray[i + 6].PrintValue()
                  << "\n";
        if (i < 2)
        {
            std::cout << "   ---+---+---\n";
        }
    }
    std::cout << "\n\n";
}

// Your Move: Prompt -> Input -> Convert -> Place Tile
void GameBoard::UserMove()
{
    std::string xyInput = "";
    std::cout << "~ Your move:\n> ";
    int tileID = 0;
    while (true)
    {
        getline(std::cin, xyInput);
        tileID = XYtoID(xyInput);
        if (tileID == -1)
        {
            std::cout << "Invalid Input. Please Try Again...\n";
            std::cout << "> ";
            continue;
        }
        if (tileArray[tileID - 1].GetValue() != 'e')
        {
            std::cout << "Tile Not Available. Please Try Again...\n";
            std::cout << "> ";
        }
        else
        {
            break;
        }
    }
    PlaceTile(tileID, 'x');
    PrintGameBoard();
}

void GameBoard::PlaceTile(int tileID, char inputVal)
{
    tileArray[tileID - 1].SetValue(inputVal);
}

int GameBoard::XYtoID(std::string inputXY)
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

const void GameBoard::PrintEndState()
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

void GameBoard::LogTiles()
{
    for (int i = 0; i < 9; i++)
    {
        std::cout << tileArray[i].GetID()
                  << tileArray[i].GetValue() << "\n";
    }
}