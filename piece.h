#ifndef PIECE
#define PIECE

#include <map>
#include <string>
enum piece
{
    line,
    leftL,
    rightL,
    square,
    leftS,
    rightS,
    pieceT
};

enum rotation
{
    side_top,
    side_bottom,
    side_left,
    side_right
};

const int PIECES_NUMBER = 7;
const int COLOR_NUMBER = 6;
const int ROTATION_NUMBER = 4;

class Piece
{
private:
    piece piece_;
    int color_;
    rotation rotation_;
    int positionX;
    int positionY;

public:
    Piece(piece, int, rotation, int, int);
    Piece(const Piece &);
    piece getPiece();
    int getColor();
    rotation getRotation();
    int getX();
    int getY();
    void fall();
    void rise();
    void moveLeft();
    void moveRight();
    void makeFalling();
    void rotateLeft();
    void rotateRight();
};

#endif