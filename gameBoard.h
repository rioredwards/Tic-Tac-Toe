#pragma once
#include <iostream>
#include <string>
#include "tile.h"

class GameBoard
{
private:
    // Private Data Members
    Tile tileArray[9];
    int *emptyTiles;
    int moveNum;
    char endState; // w = win, l = lose, d = draw

    // Private Helper Functions
    int XYtoID(std::string inputXY);
    void PlaceTile(int tileID, char inputVal);
    // int *GetEmptyTiles();
    void RemoveEmptyTile(int tileID);

public:
    // Public Member Functions
    GameBoard();
    ~GameBoard();
    const void PrintGameBoard();
    const void PrintEndState();
    void UserMove();
    void CompMove();

    const int GetMoveNum() { return moveNum; }

    void LogTiles();
    void LogEmptyTiles();
};