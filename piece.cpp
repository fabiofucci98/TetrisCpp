#include "piece.h"

Piece::Piece(piece p, int c, rotation r, int x, int y)
    : piece_(p),
      color_(c),
      rotation_(r),
      positionX(x),
      positionY(y)
{
}

Piece::Piece(const Piece &piece)
    : piece_(piece.piece_),
      color_(piece.color_),
      rotation_(piece.rotation_),
      positionX(piece.positionX),
      positionY(piece.positionY)

{
}
piece Piece::getPiece()
{
    return piece_;
}
int Piece::getColor()
{
    return color_;
}
rotation Piece::getRotation()
{
    return rotation_;
}
int Piece::getX()
{
    return positionX;
}
int Piece::getY()
{
    return positionY;
}

void Piece::fall()
{
    positionX++;
}

void Piece::rise()
{
    positionX--;
}
void Piece::moveLeft()
{
    positionY--;
}
void Piece::moveRight()
{
    positionY++;
}

void Piece::makeFalling()
{
    positionX = 1;
    positionY = 10;
}

void Piece::rotateLeft()
{
    int rot = static_cast<int>(rotation_);
    rot++;
    rotation_ = static_cast<rotation>(rot % ROTATION_NUMBER);
}

void Piece::rotateRight()
{
    int rot = static_cast<int>(rotation_);
    rot--;
    rotation_ = static_cast<rotation>(rot % ROTATION_NUMBER);
}