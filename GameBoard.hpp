#ifndef __GAMEBOARD__HPP__
#define __GAMEBOARD__HPP__

#ifndef BOARDHEIGHT
    #define BOARDHEIGHT 20
#endif // BOARDHEIGHT

#ifndef BOARDWIDTH
    #define BOARDWIDTH 60
#endif // BOARDWIDTH

#include <iostream>

class GameBoard {
public:
    GameBoard(char vChar) {
        initArray(vChar);
    }

    void displayBoard(void);
    void initArray(char vChar);

private:
    struct GameTile {
        char visChar;
        bool hasUser = false;
        bool hasBlock = false;
    };

    GameTile board[BOARDWIDTH][BOARDHEIGHT];

};

// -- start of class definition

void GameBoard::displayBoard(void) {
    for(int y = 0; y < BOARDHEIGHT; y++) {
        for(int x = 0; x < BOARDWIDTH; x++) {
            std::cout << board[x][y].visChar;
        }
        std::cout << std::endl;
    }
}

void GameBoard::initArray(char vChar) {
    for(int y = 0; y < BOARDHEIGHT; y++) {
        for(int x = 0; x < BOARDWIDTH; x++) {
            board[x][y].visChar = vChar;
        }
    }
}



#endif // __GAMEBOARD__HPP__
