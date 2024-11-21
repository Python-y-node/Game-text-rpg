#include <iostream>
#include <ncurses.h>

using namespace std;



// Declaración de la función basePlayer
void basePlayer(int y, int x, bool hasSword, bool hasShield);
void Player(int initialPositionY, int initialPositionX, string typePlayer, bool hasSword, bool hasShield);
void removePlayer(int y, int x, bool hasSword, bool hasShield);

int m() {
    // Inicializar ncurses
    initscr();
    cbreak();      // Entrada sin esperar Enter
    noecho();      // No mostrar la entrada del usuario
    keypad(stdscr, TRUE); // Habilitar teclas especiales

    // Crear al jugador
    Player(0,0,"dinamic", FALSE, FALSE);

    // Esperar una tecla para salir
    getch();

    // Finalizar ncurses
    endwin();

    return 0;
}

void basePlayer(int y, int x, bool hasSword, bool hasShield) {
    // Dibuja un personaje con detalles
    // Sombrero o casco
    mvaddch(y, x, ACS_ULCORNER);
    mvaddch(y, x + 1, ACS_HLINE);
    mvaddch(y, x + 2, ACS_HLINE);
    mvaddch(y, x + 3, ACS_HLINE);
    mvaddch(y, x + 4, ACS_HLINE);
    mvaddch(y, x + 5, ACS_URCORNER);
    mvaddch(y + 1, x - 1, ACS_LLCORNER);
    mvaddch(y + 1, x, ACS_HLINE);
    mvaddch(y + 1, x + 1, ACS_HLINE);
    mvaddch(y + 1, x + 2, ACS_HLINE);
    mvaddch(y + 1, x + 3, ACS_HLINE);
    mvaddch(y + 1, x + 4, ACS_HLINE);
    mvaddch(y + 1, x + 5, ACS_HLINE);
    mvaddch(y + 1, x + 6, ACS_LRCORNER);

    // Cabeza
    mvaddch(y + 2, x, ACS_VLINE);

    // Boca
    mvaddch(y + 2, x + 3, '_');

    mvaddch(y + 2, x + 5, ACS_VLINE);

    // Barbilla
    mvaddch(y + 3, x, ACS_LLCORNER);
    mvaddch(y + 3, x + 5, ACS_LRCORNER);

    // Cuerpo
    mvaddch(y + 3, x + 6, ACS_HLINE);
    mvaddch(y + 3, x - 1, ACS_HLINE);
    mvaddch(y + 5, x, ACS_LLCORNER);
    mvaddch(y + 5, x + 1, ACS_HLINE);
    mvaddch(y + 5, x + 2, ACS_HLINE);
    mvaddch(y + 5, x + 3, ACS_HLINE);
    mvaddch(y + 5, x + 4, ACS_HLINE);
    mvaddch(y + 5, x + 5, ACS_LRCORNER);

    

    // Brazo derecho
    mvaddch(y + 4, x + 5, ACS_VLINE);
    mvaddch(y + 4, x + 7, ACS_VLINE);
    mvaddch(y + 5, x + 7, ACS_LRCORNER);

    // Piernas
    mvaddch(y + 6, x, ACS_VLINE);
    mvaddch(y + 6, x + 5, ACS_VLINE);
    mvaddch(y + 7, x, ACS_VLINE);
    mvaddch(y + 7, x + 5, ACS_VLINE);

    mvaddch(y + 8, x, ACS_LLCORNER);
    mvaddch(y + 8, x + 1, ACS_HLINE);
    mvaddch(y + 8, x + 2, ACS_HLINE);
    mvaddch(y + 7, x + 2, '_');
    mvaddch(y + 7, x + 3, ACS_VLINE);
    mvaddch(y + 8, x + 3, ACS_BTEE);
    mvaddch(y + 7, x + 4, '_');
    mvaddch(y + 8, x + 5, '_');
    mvaddch(y + 8, x + 4, ACS_HLINE);
    mvaddch(y + 8, x + 5, ACS_HLINE);
    mvaddch(y + 8, x + 6, ACS_LRCORNER);

    // Ojos
    mvaddch(y + 2, x + 2, '0');
    mvaddch(y + 2, x + 4, '0');

    // Si tiene espada
    if (hasSword) {
        // Dibuja una espada en la mano derecha
        mvaddch(y + 3, x + 7, ACS_VLINE);
        mvaddch(y + 2, x + 7, ACS_VLINE);
        mvaddch(y + 1, x + 7, ACS_VLINE);
        mvaddch(y, x + 7, ACS_UARROW);
    }

    // Si tiene escudo
    if (hasShield) {
        // Dibuja un escudo en el brazo izquierdo
        mvaddch(y + 4, x - 3, ACS_DIAMOND);
        mvaddch(y + 5, x - 3, ACS_VLINE);
        mvaddch(y + 6, x - 3, ACS_LLCORNER);
    }
}

