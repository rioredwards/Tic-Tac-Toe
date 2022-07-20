#pragma once
#include <iostream>
#include <string>
#include <unistd.h> // Enables sleep() fucntion
#include "tile.h"
#include "gameBoard.h"

int main();
bool ContinueOrQuit();
void PrintNewlines(int lines);
void PrintNewScreen();