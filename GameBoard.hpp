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

    enum BlockType {
        OVERLAP, PLACED, EMPTY, USER
    };

    void setBlockType(BlockType bt, char vis);

    void newBlock(void);
    void eraseBlock(void);

    void updateGameBoard(void);
    void moveBlock(char direction);
    void applyGamePiece(void);

private:
    struct GameTile {
        char visChar;
        bool hasUser = false;
        bool hasBlock = false;
    };

    GameTile board[BOARDWIDTH][BOARDHEIGHT];

    /* configuration characters, define the board look */
    char overlap_;
    char placed_;
    char empty_;
    char user_;

    /* user block tracking variables */
    int xPos;
    int yPos;
    bool isBlock; // dont want to operate on a nonexistant block

};

// -- start of class definition

void GameBoard::applyGamePiece(void) {

    if(!isBlock)
        return;

    for(int x = 0; x < BOARDWIDTH; x++) {
        for(int y = 0; y < BOARDHEIGHT; y++) {
            if(board[x][y].hasUser) {
                board[x][y].hasBlock = true;
                board[x][y].hasUser = false;
            }
        }
    }

    isBlock = false;
}

void GameBoard::moveBlock(char direction) {
    if(!isBlock)
        return;
    board[xPos][yPos].hasUser = false;

    switch(direction) {
        case 'W':
        case 'w':
            yPos--;
            break;
        case 'A':
        case 'a':
            xPos--;
            break;
        case 'S':
        case 's':
            yPos++;
            break;
        case 'D':
        case 'd':
            xPos++;
            break;
        default:
            std::cout << "Invalid character supplied" << std::endl;
            return;
    }

    board[xPos][yPos].hasUser = true;

}

void GameBoard::updateGameBoard(void) {
    if(!isBlock)
        return;

    for(int x = 0; x < BOARDWIDTH; x++) {
        for(int y = 0; y < BOARDHEIGHT; y++) {
            if(board[x][y].hasUser && board[x][y].hasBlock) {
                board[x][y].visChar = overlap_;
            } else if(board[x][y].hasUser && !board[x][y].hasBlock) {
                board[x][y].visChar = user_;
            } else if(!board[x][y].hasUser && board[x][y].hasBlock) {
                board[x][y].visChar = placed_;
            } else if(!board[x][y].hasUser && !board[x][y].hasBlock) {
                board[x][y].visChar = empty_;
            }
        }
    }
}

void GameBoard::newBlock(void) {

    if(isBlock)
        eraseBlock();

    xPos = 0;
    yPos = 0;
    isBlock = true;
}

void GameBoard::eraseBlock(void) {
    isBlock = false;
}

void GameBoard::setBlockType(BlockType bt, char vis) {
    switch(bt) {
        case OVERLAP:
            overlap_ = vis;
            break;
        case PLACED:
            placed_ = vis;
            break;
        case EMPTY:
            empty_ = vis;
            break;
        case USER:
            user_ = vis;
            break;
        default:
            std::cout << "Error in setBlockType configuration" << std::endl;
            exit(1);
    }
}

void GameBoard::displayBoard(void) {
    system("clear"); // Linux, Windows users use 'cls'

    for(int i = 0; i < 80; i++)
        std::cout << '-';
    std::cout << std::endl;

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
