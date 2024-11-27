#include <ncurses.h>
#include <iostream>


void drawTroll(WINDOW* win, int y, int x) {

    // cabeza
    mvwaddch(win, y, x + 2, ACS_ULCORNER);
    mvwaddch(win,y, x + 4, ACS_HLINE);
    mvwaddch(win,y, x + 5, ACS_HLINE);
    mvwaddch(win,y, x + 6, ACS_HLINE);
    mvwaddch(win,y + 1, x + 1, ACS_VLINE);
    mvwaddch(win,y + 1, x + 8, ACS_VLINE);
    mvwaddch(win,y + 2, x, ACS_LLCORNER);
    mvwaddch(win,y + 2, x + 9, ACS_LRCORNER);

    // cejas enojado
    mvwaddch(win,y, x + 3, '\\'); 
    mvwaddch(win,y, x + 7, '/');  

    // ojos
    mvwaddch(win,y + 1, x + 3, 'O');
    mvwaddch(win,y + 1, x + 7, 'O');

    //nariz
    mvwaddch(win,y + 1, x + 4, ACS_ULCORNER);   
    mvwaddch(win,y + 1, x + 5, ACS_HLINE);      
    mvwaddch(win,y + 1, x + 6, ACS_HLINE);     
    mvwaddch(win,y + 1, x + 6, ACS_URCORNER);   
 

    mvwaddch(win,y + 2, x + 1, ACS_LLCORNER);
    mvwaddch(win,y + 2, x + 8, ACS_LRCORNER);

    // cuerpo
    mvwaddch(win,y + 3, x + 1, ACS_VLINE);
    mvwaddch(win,y + 3, x + 8, ACS_VLINE);
    mvwaddch(win,y + 4, x, ACS_LLCORNER);
    mvwaddch(win,y + 4, x + 9, ACS_LRCORNER);
    mvwaddch(win,y + 4, x + 1, ACS_HLINE);
    mvwaddch(win,y + 4, x + 2, ACS_HLINE);
    mvwaddch(win,y + 4, x + 3, ACS_HLINE);
    mvwaddch(win,y + 4, x + 4, ACS_HLINE);
    mvwaddch(win,y + 4, x + 5, ACS_HLINE);
    mvwaddch(win,y + 4, x + 6, ACS_HLINE);
    mvwaddch(win,y + 4, x + 7, ACS_HLINE);
    mvwaddch(win,y + 4, x + 8, ACS_HLINE);


    // Piernas
    mvwaddch(win,y + 5, x + 2, ACS_VLINE);
    mvwaddch(win,y + 5, x + 7, ACS_VLINE);
    mvwaddch(win,y + 6, x + 1, ACS_LLCORNER);
    mvwaddch(win,y + 6, x + 3, ACS_LRCORNER);
    mvwaddch(win,y + 6, x + 6, ACS_LLCORNER);
    mvwaddch(win,y + 6, x + 8, ACS_LRCORNER);

    // Brazos
    mvwaddch(win,y + 3, x - 1, ACS_VLINE);
    mvwaddch(win,y + 3, x + 10, ACS_VLINE);
    mvwaddch(win,y + 4, x - 1, ACS_LLCORNER);
    mvwaddch(win,y + 4, x + 10, ACS_LRCORNER);

    
}
