/*
    Author: Joey Cluett

    Date Created: 10-18-2016

    Date Last Modified: 11-15-2016

*/

#include <iostream>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__) // Windows
    #include <conio.h>
#else                                                                             // Linux/Unix
    /* user-defined library with functions that have the
    same interface but are defined differently */
    #include "conio.h"
#endif // defined

//#define BOARDWIDTH  10
//#define BOARDHEIGHT 30

#include "GameBoard.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    /* Setup and configuration */
    GameBoard gb('*');

    gb.setBlockType(GameBoard::BlockType::EMPTY,   ' ');
    gb.setBlockType(GameBoard::BlockType::OVERLAP, ' ');
    gb.setBlockType(GameBoard::BlockType::PLACED,  '#');
    gb.setBlockType(GameBoard::BlockType::USER,    'X');

    /* main game loop */
    for(;;) {
        char input;
        input = getch();
        //cout << "input: " << input << endl;

        if(input >= 48 && input <= 57) {
            // spawn a user block
            gb.newBlock();
        } else {

            switch(input) {
                case 'a': case 'A':
                case 'w': case 'W':
                case 's': case 'S':
                case 'd': case 'D':
                    gb.moveBlock(input);
                    break;
                case '\n':
                    // place the user block
                    gb.applyGamePiece();
                    break;
                default:
                    break;
            }
        }
        gb.updateGameBoard();
        gb.displayBoard();
    }

    return 0;
}















