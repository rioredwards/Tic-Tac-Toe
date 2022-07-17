#pragma once
#include <iostream>

class Tile
{
private:
    int id;     // 1-9
    char xPos;  // 'a', 'b', 'c'
    char yPos;  // '1', '2', '3'
    char value; // 'E' empty, 'O', 'X'

public:
    // Default Constructor
    Tile();

    // Overridden Constructor
    Tile(char xyPos[]);
    Tile::Tile(int inputID);

    // Setters
    void SetID(char inputID) { id = inputID; }
    void SetXPos(char inputX) { xPos = inputX; }
    void SetYPos(char inputY) { yPos = inputY; }
    void SetXYPos(char inputXY[]);
    void SetValue(char inVal);

    // Getters
    const int GetID() {return id;}
    const char GetXPos() {return xPos;}
    const char GetYPos() {return yPos;}
    const char GetValue() {return value;}

    // Setters
    // void Clear();
    // void AddCount() {count++;}
    // void AddInputLineCount() const {inputLineCount++;}
    // void AddLines();
    // void ToggleNewLineFlag() const {newLineFlag = !(newLineFlag);}
    // void DeleteCharAt(int delIndex);
    // void DeleteLineAt(int delIndex);

    // Getters
    // const char* GetString() const {return string;}
    // const int GetLines(int i) const {return lines[i];}
    // int GetNumLines() const { return numLines;}
    // int GetCount() const { return count;}
    // int GetLength() const { return length;}
    // int GetLineCount() const { return inputLineCount;}
    // bool GetNewLineFlag() const { return newLineFlag;}

    // friend std::ostream & operator << (std::ostream &, const word &);
    // friend std::istream & operator >> (std::istream &, word &);
};

// bool operator == (const word &, const word &);
// bool operator <  (const word &, const word &);
// bool operator >  (const word &, const word &);
// bool operator <= (const word &, const word &);
// bool operator >= (const word &, const word &);
// bool operator != (const word &, const word &);