void removePlayer(int y, int x, bool hasSword, bool hasShield)
{

    // Sombrero o casco
    mvaddch(y, x, ' ');
    mvaddch(y, x + 1, ' ');
    mvaddch(y, x + 2, ' ');
    mvaddch(y, x + 3, ' ');
    mvaddch(y, x + 4, ' ');
    mvaddch(y, x + 5, ' ');
    mvaddch(y + 1, x - 1, ' ');
    mvaddch(y + 1, x, ' ');
    mvaddch(y + 1, x + 1, ' ');
    mvaddch(y + 1, x + 2, ' ');
    mvaddch(y + 1, x + 3, ' ');
    mvaddch(y + 1, x + 4, ' ');
    mvaddch(y + 1, x + 5, ' ');
    mvaddch(y + 1, x + 6, ' ');

    // Cabeza
    mvaddch(y + 2, x, ' ');

    // boca
    mvaddch(y + 2, x + 3, '_');

    mvaddch(y + 2, x + 5, ' ');

    // barbilla
    mvaddch(y + 3, x, ' ');
    mvaddch(y + 3, x + 5, ' ');

    // cuerpo
    mvaddch(y + 3, x + 6, ' ');
    mvaddch(y + 3, x - 1, ' ');
    mvaddch(y + 5, x, ' ');
    mvaddch(y + 5, x + 1, ' ');
    mvaddch(y + 5, x + 2, ' ');
    mvaddch(y + 5, x + 3, ' ');
    mvaddch(y + 5, x + 4, ' ');
    mvaddch(y + 5, x + 5, ' ');

    // Brazo izquierdo
    mvaddch(y + 4, x - 2, ' ');
    mvaddch(y + 4, x, ' ');
    mvaddch(y + 5, x - 2, ' ');
    // Brazo derecho
    mvaddch(y + 4, x + 5, ' ');
    mvaddch(y + 4, x + 7, ' ');
    mvaddch(y + 5, x + 7, ' ');

    // piernas
    mvaddch(y + 6, x, ' ');
    mvaddch(y + 6, x + 5, ' ');
    mvaddch(y + 7, x, ' ');
    mvaddch(y + 7, x + 5, ' ');

    mvaddch(y + 8, x, ' ');
    mvaddch(y + 8, x + 1, ' ');
    mvaddch(y + 8, x + 2, ' ');
    mvaddch(y + 7, x + 2, '_');
    mvaddch(y + 7, x + 2, '_');
    mvaddch(y + 7, x + 3, ' ');
    mvaddch(y + 8, x + 3, ' ');
    mvaddch(y + 7, x + 4, '_');
    mvaddch(y + 8, x + 5, '_');
    mvaddch(y + 8, x + 4, ' ');
    mvaddch(y + 8, x + 5, ' ');
    mvaddch(y + 8, x + 6, ' ');

    // ojos
    mvaddch(y + 2, x + 2, ' ');
    mvaddch(y + 2, x + 4, ' ');
}

void Player(int initialPositionY, int initialPositionX, string typePlayer, bool hasSword, bool hasShield)
{

    int maxPosition = 70;
    int movents = 0;

    if (typePlayer == "static")
    {
        basePlayer(initialPositionY, initialPositionX, hasSword, hasShield);
    }
    else if (typePlayer == "dinamic")
    {
        int key;
        while ((key = getch()) != 'q')
        {
            basePlayer(initialPositionY, initialPositionX, hasSword, hasShield);
            switch (key)
            {
            case KEY_RIGHT:
                if (initialPositionX == maxPosition)
                {
                    break;
                }
                else
                {
                    removePlayer(initialPositionY, initialPositionX - 1, hasSword, hasShield);
                    basePlayer(initialPositionY, initialPositionX, hasSword, hasShield);
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
                    removePlayer(initialPositionY, initialPositionX + 1, hasSword, hasShield);
                    basePlayer(initialPositionY, initialPositionX, hasSword, hasShield);
                    initialPositionX--;
                    refresh();
                }
                break;
            default:
                break;
            }
        }
    }
}