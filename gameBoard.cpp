#include "gameBoard.h"

// Default Constructor
GameBoard::GameBoard()
{
    std::srand(std::time(0));
    emptyTilesSize = 9;
    emptyTiles = new int[emptyTilesSize];
    for (int i = 0; i < 9; i++)
    {
        tileArray[i].SetID(i + 1);
        emptyTiles[i] = i + 1;
    }
    moveNum = 1;
    endState = 'd';
}

// Destructor
GameBoard::~GameBoard()
{
    if (emptyTiles != nullptr)
    {
        delete[] emptyTiles;
    }
}

const void GameBoard::PrintGameBoard()
{
    int pos = 0;
    std::cout << SPACES <<  "      a   b   c\n\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << SPACES << "  " << i + 1 << "   ";
        std::cout << tileArray[pos].PrintValue()
                  << " | "
                  << tileArray[pos + 1].PrintValue()
                  << " | "
                  << tileArray[pos + 2].PrintValue()
                  << "\n";
        if (i < 2)
        {
            std::cout << SPACES << "     ---+---+---\n";
        }
        pos += 3;
    }
}

// Your Move: Prompt -> Input -> Convert -> Place Tile
void GameBoard::UserMove(int tileID)
{
    PlaceTile(tileID, 'O');
}

void GameBoard::CompMove()
{
    if (GetEmptyTilesSize() != 0)
    {
        int tileID = 0;
        tileID = CompChooseTileID();
        PlaceTile(tileID, 'X');
    }
}

int GameBoard::CompChooseTileID()
{
    srand(time(0));
    int randNum = rand();
    int randIdx = 0;
    int resultID = 0;

    randIdx = ((randNum / 2) % (emptyTilesSize - 1));
    resultID = emptyTiles[randIdx];

    return resultID;
}

void GameBoard::RemoveEmptyTile(int tileID)
{
    int *newEmptyTiles;
    int delIdx = 0;

    // Search Loop
    while (tileID != emptyTiles[delIdx])
    {
        delIdx++;
    }

    // Remove Loop
    newEmptyTiles = new int[emptyTilesSize - 1];
    for (int i = 0; i < emptyTilesSize - 1; i++)
    {
        if (i < delIdx)
        {
            newEmptyTiles[i] = emptyTiles[i];
        }
        else
        {
            newEmptyTiles[i] = emptyTiles[i + 1];
        }
    }
    delete[] emptyTiles;
    emptyTiles = newEmptyTiles;
    newEmptyTiles = nullptr;
    emptyTilesSize--;
}

void GameBoard::PlaceTile(int tileID, char inputVal)
{
    RemoveEmptyTile(tileID);
    tileArray[tileID - 1].SetValue(inputVal);
    moveNum++;
}

// Returns 0 if no win and 1 if win
int GameBoard::CheckWinState()
{
    bool go = true;
    if (moveNum >= 6)
    {
        // 1's, 2's and 3's in a Row
        for (int i = 0; i < 9; i += 3)
        {
            if (go == false)
            {
                break;
            }
            if (tileArray[i].GetValue() == tileArray[i + 1].GetValue() && tileArray[i + 1].GetValue() == tileArray[i + 2].GetValue())
            {
                if (tileArray[i].GetValue() == 'e')
                {
                    // Do Nothing
                }
                else if (tileArray[i].GetValue() == 'O')
                {
                    endState = 'w';
                    go = false;
                }
                else if (tileArray[i].GetValue() == 'X')
                {
                    endState = 'l';
                    go = false;
                }
            }
        }
        // a's, b's and c's in a Row
        for (int i = 0; i < 3; i++)
        {
            if (go == false)
            {
                break;
            }
            if (tileArray[i].GetValue() == tileArray[i + 3].GetValue() && tileArray[i + 3].GetValue() == tileArray[i + 6].GetValue())
            {
                if (tileArray[i].GetValue() == 'e')
                {
                    // Do Nothing
                }
                else if (tileArray[i].GetValue() == 'O')
                {
                    endState = 'w';
                    go = false;
                }
                else if (tileArray[i].GetValue() == 'X')
                {
                    endState = 'l';
                    go = false;
                }
            }
        }
        if (go != false)
        {
            // diagonal 1 in a Row
            if (tileArray[0].GetValue() == tileArray[4].GetValue() && tileArray[4].GetValue() == tileArray[8].GetValue())
            {
                if (tileArray[0].GetValue() == 'e')
                {
                    // Do Nothing
                }
                else if (tileArray[0].GetValue() == 'O')
                {
                    endState = 'w';
                }
                else if (tileArray[0].GetValue() == 'X')
                {
                    endState = 'l';
                }
            }
            // diagonal 2 in a Row
            if (tileArray[2].GetValue() == tileArray[4].GetValue() && tileArray[4].GetValue() == tileArray[6].GetValue())
            {
                if (tileArray[2].GetValue() == 'e')
                {
                    // Do Nothing
                }
                else if (tileArray[2].GetValue() == 'O')
                {
                    endState = 'w';
                }
                else if (tileArray[2].GetValue() == 'X')
                {
                    endState = 'l';
                }
            }
        }
    }
    if (endState != 'd')
    {
        return 1;
    }
    else
    {
        return 0;
    }

    // 3 in a row combinations:
    // 1's: 1, 2, 3
    // 2's: 4, 5, 6
    // 3's: 7, 8, 9

    // a's: 1, 4, 7
    // b's: 2, 5, 8
    // c's: 3, 6, 9

    // diagonal 1: 1, 5, 9
    // diagonal 2: 3, 5, 7
}

void GameBoard::PrintNewlines(int lines)
{
    for (int i = 0; i < lines; i++)
    {
        std::cout << "~\n";
    }
}

void GameBoard::LogTiles()
{
    std::cout << "Logging Tiles: \n";
    for (int i = 0; i < 9; i++)
    {
        std::cout << tileArray[i].GetID()
                  << tileArray[i].GetValue() << "\n";
    }
}

void GameBoard::LogEmptyTiles()
{
    std::cout << "Logging Empty Tiles: \n";
    for (int i = 0; i < emptyTilesSize; i++)
    {
        std::cout << emptyTiles[i] << "\n";
    }
}