#include "tile.h"

// Default Constructor
Tile::Tile() 
{
    id = 0;
    xPos = 0;
    yPos = 0;
    value = 'e';
}

// Overridden Constructor
Tile::Tile(int inputID)
{   
    id = inputID;
    xPos = 0;
    yPos = 0;
    value = 'e';
}

// Overridden Constructor
Tile::Tile(char xyPos[])
{   
    id = 0;
    xPos = xyPos[0];
    yPos = xyPos[0];
    value = 'e';
}

void Tile::SetXYPos(char inputXY[])
{
        xPos = inputXY[0];
        yPos = inputXY[1];
}

void Tile::SetValue(char inVal)
{
    value = inVal;
}
