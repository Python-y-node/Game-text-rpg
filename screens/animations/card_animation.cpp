#include <iostream>
#include <ncurses.h>

using namespace std;

void cardAnimation(WINDOW* window, int y, int x);


void cardAnimation(WINDOW* window, int y, int x){

    init_pair(23, COLOR_RED, COLOR_BLACK);

    // Parte izquierda del escudo
    mvwaddch(window, y, x - 2, ACS_HLINE);
    mvwaddch(window, y , x - 1, ACS_HLINE);
    mvwaddch(window, y , x - 3, ACS_HLINE);
    mvwaddch(window, y , x - 4, ACS_ULCORNER);
    mvwaddch(window, y , x, ACS_HLINE);
    mvwaddch(window, y , x + 1, ACS_URCORNER);

    // Parte derecha del escudo
    mvwaddch(window, y + 1, x + 1, ACS_VLINE);
    mvwaddch(window, y + 2, x + 1, ACS_VLINE);
    mvwaddch(window, y + 3, x + 1, ACS_LRCORNER);

    // Parte izquierda del escudo
    mvwaddch(window, y + 1, x - 4, ACS_VLINE);
    mvwaddch(window, y + 2, x - 4, ACS_VLINE);
    mvwaddch(window, y + 3, x - 4, ACS_LLCORNER);

    // Parte inferior del escudo
    mvwaddch(window, y + 3, x, ACS_HLINE);
    mvwaddch(window, y + 3, x - 2, ACS_HLINE);
    mvwaddch(window, y + 3, x - 1, ACS_HLINE);
    mvwaddch(window, y + 3, x - 3, ACS_HLINE);

    wattron(window, COLOR_PAIR(23));
        // Cuadro del centro (diamantes)
        mvwaddch(window, y + 1 , x - 1, ACS_DIAMOND);
        mvwaddch(window, y + 1, x - 2, ACS_DIAMOND);
        mvwaddch(window, y + 2, x - 1, ACS_DIAMOND);
        mvwaddch(window, y + 2, x - 2, ACS_DIAMOND);
    wattroff(window, COLOR_PAIR(23));
}
