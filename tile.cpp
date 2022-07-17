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

// void Tile::PlaceTile(std::string inputXY, char inputVal) {
//     if (inputXY[0] == 'a') {
//         if (inputXY[1] == '1') {        // a1 = 1
//             id = 1;
//         }
//         else if (inputXY[1] == '2') {   // a2 = 4
//             id = 4;
//         }
//         else {                          // a3 = 7
//             id = 7;
//         }
//     }
//     else if (inputXY[0] == 'b') {
//         if (inputXY[1] == '1') {        // b1 = 2
//             id = 2;
//         }
//         else if (inputXY[1] == '2') {   // b2 = 5
//             id = 5;
//         }
//         else {                          // b3 = 8
//             id = 8;
//         }
//     }
//     else {
//         if (inputXY[1] == '1') {        // c1 = 3
//             id = 3;
//         }
//         else if (inputXY[1] == '2') {   // c2 = 6
//             id = 6;
//         }
//         else {                          // c3 = 9
//             id = 9;
//         }
//     }
//     value = inputVal;
// }
