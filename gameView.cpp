#include "gameView.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <ncurses.h>
#include <cstring>
using namespace std;

GameView::GameView(int height_, int length_)
{

    height = height_;
    length = length_;
    gameView = new pair<char, int> *[height];

    for (int i = 0; i < height; i++)
    {

        gameView[i] = new pair<char, int>[length];
    }
    setGameView();
}

GameView::~GameView()
{
    for (int i = 0; i < height; i++)
    {
        delete[] gameView[i];
    }
    delete[] gameView;
}

void GameView::setPiece(Piece p)
{
    drawPiece(p, '@');
}

void GameView::clearPiece(Piece p)
{
    drawPiece(p, ' ');
}

void GameView::drawPiece(Piece p, char c)
{
    if (p.getPiece() == line)
    {
        if (p.getRotation() == side_top || p.getRotation() == side_bottom)
        {
            for (int i = p.getY(); i < p.getY() + 4; i++)
            {
                setCell(p.getX(), i, c, p.getColor());
            }
        }
        else
        {
            for (int i = p.getX(); i < p.getX() + 4; i++)
            {
                setCell(i, p.getY(), c, p.getColor());
            }
        }
    }
    else if (p.getPiece() == square)
    {
        setCell(p.getX(), p.getY(), c, p.getColor());
        setCell(p.getX() + 1, p.getY(), c, p.getColor());
        setCell(p.getX(), p.getY() + 1, c, p.getColor());
        setCell(p.getX() + 1, p.getY() + 1, c, p.getColor());
    }
    else if (p.getPiece() == leftS)
    {
        if (p.getRotation() == side_top || p.getRotation() == side_bottom)
        {
            setCell(p.getX() + 1, p.getY(), c, p.getColor());
            setCell(p.getX() + 2, p.getY(), c, p.getColor());
            setCell(p.getX(), p.getY() + 1, c, p.getColor());
            setCell(p.getX() + 1, p.getY() + 1, c, p.getColor());
        }
        else
        {
            setCell(p.getX(), p.getY(), c, p.getColor());
            setCell(p.getX(), p.getY() + 1, c, p.getColor());
            setCell(p.getX() + 1, p.getY() + 1, c, p.getColor());
            setCell(p.getX() + 1, p.getY() + 2, c, p.getColor());
        }
    }
    else if (p.getPiece() == rightS)
    {
        if (p.getRotation() == side_top || p.getRotation() == side_bottom)
        {
            setCell(p.getX(), p.getY(), c, p.getColor());
            setCell(p.getX() + 1, p.getY(), c, p.getColor());
            setCell(p.getX() + 1, p.getY() + 1, c, p.getColor());
            setCell(p.getX() + 2, p.getY() + 1, c, p.getColor());
        }
        else
        {
            setCell(p.getX(), p.getY() + 1, c, p.getColor());
            setCell(p.getX(), p.getY() + 2, c, p.getColor());
            setCell(p.getX() + 1, p.getY(), c, p.getColor());
            setCell(p.getX() + 1, p.getY() + 1, c, p.getColor());
        }
    }
    else if (p.getPiece() == leftL)
    {
        if (p.getRotation() == side_top)
        {
            setCell(p.getX(), p.getY(), c, p.getColor());
            setCell(p.getX() + 1, p.getY(), c, p.getColor());
            setCell(p.getX() + 1, p.getY() + 1, c, p.getColor());
            setCell(p.getX() + 1, p.getY() + 2, c, p.getColor());
        }
        else if (p.getRotation() == side_right)
        {
            setCell(p.getX(), p.getY(), c, p.getColor());
            setCell(p.getX(), p.getY() + 1, c, p.getColor());
            setCell(p.getX() + 1, p.getY(), c, p.getColor());
            setCell(p.getX() + 2, p.getY(), c, p.getColor());
        }
        else if (p.getRotation() == side_bottom)
        {
            setCell(p.getX(), p.getY(), c, p.getColor());
            setCell(p.getX(), p.getY() + 1, c, p.getColor());
            setCell(p.getX(), p.getY() + 2, c, p.getColor());
            setCell(p.getX() + 1, p.getY() + 2, c, p.getColor());
        }
        else if (p.getRotation() == side_left)
        {
            setCell(p.getX(), p.getY() + 1, c, p.getColor());
            setCell(p.getX() + 1, p.getY() + 1, c, p.getColor());
            setCell(p.getX() + 2, p.getY(), c, p.getColor());
            setCell(p.getX() + 2, p.getY() + 1, c, p.getColor());
        }
    }
    else if (p.getPiece() == rightL)
    {
        if (p.getRotation() == side_top)
        {
            setCell(p.getX() + 1, p.getY(), c, p.getColor());
            setCell(p.getX() + 1, p.getY() + 1, c, p.getColor());
            setCell(p.getX() + 1, p.getY() + 2, c, p.getColor());
            setCell(p.getX(), p.getY() + 2, c, p.getColor());
        }
        else if (p.getRotation() == side_right)
        {
            setCell(p.getX(), p.getY(), c, p.getColor());
            setCell(p.getX() + 2, p.getY() + 1, c, p.getColor());
            setCell(p.getX() + 1, p.getY(), c, p.getColor());
            setCell(p.getX() + 2, p.getY(), c, p.getColor());
        }
        else if (p.getRotation() == side_bottom)
        {
            setCell(p.getX(), p.getY(), c, p.getColor());
            setCell(p.getX(), p.getY() + 1, c, p.getColor());
            setCell(p.getX(), p.getY() + 2, c, p.getColor());
            setCell(p.getX() + 1, p.getY(), c, p.getColor());
        }
        else if (p.getRotation() == side_left)
        {
            setCell(p.getX(), p.getY() + 1, c, p.getColor());
            setCell(p.getX() + 1, p.getY() + 1, c, p.getColor());
            setCell(p.getX(), p.getY(), c, p.getColor());
            setCell(p.getX() + 2, p.getY() + 1, c, p.getColor());
        }
    }
    else if (p.getPiece() == pieceT)
    {
        if (p.getRotation() == side_top)
        {
            setCell(p.getX(), p.getY() + 1, c, p.getColor());
            setCell(p.getX() + 1, p.getY(), c, p.getColor());
            setCell(p.getX() + 1, p.getY() + 1, c, p.getColor());
            setCell(p.getX() + 1, p.getY() + 2, c, p.getColor());
        }
        else if (p.getRotation() == side_right)
        {
            setCell(p.getX(), p.getY(), c, p.getColor());
            setCell(p.getX() + 1, p.getY() + 1, c, p.getColor());
            setCell(p.getX() + 1, p.getY(), c, p.getColor());
            setCell(p.getX() + 2, p.getY(), c, p.getColor());
        }
        else if (p.getRotation() == side_bottom)
        {
            setCell(p.getX(), p.getY(), c, p.getColor());
            setCell(p.getX(), p.getY() + 1, c, p.getColor());
            setCell(p.getX(), p.getY() + 2, c, p.getColor());
            setCell(p.getX() + 1, p.getY() + 1, c, p.getColor());
        }
        else if (p.getRotation() == side_left)
        {
            setCell(p.getX(), p.getY() + 1, c, p.getColor());
            setCell(p.getX() + 1, p.getY() + 1, c, p.getColor());
            setCell(p.getX() + 2, p.getY() + 1, c, p.getColor());
            setCell(p.getX() + 1, p.getY(), c, p.getColor());
        }
    }
}
void GameView::display()
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            char c = gameView[i][j].first;
            int color = gameView[i][j].second;
            move(i, j);

            attron(COLOR_PAIR(color));
            addch(c);
            attroff(COLOR_PAIR(color));
        }
    }
    refresh();
}

