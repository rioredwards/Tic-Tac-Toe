#include "gameBoard.h"

// Default Constructor
GameBoard::GameBoard()
{
    emptyTiles = new int[9];
    for (int i = 0; i < 9; i++)
    {
        tileArray[i].SetID(i + 1);
        emptyTiles[i] = i + 1;
    }
    moveNum = 1;
    endState = 'd';
}

// Destructor
GameBoard::~GameBoard()
{
    if (emptyTiles != nullptr)
    {
        delete[] emptyTiles;
    }
}

const void GameBoard::PrintGameBoard()
{
    int pos = 0;
    std::cout << "____________________\n\n"
              << "    a   b   c\n\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << i + 1 << "   ";
        std::cout << tileArray[pos].PrintValue()
                  << " | "
                  << tileArray[pos + 1].PrintValue()
                  << " | "
                  << tileArray[pos + 2].PrintValue()
                  << "\n";
        if (i < 2)
        {
            std::cout << "   ---+---+---\n";
        }
        pos += 3;
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
        std::cout << tileArray[tileID - 1].GetValue() << "\n";
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
    PlaceTile(tileID, 'O');
    PrintGameBoard();
}

void GameBoard::CompMove()
{
    int tileID = 0;
    int *emptyTiles;

    std::cout << "Computer Move\n";
    // emptyTiles = GetEmptyTiles();
    // ChooseTile();

    PlaceTile(tileID, 'X');
    PrintGameBoard();
}

// int *GameBoard::GetEmptyTiles()
// {
// }

void GameBoard::RemoveEmptyTile(int tileID)
{
    LogEmptyTiles();
    int *newEmptyTiles;
    int numEmptyTiles = (9 - moveNum);
    newEmptyTiles = new int[numEmptyTiles - 1];
    for (int i = 0; i < numEmptyTiles - 1; i++)
    {
        if (i < (tileID - 1))
        {
            newEmptyTiles[i] = emptyTiles[i];
        }
        else
        {
            newEmptyTiles[i] = emptyTiles[i + 1];
        }
        delete[] emptyTiles;
        emptyTiles = newEmptyTiles;
        newEmptyTiles = nullptr;
    }
    LogEmptyTiles();
}

void GameBoard::PlaceTile(int tileID, char inputVal)
{
    RemoveEmptyTile(tileID);
    tileArray[tileID - 1].SetValue(inputVal);
    moveNum++;
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

void GameBoard::LogEmptyTiles()
{
    for (int i = 0; i < 9; i++)
    {
        std::cout << emptyTiles[i] << "\n";
    }
}