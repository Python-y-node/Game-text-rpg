#include <ncurses.h>

void drawTroll(WINDOW *win, int y, int x)
{
    mvwprintw(win, y, x,     "      @@@@@@@");
    mvwprintw(win, y + 1, x, "     @       @");
    mvwprintw(win, y + 2, x, "    @  O   O  @");
    mvwprintw(win, y + 3, x, "    @    ^    @");
    mvwprintw(win, y + 4, x, "     @  '-'  @");
    mvwprintw(win, y + 5, x, "      @@@@@@@");
    mvwprintw(win, y + 6, x, "       || ||");
    mvwprintw(win, y + 7, x, "     // | | \\\\");
    mvwprintw(win, y + 8, x, "    //  | |  \\\\");
    mvwprintw(win, y + 9, x, "   ||   | |   ||");
    mvwprintw(win, y + 10, x,"    \\\\  | |  //");
    mvwprintw(win, y + 11, x,"     \\\\_|_|_//");
    mvwprintw(win, y + 12, x,"      /     \\");
    mvwprintw(win, y + 13, x,"     |       |");
    mvwprintw(win, y + 14, x,"     |  ---  |");
    mvwprintw(win, y + 15, x,"     |_______|");
}