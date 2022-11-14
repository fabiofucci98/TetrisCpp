#include <unistd.h>
#include "gameView.h"
#include <utility>
#include "game.h"
#include <time.h>
#include <chrono>
#include <thread>
#include <ncurses.h>
#include <iostream>

int main()
{
    srand(time(NULL));
    system("clear");
    initscr();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    start_color();
    init_pair(0, COLOR_BLACK, COLOR_BLACK);

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    int height = 42;
    int length = 28;
    Game game = Game(height, length);
    bool playing = true;
    while (playing)
    {
        game.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        int tmp = getch();
        switch (tmp)
        {
        case KEY_LEFT:
            game.moveLeft();
            break;
        case KEY_RIGHT:
            game.moveRight();
            break;
        case KEY_UP:
            game.rotateLeft();
            break;
        case KEY_DOWN:
            game.rotateRight();
            break;
        case 'q':
            playing = false;
            break;
        }
        flushinp();
        game.update();
    }
    nodelay(stdscr, false);
    endwin();
    return 0;
}
