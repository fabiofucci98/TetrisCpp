#include "game.h"
#include "piece.h"
#include "gameView.h"
#include <iostream>
Game::Game(int height, int length)

    : gameView(GameView(height, length)),
      score(0),
      nextPiece(getNextRandom()),
      fallingPiece(getFallingRandom())
{
    gameView.setPiece(nextPiece);
    gameView.setPiece(fallingPiece);
}

Game::~Game()
{
}

void Game::display()
{
    gameView.display();
}

Piece Game::getNextRandom()
{
    piece p = static_cast<piece>(rand() % PIECES_NUMBER);
    int c = rand() % COLOR_NUMBER;
    rotation r = static_cast<rotation>(rand() % ROTATION_NUMBER);
    return Piece(p, c, r, 9, 24);
}

Piece Game::getFallingRandom()
{
    piece p = static_cast<piece>(rand() % PIECES_NUMBER);
    int c = rand() % COLOR_NUMBER;
    rotation r = static_cast<rotation>(rand() % ROTATION_NUMBER);
    return Piece(p, c, r, 1, 10);
}

void Game::update()
{

    gameView.clearPiece(fallingPiece);
    fallingPiece.fall();
    if (checkCollision(fallingPiece))
    {
        fallingPiece.rise();
        gameView.setPiece(fallingPiece);
        gameView.clearPiece(nextPiece);
        fallingPiece = nextPiece;
        fallingPiece.makeFalling();
        nextPiece = getNextRandom();
        gameView.setPiece(nextPiece);
        int n = clearRows();
        n = n * 100;
        setScore(score + n);
        drawScore();
    }
    gameView.setPiece(fallingPiece);
}

void Game::moveLeft()
{
    gameView.clearPiece(fallingPiece);

    fallingPiece.moveLeft();
    if (checkCollision(fallingPiece))
    {
        fallingPiece.moveRight();
        return;
    }
}

void Game::moveRight()
{
    gameView.clearPiece(fallingPiece);

    fallingPiece.moveRight();
    if (checkCollision(fallingPiece))
    {
        fallingPiece.moveLeft();
        return;
    }
}

bool Game::checkCollision(Piece p)
{
    return gameView.checkCollision(p);
}

void Game::rotateLeft()
{
    gameView.clearPiece(fallingPiece);
    fallingPiece.rotateLeft();
    if (checkCollision(fallingPiece))
    {
        fallingPiece.rotateRight();
    }
}

void Game::rotateRight()
{
    gameView.clearPiece(fallingPiece);
    fallingPiece.rotateRight();
    if (checkCollision(fallingPiece))
    {
        fallingPiece.rotateLeft();
    }
}
int Game::clearRows()
{
    return gameView.clearRows();
}

void Game::setScore(int n)
{
    score = n;
}

void Game::drawScore()
{
    gameView.drawScore(score);
}