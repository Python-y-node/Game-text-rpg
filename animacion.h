#include <iostream>
#include <ncurses.h>

#include "loader/loader.h"

using namespace std;



// Declaración de la función basePlayer
void basePlayer(WINDOW*juego, int  y, int x, bool hasSword, bool hasShield);
void Player(WINDOW*juego, int initialPositionY, int initialPositionX, string typePlayer, bool hasSword, bool hasShield);
void removePlayer(WINDOW*juego, int y, int x, bool hasSword, bool hasShield);


void basePlayer(WINDOW *juego, int y, int x, bool hasSword, bool hasShield) {
    // Dibuja un personaje con detalles
    // Sombrero o casco
    mvwaddch(juego, y, x, ACS_ULCORNER);
    mvwaddch(juego, y, x + 1, ACS_HLINE);
    mvwaddch(juego, y, x + 2, ACS_HLINE);
    mvwaddch(juego, y, x + 3, ACS_HLINE);
    mvwaddch(juego, y, x + 4, ACS_HLINE);
    mvwaddch(juego, y, x + 5, ACS_URCORNER);
    mvwaddch(juego, y + 1, x - 1, ACS_LLCORNER);
    mvwaddch(juego, y + 1, x, ACS_HLINE);
    mvwaddch(juego, y + 1, x + 1, ACS_HLINE);
    mvwaddch(juego, y + 1, x + 2, ACS_HLINE);
    mvwaddch(juego, y + 1, x + 3, ACS_HLINE);
    mvwaddch(juego, y + 1, x + 4, ACS_HLINE);
    mvwaddch(juego, y + 1, x + 5, ACS_HLINE);
    mvwaddch(juego, y + 1, x + 6, ACS_LRCORNER);

    // Cabeza
    mvwaddch(juego, y + 2, x, ACS_VLINE);

    // Boca
    mvwaddch(juego, y + 2, x + 3, '_');

    mvwaddch(juego, y + 2, x + 5, ACS_VLINE);

    // Barbilla
    mvwaddch(juego, y + 3, x, ACS_LLCORNER);
    mvwaddch(juego, y + 3, x + 5, ACS_LRCORNER);

    // Cuerpo
    mvwaddch(juego, y + 3, x + 6, ACS_HLINE);
    mvwaddch(juego, y + 3, x - 1, ACS_HLINE);
    mvwaddch(juego, y + 5, x, ACS_LLCORNER);
    mvwaddch(juego, y + 5, x + 1, ACS_HLINE);
    mvwaddch(juego, y + 5, x + 2, ACS_HLINE);
    mvwaddch(juego, y + 5, x + 3, ACS_HLINE);
    mvwaddch(juego, y + 5, x + 4, ACS_HLINE);
    mvwaddch(juego, y + 5, x + 5, ACS_LRCORNER);

    
    // Brazo derecho
    mvwaddch(juego, y + 4, x + 5, ACS_VLINE);
    mvwaddch(juego, y + 4, x + 7, ACS_VLINE);
    mvwaddch(juego, y + 5, x + 7, ACS_LRCORNER);
        // Brazo izquierdo
    mvwaddch(juego, y + 4, x - 2, ACS_VLINE);
    mvwaddch(juego, y + 4, x, ACS_VLINE);
    mvwaddch(juego, y + 5, x - 2, ACS_HLINE);

    // Piernas
    mvwaddch(juego, y + 6, x, ACS_VLINE);
    mvwaddch(juego, y + 6, x + 5, ACS_VLINE);
    mvwaddch(juego, y + 7, x, ACS_VLINE);
    mvwaddch(juego, y + 7, x + 5, ACS_VLINE);

    mvwaddch(juego, y + 8, x, ACS_LLCORNER);
    mvwaddch(juego, y + 8, x + 1, ACS_HLINE);
    mvwaddch(juego, y + 8, x + 2, ACS_HLINE);
    mvwaddch(juego, y + 7, x + 2, '_');
    mvwaddch(juego, y + 7, x + 3, ACS_VLINE);
    mvwaddch(juego, y + 8, x + 3, ACS_BTEE);
    mvwaddch(juego, y + 7, x + 4, '_');
    mvwaddch(juego, y + 8, x + 5, '_');
    mvwaddch(juego, y + 8, x + 4, ACS_HLINE);
    mvwaddch(juego, y + 8, x + 5, ACS_HLINE);
    mvwaddch(juego, y + 8, x + 6, ACS_LRCORNER);

    // Ojos
    mvwaddch(juego, y + 2, x + 2, '0');
    mvwaddch(juego, y + 2, x + 4, '0');

    // Si tiene espada
    if (hasSword) {
        // Dibuja una espada en la mano derecha
        mvwaddch(juego, y + 3, x + 7, ACS_VLINE);
        mvwaddch(juego, y + 2, x + 7, ACS_VLINE);
        mvwaddch(juego, y + 1, x + 7, ACS_VLINE);
        mvwaddch(juego, y, x + 7, ACS_UARROW);
    }

    // Si tiene escudo
    if (hasShield) {
        // Dibuja un escudo en el brazo izquierdo
        mvwaddch(juego, y + 4, x - 3, ACS_DIAMOND);
        mvwaddch(juego, y + 5, x - 3, ACS_VLINE);
        mvwaddch(juego, y + 6, x - 3, ACS_LLCORNER);
    }
}

