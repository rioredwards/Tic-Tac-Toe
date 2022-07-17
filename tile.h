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
    // void PlaceTile(std::string inputXY, char inputVal);

    // Getters
    const int GetID() {return id;}
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