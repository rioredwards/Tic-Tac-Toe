#pragma once
#include <iostream>
#include <string>
#include <ctime>    // Enables use of time() function
#include <unistd.h> // Enables sleep() fucntion
#include "main.h"
#include "tile.h"

class GameBoard
{
private:
    // Private Data Members
    Tile tileArray[9];
    int *emptyTiles;
    int emptyTilesSize;
    int moveNum;
    char endState; // w = win, l = lose, d = draw

    // Private Helper Functions
    int XYtoID(std::string inputXY);
    void PlaceTile(int tileID, char inputVal);
    int CompChooseTileID();
    void RemoveEmptyTile(int tileID);

public:
    // Public Member Functions
    GameBoard();
    ~GameBoard();
    void UserMove();
    void CompMove();
    int CheckWinState();

    void PrintNewlines(int lines);
    const void PrintGameBoard();

    const int GetMoveNum() { return moveNum; }
    const int GetEndState() { return endState; }
    const int GetEmptyTilesSize() { return emptyTilesSize; }

    void LogTiles();
    void LogEmptyTiles();
};