void removePlayer(WINDOW*juego, int y, int x, bool hasSword, bool hasShield)
{

    // Sombrero o casco
    mvwaddch(juego, y, x, ' ');
    mvwaddch(juego, y, x + 1, ' ');
    mvwaddch(juego, y, x + 2, ' ');
    mvwaddch(juego, y, x + 3, ' ');
    mvwaddch(juego, y, x + 4, ' ');
    mvwaddch(juego, y, x + 5, ' ');
    mvwaddch(juego, y + 1, x - 1, ' ');
    mvwaddch(juego, y + 1, x, ' ');
    mvwaddch(juego, y + 1, x + 1, ' ');
    mvwaddch(juego, y + 1, x + 2, ' ');
    mvwaddch(juego, y + 1, x + 3, ' ');
    mvwaddch(juego, y + 1, x + 4, ' ');
    mvwaddch(juego, y + 1, x + 5, ' ');
    mvwaddch(juego, y + 1, x + 6, ' ');

    // Cabeza
    mvwaddch(juego, y + 2, x, ' ');

    // boca
    mvwaddch(juego, y + 2, x + 3, '_');

    mvwaddch(juego, y + 2, x + 5, ' ');

    // barbilla
    mvwaddch(juego, y + 3, x, ' ');
    mvwaddch(juego, y + 3, x + 5, ' ');

    // cuerpo
    mvwaddch(juego, y + 3, x + 6, ' ');
    mvwaddch(juego, y + 3, x - 1, ' ');
    mvwaddch(juego, y + 5, x, ' ');
    mvwaddch(juego, y + 5, x + 1, ' ');
    mvwaddch(juego, y + 5, x + 2, ' ');
    mvwaddch(juego, y + 5, x + 3, ' ');
    mvwaddch(juego, y + 5, x + 4, ' ');
    mvwaddch(juego, y + 5, x + 5, ' ');

    // Brazo izquierdo
    mvwaddch(juego, y + 4, x - 2, ' ');
    mvwaddch(juego, y + 4, x, ' ');
    mvwaddch(juego, y + 5, x - 2, ' ');
    // Brazo derecho
    mvwaddch(juego, y + 4, x + 5, ' ');
    mvwaddch(juego, y + 4, x + 7, ' ');
    mvwaddch(juego, y + 5, x + 7, ' ');

    // piernas
    mvwaddch(juego, y + 6, x, ' ');
    mvwaddch(juego, y + 6, x + 5, ' ');
    mvwaddch(juego, y + 7, x, ' ');
    mvwaddch(juego, y + 7, x + 5, ' ');

    mvwaddch(juego, y + 8, x, ' ');
    mvwaddch(juego, y + 8, x + 1, ' ');
    mvwaddch(juego, y + 8, x + 2, ' ');
    mvwaddch(juego, y + 7, x + 2, '_');
    mvwaddch(juego, y + 7, x + 2, '_');
    mvwaddch(juego, y + 7, x + 3, ' ');
    mvwaddch(juego, y + 8, x + 3, ' ');
    mvwaddch(juego, y + 7, x + 4, '_');
    mvwaddch(juego, y + 8, x + 5, '_');
    mvwaddch(juego, y + 8, x + 4, ' ');
    mvwaddch(juego, y + 8, x + 5, ' ');
    mvwaddch(juego, y + 8, x + 6, ' ');

    // ojos
    mvwaddch(juego, y + 2, x + 2, ' ');
    mvwaddch(juego, y + 2, x + 4, ' ');
}

void Player(WINDOW*juego, int initialPositionY, int initialPositionX, string typePlayer, bool hasSword, bool hasShield)
{

    int maxPosition = 70;
    int movents = 0;

    if (typePlayer == "static")
    {
        basePlayer(juego, initialPositionY, initialPositionX, hasSword, hasShield);
    }
    else if (typePlayer == "dinamic")
    {
        int key;
        while ((key = getch()) != 'q')
        {
            basePlayer(juego, initialPositionY, initialPositionX, hasSword, hasShield);
            switch (key)
            {
            case KEY_RIGHT:
                if (initialPositionX == maxPosition)
                {
                    break;
                }
                else
                {
                    removePlayer(juego, initialPositionY, initialPositionX - 1, hasSword, hasShield);
                    basePlayer(juego, initialPositionY, initialPositionX, hasSword, hasShield);
                    initialPositionX++;
                    refresh();
                }
                break;
            case KEY_LEFT:
                if (initialPositionX == 2)
                {
                    break;
                }
                else
                {
                    removePlayer(juego, initialPositionY, initialPositionX + 1, hasSword, hasShield);
                    basePlayer(juego, initialPositionY, initialPositionX, hasSword, hasShield);
                    initialPositionX--;
                    refresh();
                }
                break;
            default:
                break;
            }
            if( isMoving == false ){ break;}
        }
    }
}