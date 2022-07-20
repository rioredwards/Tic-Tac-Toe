#pragma once
#include <iostream>
#include <string>
#include <unistd.h> // Enables sleep() fucntion
#include "tile.h"
#include "gameBoard.h"
#define SPACES "                   "
#define LINES 14

int main();
bool ContinueOrQuit();
void PrintNewlines(int lines);
void PrintEndState(char endState);
void PrintNewScreen();