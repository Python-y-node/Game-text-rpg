#include <ncurses.h>

void drawTroll(WINDOW *win, int y, int x)
{
    //Colores
    init_pair(10, COLOR_GREEN, COLOR_BLACK);
    init_pair(11, COLOR_RED, COLOR_BLACK);

    // Cuello y cuerpo
    wattron(win, COLOR_PAIR(2)); // Color para el cuerpo
    mvwprintw(win, y, x, "     /\\______/\\      ");
    mvwprintw(win, y + 1, x, "     |  0  0   |       ");
    mvwprintw(win, y + 2, x, "       |         |       ");
    mvwprintw(win, y + 3, x, "     |_/\\/\\/\\__|    ");
    mvwprintw(win, y + 4, x, "     |_________|       ");
    wattroff(win, COLOR_PAIR(2));

    // Piernas y pies
    wattron(win, COLOR_PAIR(3)); // Color para las piernas
    mvwprintw(win, y + 5, x, "       |    |           ");
    mvwprintw(win, y + 6, x, "     /       \\        ");
    mvwprintw(win, y + 7, x, "    /         \\       ");
    mvwprintw(win, y + 8, x, "   (           )      ");
    mvwprintw(win, y + 9, x, "    \\_________/       ");
    wattroff(win, COLOR_PAIR(3));
}