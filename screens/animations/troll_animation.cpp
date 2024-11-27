
#include <ncurses.h>
#include <iostream>


    void trollAnimation( int y, int x) {
    
    // cabeza
    mvaddch(y, x + 2, ACS_ULCORNER);
    mvaddch(y, x + 4, ACS_HLINE);
    mvaddch(y, x + 5, ACS_HLINE);
    mvaddch(y, x + 6, ACS_HLINE);
    mvaddch(y + 1, x + 1, ACS_VLINE);
    mvaddch(y + 1, x + 8, ACS_VLINE);
    mvaddch(y + 2, x, ACS_LLCORNER);
    mvaddch(y + 2, x + 9, ACS_LRCORNER);

    // cejas enojado
    mvaddch(y, x + 3, '\\'); 
    mvaddch(y, x + 7, '/');  

    // ojos
    mvaddch(y + 1, x + 3, 'O');
    mvaddch(y + 1, x + 7, 'O');

    //nariz
     mvaddch(y + 1, x + 4, ACS_ULCORNER);   
    mvaddch(y + 1, x + 5, ACS_HLINE);      
    mvaddch(y + 1, x + 6, ACS_HLINE);     
    mvaddch(y + 1, x + 6, ACS_URCORNER);   
 

    mvaddch(y + 2, x + 1, ACS_LLCORNER);
    mvaddch(y + 2, x + 8, ACS_LRCORNER);

    // cuerpo
    mvaddch(y + 3, x + 1, ACS_VLINE);
    mvaddch(y + 3, x + 8, ACS_VLINE);
    mvaddch(y + 4, x, ACS_LLCORNER);
    mvaddch(y + 4, x + 9, ACS_LRCORNER);
    mvaddch(y + 4, x + 1, ACS_HLINE);
    mvaddch(y + 4, x + 2, ACS_HLINE);
    mvaddch(y + 4, x + 3, ACS_HLINE);
    mvaddch(y + 4, x + 4, ACS_HLINE);
    mvaddch(y + 4, x + 5, ACS_HLINE);
    mvaddch(y + 4, x + 6, ACS_HLINE);
    mvaddch(y + 4, x + 7, ACS_HLINE);
    mvaddch(y + 4, x + 8, ACS_HLINE);


    // Piernas
    mvaddch(y + 5, x + 2, ACS_VLINE);
    mvaddch(y + 5, x + 7, ACS_VLINE);
    mvaddch(y + 6, x + 1, ACS_LLCORNER);
    mvaddch(y + 6, x + 3, ACS_LRCORNER);
    mvaddch(y + 6, x + 6, ACS_LLCORNER);
    mvaddch(y + 6, x + 8, ACS_LRCORNER);

    // Brazos
    mvaddch(y + 3, x - 1, ACS_VLINE);
    mvaddch(y + 3, x + 10, ACS_VLINE);
    mvaddch(y + 4, x - 1, ACS_LLCORNER);
    mvaddch(y + 4, x + 10, ACS_LRCORNER);

    
}
