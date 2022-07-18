#include "tile.h"

// Default Constructor
Tile::Tile() 
{
    id = 0;
    value = 'e';
}

// Overridden Constructor
Tile::Tile(int inputID)
{   
    id = inputID;
    value = 'e';
}

void Tile::PlaceTile(int inputID, char inputVal) {
    id = inputID;
    value = inputVal;
}

const char Tile::PrintValue() {
    if (value == 'e') {
        return ' ';
    }
    else {
        return value;
    }
}