void GameView::setGameView()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            setCell(i, j, ' ', COLOR_WHITE);
        }
    }

    for (int i = 0; i < length - 7; i++)
    {

        setCell(0, i, '#', COLOR_WHITE);
    }
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 0; j < length - 7; j++)
        {
            if (j == 0 || j == length - 8)
            {
                setCell(i, j, '#', COLOR_WHITE);
            }
            else
            {
                setCell(i, j, ' ', COLOR_WHITE);
            }
        }
    }
    for (int i = 0; i < length - 7; i++)
    {
        setCell(height - 1, i, '#', COLOR_WHITE);
    }

    setCell(3, length - 6, 's', COLOR_WHITE);
    setCell(3, length - 5, 'c', COLOR_WHITE);
    setCell(3, length - 4, 'o', COLOR_WHITE);
    setCell(3, length - 3, 'r', COLOR_WHITE);
    setCell(3, length - 2, 'e', COLOR_WHITE);

    setCell(5, length - 5, '0', COLOR_WHITE);
    setCell(5, length - 4, '0', COLOR_WHITE);
    setCell(5, length - 3, '0', COLOR_WHITE);
    setCell(5, length - 2, '0', COLOR_WHITE);

    setCell(7, length - 7, ' ', COLOR_WHITE);
    setCell(7, length - 6, 'p', COLOR_WHITE);
    setCell(7, length - 5, 'i', COLOR_WHITE);
    setCell(7, length - 4, 'e', COLOR_WHITE);
    setCell(7, length - 3, 'c', COLOR_WHITE);
    setCell(7, length - 2, 'e', COLOR_WHITE);
}

