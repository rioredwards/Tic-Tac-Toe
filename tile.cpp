#include "tile.h"

// Default Constructor
tile::tile() 
{
    xPos = 0;
    yPos = 0;
    value = 'e';
}

// Overridden Constructor
tile::tile(char xyPos[])
{   
    xPos = xyPos[0];
    yPos = xyPos[0];
    value = 'e';
}
