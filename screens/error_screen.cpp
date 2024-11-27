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

    start_color();
    WINDOW *errorScreen = newwin(yMax, xMax, 0, 0);
    box(errorScreen, 0, 0);

    init_pair(8, COLOR_YELLOW, COLOR_BLACK); 
    wattron(aceptar,COLOR_PAIR(8)) ;
    mvwprintw(errorScreen, 5, 40, "Ya has pasado por aqui, continua tu camino por otro lado...");
    

    


    

    wrefresh(errorScreen);

    
    wgetch(errorScreen);
    endwin();

    return 0;
}
