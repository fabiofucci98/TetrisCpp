#ifndef GAME
#define GAME

#include "piece.h"
#include "gameView.h"
#include <string>

class Game
{

public:
    Game(int height, int lenght);
    ~Game();
    void display();
    void update();
    void moveLeft();
    void moveRight();
    void rotateRight();
    void rotateLeft();
    int clearRows();
    void setScore(int);
    void drawScore();

private:
    GameView gameView;
    Piece nextPiece;
    Piece fallingPiece;
    int score;

    piece getRandomPiece();
    int getRandomColor();
    rotation getRandomRotation();
    Piece getNextRandom();
    Piece getFallingRandom();
    bool checkCollision(Piece);
};

#endif
