#ifndef GAME_VIEW
#define GAME_VIEW

#include "piece.h"
#include <string>

using namespace std;

class GameView
{

public:
    GameView(int height_, int length_);
    ~GameView();
    void setPiece(Piece);
    void clearPiece(Piece);
    void drawPiece(Piece, char);
    void display();
    bool checkCollision(Piece);
    int clearRows();
    int clearRow(int);
    void drawScore(int);
    void shiftRows(int);

private:
    pair<char, int> **gameView;
    int height;
    int length;

    void setGameView();
    void setCell(int row, int column, char c, int color);
    bool checkCollisionCell(int, int);
    void shiftRow(int, int);
};

#endif
