#pragma once
#include <iostream>
#include <string>
#include "tile.h"

class GameBoard {
    private:
    // Private Data Members
    Tile tileArray[9];
    char endState = 'd'; // w = win, l = lose, d = draw

    // Private Helper Functions
    int XYtoID(std::string inputXY);
    void PlaceTile(int tileID, char inputVal);

    public:
    // Public Member Functions
    GameBoard();
    const void PrintGameBoard();
    const void PrintEndState();
    void UserMove();

    void LogTiles();

};