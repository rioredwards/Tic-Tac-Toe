#pragma once
#include <iostream>
#include <string>

class Tile
{
private:
    int id;     // 1-9
    char value; // 'E' empty, 'O', 'X'

public:
    // Default Constructor
    Tile();

    // Overridden Constructor
    Tile(int inputID);
    Tile(std::string xyPos);

    // Setters
    void SetID(int inputID) { id = inputID; }
    void SetValue(char inputVal) { value = inputVal; }
    void PlaceTile(int inputID, char inputVal);

    // Getters
    const int GetID() {return id;}
    const char GetValue() {return value;}
    const char PrintValue();                    // Prints whitespace if value == "e"

};
