#include <iostream>
#include <ncurses.h>

using namespace std;

void basePlayerNoHat(WINDOW*juego, int y, int x);


void basePlayerNoHat(WINDOW* juego, int y, int x) {

   // cabeza
mvwaddch(juego, y, x, ACS_ULCORNER);
mvwaddch(juego, y, x + 1, ACS_HLINE);
mvwaddch(juego, y, x + 2, ACS_HLINE);
mvwaddch(juego, y, x + 3, ACS_HLINE);
mvwaddch(juego, y, x + 4, ACS_HLINE);
mvwaddch(juego, y, x + 5, ACS_URCORNER);

mvwaddch(juego, y + 1, x, ACS_VLINE);
mvwaddch(juego, y + 1, x + 5, ACS_VLINE);

// Unibrow 
mvwaddch(juego, y + 1, x + 1, ACS_HLINE);  
mvwaddch(juego, y + 1, x + 2, ACS_HLINE);
mvwaddch(juego, y + 1, x + 3, ACS_HLINE);
mvwaddch(juego, y + 1, x + 4, ACS_HLINE);

// ojo
mvwaddch(juego, y + 2, x + 2, '0');
mvwaddch(juego, y + 2, x + 4, '0');

// bigote
mvwaddch(juego, y + 3, x + 1, ACS_HLINE);
mvwaddch(juego, y + 3, x + 2, ACS_HLINE);
mvwaddch(juego, y + 3, x + 3, '_');
mvwaddch(juego, y + 3, x + 4, ACS_HLINE);
mvwaddch(juego, y + 3, x + 5, ACS_HLINE);

// barbilla
mvwaddch(juego, y + 4, x, ACS_LLCORNER);
mvwaddch(juego, y + 4, x + 5, ACS_LRCORNER);

// cuerpo
mvwaddch(juego, y + 5, x + 6, ACS_HLINE);
mvwaddch(juego, y + 5, x - 1, ACS_HLINE);
mvwaddch(juego, y + 7, x, ACS_LLCORNER);
mvwaddch(juego, y + 7, x + 1, ACS_HLINE);
mvwaddch(juego, y + 7, x + 2, ACS_HLINE);
mvwaddch(juego, y + 7, x + 3, ACS_HLINE);
mvwaddch(juego, y + 7, x + 4, ACS_HLINE);
mvwaddch(juego, y + 7, x + 5, ACS_LRCORNER);



// brazo derecho
mvwaddch(juego, y + 6, x + 5, ACS_VLINE);
mvwaddch(juego, y + 6, x + 7, ACS_VLINE);
mvwaddch(juego, y + 7, x + 7, ACS_LRCORNER);

// piernas
mvwaddch(juego, y + 8, x, ACS_VLINE);
mvwaddch(juego, y + 8, x + 5, ACS_VLINE);
mvwaddch(juego, y + 9, x, ACS_VLINE);
mvwaddch(juego, y + 9, x + 5, ACS_VLINE);

mvwaddch(juego, y + 10, x, ACS_LLCORNER);
mvwaddch(juego, y + 10, x + 1, ACS_HLINE);
mvwaddch(juego, y + 10, x + 2, ACS_HLINE);
mvwaddch(juego, y + 9, x + 2, '_');
mvwaddch(juego, y + 9, x + 3, ACS_VLINE);
mvwaddch(juego, y + 10, x + 3, ACS_BTEE);
mvwaddch(juego, y + 9, x + 4, '_');
mvwaddch(juego, y + 10, x + 5, '_');
mvwaddch(juego, y + 10, x + 4, ACS_HLINE);
mvwaddch(juego, y + 10, x + 5, ACS_HLINE);
mvwaddch(juego, y + 10, x + 6, ACS_LRCORNER);


        //parte izquierda del escudo
        mvwaddch(juego, y + 4, x - 2, ACS_HLINE);
        mvwaddch(juego, y + 4, x - 1, ACS_HLINE);
        mvwaddch(juego, y + 4, x - 3, ACS_HLINE);
        mvwaddch(juego, y + 4, x - 4, ACS_ULCORNER);
        mvwaddch(juego, y + 4, x , ACS_HLINE);
        mvwaddch(juego, y + 4, x + 1 , ACS_URCORNER);

        //parte derecha del escudo
        mvwaddch(juego, y + 5, x + 1 , ACS_VLINE);
        mvwaddch(juego, y + 6, x + 1 , ACS_VLINE);
        mvwaddch(juego, y + 7, x + 1 , '/');

        //parte izquierda del escudo
        mvwaddch(juego, y + 5, x - 4, ACS_VLINE);
        mvwaddch(juego, y + 6, x - 4 , ACS_VLINE);
        mvwaddch(juego, y + 7, x - 4 , '\\');

        //parte derecha del escudo
        mvwaddch(juego, y + 7, x , ACS_HLINE);
        mvwaddch(juego, y + 7 ,x - 2, ACS_HLINE);
        mvwaddch(juego, y + 7, x - 1, ACS_HLINE);
        mvwaddch(juego, y + 7, x - 3, ACS_HLINE);

        //cuadro del centro
        mvwaddch(juego,  y + 5, x - 1, ACS_DIAMOND);
        mvwaddch(juego,  y + 5, x - 2, ACS_DIAMOND);
        mvwaddch(juego,  y + 6, x - 1, ACS_DIAMOND);
        mvwaddch(juego,  y + 6, x - 2, ACS_DIAMOND);

    }