void GameView::setCell(int row, int column, char c, int color)
{
    gameView[row][column] = make_pair(c, color);
}

bool GameView::checkCollision(Piece p)
{
    if (p.getPiece() == line)
    {
        if (p.getRotation() == side_top || p.getRotation() == side_bottom)
        {
            return checkCollisionCell(p.getX(), p.getY()) || checkCollisionCell(p.getX(), p.getY() + 1) || checkCollisionCell(p.getX(), p.getY() + 2) || checkCollisionCell(p.getX(), p.getY() + 3);
        }
        else
        {
            return checkCollisionCell(p.getX(), p.getY()) || checkCollisionCell(p.getX() + 1, p.getY()) || checkCollisionCell(p.getX() + 2, p.getY()) || checkCollisionCell(p.getX() + 3, p.getY());
        }
    }
    else if (p.getPiece() == square)
    {
        return checkCollisionCell(p.getX(), p.getY()) || checkCollisionCell(p.getX() + 1, p.getY()) || checkCollisionCell(p.getX(), p.getY() + 1) || checkCollisionCell(p.getX() + 1, p.getY() + 1);
    }
    else if (p.getPiece() == leftS)
    {
        if (p.getRotation() == side_top || p.getRotation() == side_bottom)
        {
            return checkCollisionCell(p.getX() + 1, p.getY()) || checkCollisionCell(p.getX() + 2, p.getY()) || checkCollisionCell(p.getX(), p.getY() + 1) || checkCollisionCell(p.getX() + 1, p.getY() + 1);
        }
        else
        {
            return checkCollisionCell(p.getX(), p.getY()) || checkCollisionCell(p.getX(), p.getY() + 1) || checkCollisionCell(p.getX() + 1, p.getY() + 1) || checkCollisionCell(p.getX() + 1, p.getY() + 2);
        }
    }
    else if (p.getPiece() == rightS)
    {
        if (p.getRotation() == side_top || p.getRotation() == side_bottom)
        {
            return checkCollisionCell(p.getX(), p.getY()) || checkCollisionCell(p.getX() + 1, p.getY()) || checkCollisionCell(p.getX() + 1, p.getY() + 1) || checkCollisionCell(p.getX() + 2, p.getY() + 1);
        }
        else
        {
            return checkCollisionCell(p.getX(), p.getY() + 1) || checkCollisionCell(p.getX(), p.getY() + 2) || checkCollisionCell(p.getX() + 1, p.getY()) || checkCollisionCell(p.getX() + 1, p.getY() + 1);
        }
    }
    else if (p.getPiece() == leftL)
    {
        if (p.getRotation() == side_top)
        {
            return checkCollisionCell(p.getX(), p.getY()) || checkCollisionCell(p.getX() + 1, p.getY()) || checkCollisionCell(p.getX() + 1, p.getY() + 1) || checkCollisionCell(p.getX() + 1, p.getY() + 2);
        }
        else if (p.getRotation() == side_right)
        {
            return checkCollisionCell(p.getX(), p.getY()) || checkCollisionCell(p.getX(), p.getY() + 1) || checkCollisionCell(p.getX() + 1, p.getY()) || checkCollisionCell(p.getX() + 2, p.getY());
        }
        else if (p.getRotation() == side_bottom)
        {
            return checkCollisionCell(p.getX(), p.getY()) || checkCollisionCell(p.getX(), p.getY() + 1) || checkCollisionCell(p.getX(), p.getY() + 2) || checkCollisionCell(p.getX() + 1, p.getY() + 2);
        }
        else if (p.getRotation() == side_left)
        {
            return checkCollisionCell(p.getX(), p.getY() + 1) || checkCollisionCell(p.getX() + 1, p.getY() + 1) || checkCollisionCell(p.getX() + 2, p.getY()) || checkCollisionCell(p.getX() + 2, p.getY() + 1);
        }
    }
    else if (p.getPiece() == rightL)
    {
        if (p.getRotation() == side_top)
        {
            return checkCollisionCell(p.getX() + 1, p.getY()) || checkCollisionCell(p.getX() + 1, p.getY() + 1) || checkCollisionCell(p.getX() + 1, p.getY() + 2) || checkCollisionCell(p.getX(), p.getY() + 1);
        }
        else if (p.getRotation() == side_right)
        {
            return checkCollisionCell(p.getX(), p.getY()) || checkCollisionCell(p.getX() + 2, p.getY() + 1) || checkCollisionCell(p.getX() + 1, p.getY()) || checkCollisionCell(p.getX() + 2, p.getY());
        }
        else if (p.getRotation() == side_bottom)
        {
            return checkCollisionCell(p.getX(), p.getY()) || checkCollisionCell(p.getX(), p.getY() + 1) || checkCollisionCell(p.getX(), p.getY() + 2) || checkCollisionCell(p.getX() + 1, p.getY());
        }
        else if (p.getRotation() == side_left)
        {
            return checkCollisionCell(p.getX(), p.getY() + 1) || checkCollisionCell(p.getX() + 1, p.getY() + 1) || checkCollisionCell(p.getX(), p.getY()) || checkCollisionCell(p.getX() + 2, p.getY() + 1);
        }
    }
    else if (p.getPiece() == pieceT)
    {
        if (p.getRotation() == side_top)
        {
            return checkCollisionCell(p.getX(), p.getY() + 1) || checkCollisionCell(p.getX() + 1, p.getY()) || checkCollisionCell(p.getX() + 1, p.getY() + 1) || checkCollisionCell(p.getX() + 1, p.getY() + 2);
        }
        else if (p.getRotation() == side_right)
        {
            return checkCollisionCell(p.getX(), p.getY()) || checkCollisionCell(p.getX() + 1, p.getY() + 1) || checkCollisionCell(p.getX() + 1, p.getY()) || checkCollisionCell(p.getX() + 2, p.getY());
        }
        else if (p.getRotation() == side_bottom)
        {
            return checkCollisionCell(p.getX(), p.getY()) || checkCollisionCell(p.getX(), p.getY() + 1) || checkCollisionCell(p.getX(), p.getY() + 2) || checkCollisionCell(p.getX() + 1, p.getY() + 1);
        }
        else if (p.getRotation() == side_left)
        {
            return checkCollisionCell(p.getX(), p.getY() + 1) || checkCollisionCell(p.getX() + 1, p.getY() + 1) || checkCollisionCell(p.getX() + 2, p.getY() + 1) || checkCollisionCell(p.getX() + 1, p.getY());
        }
    }
    return false;
}

