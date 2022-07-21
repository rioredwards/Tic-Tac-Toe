#pragma once
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h> // Enables sleep() fucntion
#endif
#include <iostream>
#include <string>
#include "tile.h"
#include "gameBoard.h"
#define SPACES "                   "
#define LINES 14

int main();
int XYtoID(std::string inputXY);
bool ContinueOrQuit();
void PrintNewlines(int lines);
void PrintEndState(char endState);
void PrintNewScreen();