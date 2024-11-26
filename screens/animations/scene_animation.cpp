

#include <ncurses.h>

void drawTree(WINDOW *win,  int y, int x) {
    mvwprintw(win, y, x, "        ^");
    mvwprintw(win, y + 1, x, "       ^^^");
    mvwprintw(win, y + 2, x, "      ^^^^^");
    mvwprintw(win, y + 3, x, "     ^^^^^^^");
    mvwprintw(win, y + 4, x, "    ^^^^^^^^^");
    mvwprintw(win, y + 5, x, "   ^^^^^^^^^^^");
    mvwprintw(win, y + 6, x, "       |||");
    mvwprintw(win, y + 7, x, "       |||");
}

// Función para dibujar un castillo
void drawCastle(WINDOW *win,int y, int x) {

    // Dibuja un castillo con varias torres unidas
    mvwprintw(win, y, x, "        T~~            T~~");
    mvwprintw(win, y + 1, x, "        |              |");
    mvwprintw(win, y + 2, x, "       / \\            / \\");
    mvwprintw(win, y + 3, x, "      /   \\          /   \\");
    mvwprintw(win, y + 4, x, "     /     \\        /     \\");
    mvwprintw(win, y + 5, x, "    /_______\\      /_______\\");
    mvwprintw(win, y + 6, x, "    |       |      |       |");
    mvwprintw(win, y + 7, x, "    |  []   |      |  []   |");
    mvwprintw(win, y + 8, x, "    |       |      |       |");
    mvwprintw(win, y + 9, x, "    |_______|      |_______|");
    mvwprintw(win, y + 10, x, "    |   |   |      |   |   |");
    mvwprintw(win, y + 11, x, "    |   |   |      |   |   |");
    mvwprintw(win, y + 12, x, "    |___|___|      |___|___|");
}

// Función para dibujar una casa
void drawHouse( WINDOW *win, int y, int x) {
    mvwprintw(win, y, x, "      /\\" );
    mvwprintw(win, y + 1, x, "     /  \\" );
    mvwprintw(win, y + 2, x, "    /    \\" );
    mvwprintw(win, y + 3, x, "   /______\\" );
    mvwprintw(win, y + 4, x, "  |        |" );
    mvwprintw(win, y + 5, x, "  |  [] [] |" );
    mvwprintw(win, y + 6, x, "  |   __   |" );
    mvwprintw(win, y + 7, x, "  |__|__|__|" );
  
}