bool GameView::checkCollisionCell(int x, int y)
{
    return gameView[x][y].first == '@' || gameView[x][y].first == '#';
}

int GameView::clearRows()
{
    int n = 0;
    for (int i = height - 1; i > 1; i--)
    {
        n = n + clearRow(i);
    }
    if (n > 0)
    {
        shiftRows(n);
    }
    return n;
}

int GameView::clearRow(int row)
{
    bool clear = true;
    for (int i = 1; i < length - 8; i++)
    {
        clear = clear && gameView[row][i].first == '@';
    }
    if (clear)
    {
        for (int i = 1; i < length - 8; i++)
        {
            setCell(row, i, ' ', COLOR_WHITE);
        }
        return 1;
    }
    return 0;
}

void GameView::drawScore(int n)
{
    std::string score = std::to_string(n);
    std::cout << score;
    while (score.length() < 4)
    {
        score.insert(0, "0");
    }
    setCell(5, length - 5, score[0], COLOR_WHITE);
    setCell(5, length - 4, score[1], COLOR_WHITE);
    setCell(5, length - 3, score[2], COLOR_WHITE);
    setCell(5, length - 2, score[3], COLOR_WHITE);
}

void GameView::shiftRows(int rows)
{
    for (int i = height - rows - 2; i > 0; i--)
    {
        shiftRow(i, i + rows);
    }
}

void GameView::shiftRow(int row_to_shift, int row)
{
    for (int i = 1; i < length - 8; i++)
    {
        pair<char, int> cell = gameView[row_to_shift][i];
        setCell(row_to_shift, i, ' ', COLOR_WHITE);
        setCell(row, i, cell.first, cell.second);
    }
}