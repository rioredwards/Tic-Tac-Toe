#include "main.h"

int main()
{
    // int endState = 0;            // 1 = Win, 2 = Lose, 3 = Tie
    // int turnNum = 0;             // incriments every turn. should end at 9
    // int gameState = 0;
    // Tile gameBoard[9] = {a1, b1, c1, a2, b2, c2, a3, b3, c3}
    // char moveInput[2]            // Ex: a1
    // char xInput;                 // a,b,c
    // char yInput;                 // 1,2,3
    char endState = 'd'; // w = win, l = lose, d = draw
    std::string xyInput = "";
    int tileID = 0;
    Tile gameBoard[9];

    // Introduction to game
    PrintIntro();

    // Start playing?
    if (ContinueOrQuit() == false)
    {
        return 0;
    }

    // Start Game
    // Construct gameBoard
    for (int i = 0; i < 9; i++)
    {
        gameBoard[i].SetID(i + 1);
    }

    LogTiles(gameBoard);

    // Your Move: Prompt -> Input -> Convert -> Place Tile
    std::cout << "~ Your move:\n> ";
    getline(std::cin, xyInput);
    std::cout << "~ You Entered: " << xyInput << "\n";
    tileID = XYtoID(xyInput);
    PlaceTile(gameBoard, tileID, 'x');

    LogTiles(gameBoard);

    PrintGameBoard();

    // End Game
    PrintEndState(endState);

    return 0;
}

void PrintIntro()
{
    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~\n"
              << "~ Welcome to Tic-Tac-Toe!\n~\n"
              << "~ Instructions:\n"
              << "~ When prompted, input your move, then press enter.\n"
              << "~ (Ex: \"a1\" \"enter\")\n";
}

// Prompts user to continue playing game. Returns a bool.
bool ContinueOrQuit()
{
    bool result = false;
    std::string playInput;

    std::cout << "~ Continue? (\"y\" or \"n\")\n";
    do
    {
        std::cout << "> ";
        getline(std::cin, playInput);
        if (playInput[0] == 'n')
        {
            std::cout << "~ Quitting...\n~\n"
                      << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
            result = false;
            break;
        }
        else if (playInput[0] == 'y')
        {
            std::cout << "~ Continuing...\n~\n";
            result = true;
            break;
        }
        else
        {
            std::cout << "~ Invalid entry. Try again:\n";
        }
    } while ((playInput[0] != 'n') || (playInput[0] != 'y'));

    return result;
}

// TODO Add gameBoard parameter
void PrintGameBoard()
{
    std::cout << "____________________\n\n"
              << "    a   b   c\n\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << i + 1 << "   "
                  << "O"
                  << " | "
                  << "O"
                  << " | "
                  << "O"
                  << "\n";
        if (i < 2)
        {
            std::cout << "   ---+---+---\n";
        }
    }
    std::cout << "\n\n";
}

void PlaceTile(Tile gameBoard[], int tileID, char inputVal)
{
    gameBoard[tileID - 1].SetValue(inputVal);
}

// Convert XY (string) to tileID (int)
int XYtoID(std::string inputXY)
{
    int tileID;

    if (inputXY[0] == 'a')
    {
        if (inputXY[1] == '1')
        { // a1 = 1
            tileID = 1;
        }
        else if (inputXY[1] == '2')
        { // a2 = 4
            tileID = 4;
        }
        else
        { // a3 = 7
            tileID = 7;
        }
    }
    else if (inputXY[0] == 'b')
    {
        if (inputXY[1] == '1')
        { // b1 = 2
            tileID = 2;
        }
        else if (inputXY[1] == '2')
        { // b2 = 5
            tileID = 5;
        }
        else
        { // b3 = 8
            tileID = 8;
        }
    }
    else
    {
        if (inputXY[1] == '1')
        { // c1 = 3
            tileID = 3;
        }
        else if (inputXY[1] == '2')
        { // c2 = 6
            tileID = 6;
        }
        else
        { // c3 = 9
            tileID = 9;
        }
    }

    return tileID;
}

void PrintEndState(char endState)
{
    if (endState == 'w')
    {
        std::cout << "Congrats! You are a WINNER!\n";
    }
    else if (endState == 'l')
    {
        std::cout << "Uh oh! Looks like you're a LOSER!\n";
    }
    else
    {
        std::cout << "(Insert Neutral statement). It's a DRAW!\n";
    }
}

// LOGGING Print out tile id's and values
void LogTiles(Tile gameBoard[])
{
    for (int i = 0; i < 9; i++)
    {
        std::cout << gameBoard[i].GetID()
                  << gameBoard[i].GetValue() << "\n";
    }
}