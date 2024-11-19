#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <curses.h>
using namespace std;

// Función para dibujar un árbol
void draw_tree(int y, int x) {
    mvprintw(y, x, "        ^");
    mvprintw(y+1, x, "       ^^^");
    mvprintw(y+2, x, "      ^^^^^");
    mvprintw(y+3, x, "     ^^^^^^^");
    mvprintw(y+4, x, "    ^^^^^^^^^");
    mvprintw(y+5, x, "   ^^^^^^^^^^^");
    mvprintw(y+6, x, "      |||");
    mvprintw(y+7, x, "      |||");
}

// Función para dibujar un castillo
void draw_castle() {
    // Dibuja un castillo con varias torres unidas
    mvprintw(5, 10, "        T~~              T~~");
    mvprintw(6, 10, "        |                 |");
    mvprintw(7, 10, "       / \\               / \\");
    mvprintw(8, 10, "      /   \\             /   \\");
    mvprintw(9, 10, "     /     \\           /     \\");
    mvprintw(10, 10, "    /_______\\         /_______\\");
    mvprintw(11, 10, "    |       |         |       |");
    mvprintw(12, 10, "    |  []   |         |  []   |");
    mvprintw(13, 10, "    |       |         |       |");
    mvprintw(14, 10, "    |_______|         |_______|");
    mvprintw(15, 10, "    |   |   |         |   |   |");
    mvprintw(16, 10, "    |   |   |         |   |   |");
    mvprintw(17, 10, "    |   |   |         |   |   |");
    mvprintw(18, 10, "    |___|___|         |___|___|");
}

// Función para dibujar una casa
void draw_house(int y, int x) {
    mvprintw(y, x, "      /\\" );
    mvprintw(y+1, x, "     /  \\" );
    mvprintw(y+2, x, "    /    \\" );
    mvprintw(y+3, x, "   /______\\" );
    mvprintw(y+4, x, "  |        |" );
    mvprintw(y+5, x, "  |  [] [] |" );
    mvprintw(y+6, x, "  |   __   |" );
    mvprintw(y+7, x, "  |________|" );
    mvprintw(y+8, x, "    |  |" );
    mvprintw(y+9, x, "    |  |" );
    mvprintw(y+10, x, "    |__|");
}

int main(int argc, char const *argv[])
{
    // INICIA NCURSES
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // Posición base donde dibujaremos las tres estructuras
    int y = yMax / 4;  // Usamos la misma coordenada 'y' para todas

    // Posiciones horizontales para cada estructura
    int x_tree = xMax / 2;        // Árbol en la primera columna
    int x_castle = xMax / 8 - 20; // Castillo en el centro
    int x_house = xMax / 4 * 3;   // Casa en la última columna

    // Dibujar las tres estructuras
    draw_tree(y, x_tree);
    draw_castle();
    draw_house(y, x_house);

    // Espera a que el usuario presione una tecla antes de salir
    getch();

    // FINALIZA NCURSES
    endwin();
    return 0;
}

