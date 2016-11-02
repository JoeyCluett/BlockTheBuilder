/*
    Author: Joey Cluett

    Date Created: 10-18-2016

    Date Last Modified: 11-1-2016
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

    //gb.displayBoard();

    /* main game loop */
    for(;;) {
        char input;
        input = getch();

        cout << "input: " << input << endl;

    }

    return 0;
}















