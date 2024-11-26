#include <iostream>
#include <ncurses.h>

using namespace std;

void basePlayerNoHat(int y, int x);

int mai() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Draw the character without a hat and with a mustache
    basePlayerNoHat(10, 90);

    refresh();
    getch();
    endwin();

    return 0;
}

void basePlayerNoHat(int y, int x) {

   // Head
mvaddch(y, x, ACS_ULCORNER);
mvaddch(y, x + 1, ACS_HLINE);
mvaddch(y, x + 2, ACS_HLINE);
mvaddch(y, x + 3, ACS_HLINE);
mvaddch(y, x + 4, ACS_HLINE);
mvaddch(y, x + 5, ACS_URCORNER);

mvaddch(y + 1, x, ACS_VLINE);
mvaddch(y + 1, x + 5, ACS_VLINE);

// Unibrow (line above the eyes)
mvaddch(y + 1, x + 1, ACS_HLINE);  // Start of the unibrow
mvaddch(y + 1, x + 2, ACS_HLINE);
mvaddch(y + 1, x + 3, ACS_HLINE);
mvaddch(y + 1, x + 4, ACS_HLINE);

// Eyes
mvaddch(y + 2, x + 2, '0');
mvaddch(y + 2, x + 4, '0');

// Mustache (moved to row y + 3)
mvaddch(y + 3, x + 1, ACS_HLINE);
mvaddch(y + 3, x + 2, ACS_HLINE);
mvaddch(y + 3, x + 3, '_');
mvaddch(y + 3, x + 4, ACS_HLINE);
mvaddch(y + 3, x + 5, ACS_HLINE);

// Chin
mvaddch(y + 4, x, ACS_LLCORNER);
mvaddch(y + 4, x + 5, ACS_LRCORNER);

// Body (Shifted body down)
mvaddch(y + 5, x + 6, ACS_HLINE);
mvaddch(y + 5, x - 1, ACS_HLINE);
mvaddch(y + 7, x, ACS_LLCORNER);
mvaddch(y + 7, x + 1, ACS_HLINE);
mvaddch(y + 7, x + 2, ACS_HLINE);
mvaddch(y + 7, x + 3, ACS_HLINE);
mvaddch(y + 7, x + 4, ACS_HLINE);
mvaddch(y + 7, x + 5, ACS_LRCORNER);



// Right arm (shifted down)
mvaddch(y + 6, x + 5, ACS_VLINE);
mvaddch(y + 6, x + 7, ACS_VLINE);
mvaddch(y + 7, x + 7, ACS_LRCORNER);

// Legs (shifted down)
mvaddch(y + 8, x, ACS_VLINE);
mvaddch(y + 8, x + 5, ACS_VLINE);
mvaddch(y + 9, x, ACS_VLINE);
mvaddch(y + 9, x + 5, ACS_VLINE);

mvaddch(y + 10, x, ACS_LLCORNER);
mvaddch(y + 10, x + 1, ACS_HLINE);
mvaddch(y + 10, x + 2, ACS_HLINE);
mvaddch(y + 9, x + 2, '_');
mvaddch(y + 9, x + 3, ACS_VLINE);
mvaddch(y + 10, x + 3, ACS_BTEE);
mvaddch(y + 9, x + 4, '_');
mvaddch(y + 10, x + 5, '_');
mvaddch(y + 10, x + 4, ACS_HLINE);
mvaddch(y + 10, x + 5, ACS_HLINE);
mvaddch(y + 10, x + 6, ACS_LRCORNER);


        //parte izquierda del escudo
        mvaddch(y + 4, x - 2, ACS_HLINE);
        mvaddch(y + 4, x - 1, ACS_HLINE);
        mvaddch(y + 4, x - 3, ACS_HLINE);
        mvaddch(y + 4, x - 4, ACS_ULCORNER);
        mvaddch(y + 4, x , ACS_HLINE);
        mvaddch(y + 4, x + 1 , ACS_URCORNER);

        //parte derecha del escudo
        mvaddch(y + 5, x + 1 , ACS_VLINE);
        mvaddch(y + 6, x + 1 , ACS_VLINE);
        mvaddch(y + 7, x + 1 , '/');

        //parte izquierda del escudo
        mvaddch(y + 5, x - 4, ACS_VLINE);
        mvaddch(y + 6, x - 4 , ACS_VLINE);
        mvaddch(y + 7, x - 4 , '\\');

        //parte derecha del escudo
        mvaddch(y + 7, x , ACS_HLINE);
        mvaddch(y + 7 ,x - 2, ACS_HLINE);
        mvaddch(y + 7, x - 1, ACS_HLINE);
        mvaddch(y + 7, x - 3, ACS_HLINE);

        //cuadro del centro
        mvaddch( y + 5, x - 1, ACS_DIAMOND);
        mvaddch( y + 5, x - 2, ACS_DIAMOND);
        mvaddch( y + 6, x - 1, ACS_DIAMOND);
        mvaddch( y + 6, x - 2, ACS_DIAMOND);

    }
