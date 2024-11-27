#include <iostream>
#include <ncurses.h>

using namespace std;

void wizardAnimation(WINDOW*window, int y, int x) {

    init_pair(21, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(22, COLOR_YELLOW, COLOR_BLACK);
    init_pair(23, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(24, COLOR_GREEN, COLOR_BLACK);

    wattron( window, COLOR_PAIR(21));
        // Sombrero
        mvwaddch(window, y + 2, x + 2, '/');
        mvwaddch(window, y + 2, x + 3, ACS_HLINE);
        mvwaddch(window, y  + 2, x + 4, '\\');
        mvwaddch(window, y + 1, x + 3, '^');
        
        mvwaddch(window, y + 3, x , ACS_HLINE);
        mvwaddch(window, y + 3, x + 1, ACS_HLINE);
        mvwaddch(window, y + 3, x + 2, ACS_HLINE);
        mvwaddch(window, y + 3, x + 3, ACS_HLINE);
        mvwaddch(window, y + 3, x + 4, ACS_HLINE);
        mvwaddch(window, y + 3, x + 5, ACS_HLINE);
        mvwaddch(window, y + 3, x + 6, ACS_HLINE);
        mvwaddch(window, y + 3, x + 7, ACS_HLINE);

         //Varita
        mvwaddch(window, y + 7, x + 8, ACS_VLINE);
        mvwaddch(window, y + 6, x + 8, ACS_VLINE);
        mvwaddch(window, y + 5, x + 8, ACS_DIAMOND);

        // Body
        mvwaddch(window, y + 7, x + 6, ACS_HLINE);
        mvwaddch(window, y + 7, x - 1, ACS_HLINE);
        mvwaddch(window, y + 9, x, ACS_LLCORNER);
        mvwaddch(window, y + 9, x + 1, ACS_HLINE);
        mvwaddch(window, y + 9, x + 2, ACS_HLINE);
        mvwaddch(window, y + 9, x + 3, ACS_HLINE);
        mvwaddch(window, y + 9, x + 4, ACS_HLINE);
        mvwaddch(window, y + 9, x + 5, ACS_LRCORNER);

         // Legs
        mvwaddch(window, y + 10, x, ACS_VLINE);
        mvwaddch(window, y + 10, x + 5, ACS_VLINE);
        mvwaddch(window, y + 11, x, ACS_VLINE);
        mvwaddch(window, y + 11, x + 5, ACS_VLINE);

        mvwaddch(window, y + 12, x, ACS_LLCORNER);
        mvwaddch(window, y + 12, x + 1, ACS_HLINE);
        mvwaddch(window, y + 12, x + 2, ACS_HLINE);
        mvwaddch(window, y + 11, x + 2, '_');
        mvwaddch(window, y + 11, x + 3, ACS_VLINE);
        mvwaddch(window, y + 12, x + 3, ACS_BTEE);
        mvwaddch(window, y + 11, x + 4, '_');
        mvwaddch(window, y + 12, x + 5, '_');
        mvwaddch(window, y + 12, x + 4, ACS_HLINE);
        mvwaddch(window, y + 12, x + 5, ACS_HLINE);
        mvwaddch(window, y + 12, x + 6, ACS_LRCORNER);

        // Eyes
        mvwaddch(window, y + 4, x + 2, '@');
        mvwaddch(window, y + 4, x + 4, '@');

    wattroff( window, COLOR_PAIR(21));

    wattron( window, COLOR_PAIR(22));
        // Mustache
        mvwaddch(window, y + 5, x + 1, ACS_HLINE);
        mvwaddch(window, y + 5, x + 2, ACS_HLINE);
        mvwaddch(window, y + 5, x + 3, '_');
        mvwaddch(window, y + 5, x + 4, ACS_HLINE);
        mvwaddch(window, y + 5, x + 5, ACS_HLINE);
        
        //Brazo derecho
        mvwaddch(window, y + 8, x + 5, ACS_VLINE);
        mvwaddch(window, y + 8, x + 7, ACS_VLINE);
        mvwaddch(window, y + 9, x + 7, ACS_LRCORNER);

        //brazo izquierdo
        mvwaddch(window,  y + 8, x - 2, ACS_VLINE);
        mvwaddch(window,  y + 8, x, ACS_VLINE);
        mvwaddch(window,  y + 9, x - 2, ACS_LLCORNER);

         // Chin
        mvwaddch(window, y + 6, x, ACS_LLCORNER);
        mvwaddch(window, y + 6, x + 5, ACS_LRCORNER);

    wattroff( window, COLOR_PAIR(22));


}

