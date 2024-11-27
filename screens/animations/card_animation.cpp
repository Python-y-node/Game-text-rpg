#include <iostream>
#include <ncurses.h>

using namespace std;

void cardAnimation(WINDOW*juego2, int y, int x);


void cardAnimation(WINDOW*juego2, int y, int x){
    // Parte izquierda del escudo
    mvwaddch(juego2, y + 4, x - 2, ACS_HLINE);
    mvwaddch(juego2, y + 4, x - 1, ACS_HLINE);
    mvwaddch(juego2, y + 4, x - 3, ACS_HLINE);
    mvwaddch(juego2, y + 4, x - 4, ACS_ULCORNER);
    mvwaddch(juego2, y + 4, x, ACS_HLINE);
    mvwaddch(juego2, y + 4, x + 1, ACS_URCORNER);

    // Parte derecha del escudo
    mvwaddch(juego2, y + 5, x + 1, ACS_VLINE);
    mvwaddch(juego2, y + 6, x + 1, ACS_VLINE);
    mvwaddch(juego2, y + 7, x + 1, ACS_LRCORNER);

    // Parte izquierda del escudo
    mvwaddch(juego2, y + 5, x - 4, ACS_VLINE);
    mvwaddch(juego2, y + 6, x - 4, ACS_VLINE);
    mvwaddch(juego2, y + 7, x - 4, ACS_LLCORNER);

    // Parte inferior del escudo
    mvwaddch(juego2, y + 7, x, ACS_HLINE);
    mvwaddch(juego2, y + 7, x - 2, ACS_HLINE);
    mvwaddch(juego2, y + 7, x - 1, ACS_HLINE);
    mvwaddch(juego2, y + 7, x - 3, ACS_HLINE);

    // Cuadro del centro (diamantes)
    mvwaddch(juego2, y + 5, x - 1, ACS_DIAMOND);
    mvwaddch(juego2, y + 5, x - 2, ACS_DIAMOND);
    mvwaddch(juego2, y + 6, x - 1, ACS_DIAMOND);
    mvwaddch(juego2, y + 6, x - 2, ACS_DIAMOND);
}
