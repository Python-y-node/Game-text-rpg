#include <iostream>
#include <ncurses.h>

using namespace std;

void wizard_animation(WINDOW*juego2, int y, int x) {
    // Sombrero
    mvwaddch(juego2, y + 2, x + 2, '/');
    mvwaddch(juego2, y + 2, x + 3, ACS_HLINE);
    mvwaddch(juego2, y  + 2, x + 4, '\\');
    mvwaddch(juego2, y + 1, x + 3, '^');
    
    mvwaddch(juego2, y + 3, x , ACS_HLINE);
    mvwaddch(juego2, y + 3, x + 1, ACS_HLINE);
    mvwaddch(juego2, y + 3, x + 2, ACS_HLINE);
    mvwaddch(juego2, y + 3, x + 3, ACS_HLINE);
    mvwaddch(juego2, y + 3, x + 4, ACS_HLINE);
    mvwaddch(juego2, y + 3, x + 5, ACS_HLINE);
    mvwaddch(juego2, y + 3, x + 6, ACS_HLINE);
    mvwaddch(juego2, y + 3, x + 7, ACS_HLINE);



    // Eyes
    mvwaddch(juego2, y + 4, x + 2, '0');
    mvwaddch(juego2, y + 4, x + 4, '0');

    // Mustache
    mvwaddch(juego2, y + 5, x + 1, ACS_HLINE);
    mvwaddch(juego2, y + 5, x + 2, ACS_HLINE);
    mvwaddch(juego2, y + 5, x + 3, '_');
    mvwaddch(juego2, y + 5, x + 4, ACS_HLINE);
    mvwaddch(juego2, y + 5, x + 5, ACS_HLINE);

    // Chin
    mvwaddch(juego2, y + 6, x, ACS_LLCORNER);
    mvwaddch(juego2, y + 6, x + 5, ACS_LRCORNER);

    // Body
    mvwaddch(juego2, y + 7, x + 6, ACS_HLINE);
    mvwaddch(juego2, y + 7, x - 1, ACS_HLINE);
    mvwaddch(juego2, y + 9, x, ACS_LLCORNER);
    mvwaddch(juego2, y + 9, x + 1, ACS_HLINE);
    mvwaddch(juego2, y + 9, x + 2, ACS_HLINE);
    mvwaddch(juego2, y + 9, x + 3, ACS_HLINE);
    mvwaddch(juego2, y + 9, x + 4, ACS_HLINE);
    mvwaddch(juego2, y + 9, x + 5, ACS_LRCORNER);

    //Brazo derechp
    mvwaddch(juego2, y + 8, x + 5, ACS_VLINE);
    mvwaddch(juego2, y + 8, x + 7, ACS_VLINE);
    mvwaddch(juego2, y + 9, x + 7, ACS_LRCORNER);

    //Varita
    mvwaddch(juego2, y + 7, x + 8, ACS_VLINE);
    mvwaddch(juego2, y + 6, x + 8, ACS_VLINE);
    mvwaddch(juego2, y + 5, x + 8, ACS_DIAMOND);

    mvwaddch(juego2,  y + 8, x - 2, ACS_VLINE);
    mvwaddch(juego2,  y + 8, x, ACS_VLINE);
     mvwaddch(juego2,  y + 9, x - 2, ACS_LLCORNER);

    // Legs
    mvwaddch(juego2, y + 10, x, ACS_VLINE);
    mvwaddch(juego2, y + 10, x + 5, ACS_VLINE);
    mvwaddch(juego2, y + 11, x, ACS_VLINE);
    mvwaddch(juego2, y + 11, x + 5, ACS_VLINE);

    mvwaddch(juego2, y + 12, x, ACS_LLCORNER);
    mvwaddch(juego2, y + 12, x + 1, ACS_HLINE);
    mvwaddch(juego2, y + 12, x + 2, ACS_HLINE);
    mvwaddch(juego2, y + 11, x + 2, '_');
    mvwaddch(juego2, y + 11, x + 3, ACS_VLINE);
    mvwaddch(juego2, y + 12, x + 3, ACS_BTEE);
    mvwaddch(juego2, y + 11, x + 4, '_');
    mvwaddch(juego2, y + 12, x + 5, '_');
    mvwaddch(juego2, y + 12, x + 4, ACS_HLINE);
    mvwaddch(juego2, y + 12, x + 5, ACS_HLINE);
    mvwaddch(juego2, y + 12, x + 6, ACS_LRCORNER);
}

