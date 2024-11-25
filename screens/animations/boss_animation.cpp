#include <ncurses.h>

void Boss(WINDOW* window, int y, int x){

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
    
    wattron( window, A_BOLD);
        wattron( window, COLOR_PAIR(5));
            mvwprintw( window, y + 2, x, "   (0)   (0)");
            mvwprintw( window, y + 3, x, " /\\         /\\ ");
            mvwprintw( window, y + 4, x, "/__\\/\\___/\\/__\\ ");
        wattroff( window, COLOR_PAIR(5));


        wattron(window, COLOR_PAIR(1));
            mvwprintw( window, y, x, "  /\\_______/\\ ");
            mvwprintw( window, y + 1, x, "  |___   ___|");
            mvwprintw( window, y + 5, x, "\\_____________/");
            mvwprintw( window, y + 6, x-3, "/\\/____\\______/___\\/\\");
        wattroff(window, COLOR_PAIR(1));

        wattron( window, COLOR_PAIR(6));
            mvwprintw( window, y + 7, x-4, "( ` \\              / ' )");
            mvwprintw( window, y + 8, x-4, "( `  )____________(  ' )");
        wattroff( window, COLOR_PAIR(6));
    wattroff( window, A_BOLD);

}