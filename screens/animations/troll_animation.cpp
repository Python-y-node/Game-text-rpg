#include <ncurses.h>

void drawTroll(WINDOW *win, int y, int x)
{
    //Colores
    init_pair(10, COLOR_GREEN, COLOR_BLACK);
    init_pair(11, COLOR_RED, COLOR_BLACK);

    // Cuello y cuerpo
    wattron(win, COLOR_PAIR(2)); // Color para el cuerpo
    mvwprintw(win, 10, 90, "     /\\______/\\      ");
    mvwprintw(win, 11, 90, "     |  0  0   |       ");
    mvwprintw(win, 12, 90, "       |         |       ");
    mvwprintw(win, 13, 90, "     |_/\\/\\/\\__|    ");
    mvwprintw(win, 14, 90, "     |_________|       ");
    wattroff(win, COLOR_PAIR(2));

    // Piernas y pies
    wattron(win, COLOR_PAIR(3)); // Color para las piernas
    mvwprintw(win, 15, 90, "       |    |           ");
    mvwprintw(win, 16, 90, "     /       \\        ");
    mvwprintw(win, 17, 90, "    /         \\       ");
    mvwprintw(win, 18, 90, "   (           )      ");
    mvwprintw(win, 19, 90, "    \\_________/       ");
    wattroff(win, COLOR_PAIR(3));
}