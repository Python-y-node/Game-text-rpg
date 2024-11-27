#include <iostream>
#include <ncurses.h>

using namespace std;

int main() {
    int yMax, xMax;

    
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, yMax, xMax);

    
    WINDOW *startScreen = newwin(yMax, xMax, 0, 0);
    box(startScreen, 0, 0);


    mvwprintw(startScreen, 5, 10, "Tu padre ha sido seleccionado para una mision importante.");

    wrefresh(startScreen);

    
    getch(startScreen);
    endwin();

    return 0;
}
