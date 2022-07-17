#pragma once
#include <iostream>
#include <string>
#include "tile.h"

int main();
void PrintIntro();
void PrintGameBoard();
bool ContinueOrQuit();
int XYtoID(std::string inputXY);
void PlaceTile(Tile gameBoard[], int tileID, char inputVal);
void PrintEndState(char);
void LogTiles(Tile gameBoard[]);
