
#include <ncurses.h>
#include <iostream>

void soldier(WINDOW*startScreen, int y, int x){

//  (O)
mvwaddch(startScreen, y, x + 2, 'O'); 

//  (/ \)
mvwaddch(startScreen, y + 1, x + 1, '/');
mvwaddch(startScreen, y + 1, x + 4, '\\');
mvwaddch(startScreen, y + 1 , x + 2, '|');

//  (/_____\)
mvwaddch(startScreen, y + 2, x, '/');
mvwaddch(startScreen, y + 2, x + 1, ' ');
mvwaddch(startScreen, y + 2, x + 2, '_');
mvwaddch(startScreen, y + 2, x + 3, '_');
mvwaddch(startScreen, y + 2, x + 4, '_');
mvwaddch(startScreen, y + 2, x + 5, '\\');
    
// Ojos
mvwaddch(startScreen, y + 3, x + 2, '0');
mvwaddch(startScreen, y + 3, x + 4, '0');
// cabeza
mvwaddch(startScreen, y + 4, x, ACS_LLCORNER);
mvwaddch(startScreen, y + 4, x + 5, ACS_LRCORNER);

// Body 
mvwaddch(startScreen, y + 5, x + 6, ACS_HLINE);
mvwaddch(startScreen, y + 5, x - 1, ACS_HLINE);
mvwaddch(startScreen, y + 7, x, ACS_LLCORNER);
mvwaddch(startScreen, y + 7, x + 1, ACS_HLINE);
mvwaddch(startScreen, y + 7, x + 2, ACS_HLINE);
mvwaddch(startScreen, y + 7, x + 3, ACS_HLINE);
mvwaddch(startScreen, y + 7, x + 4, ACS_HLINE);
mvwaddch(startScreen, y + 7, x + 5, ACS_LRCORNER);

// Legs (shifted don)
mvwaddch(startScreen, y + 8, x, ACS_VLINE);
mvwaddch(startScreen, y + 8, x + 5, ACS_VLINE);
mvwaddch(startScreen, y + 9, x, ACS_VLINE);
mvwaddch(startScreen, y + 9, x + 5, ACS_VLINE);

mvwaddch(startScreen, y + 10, x, ACS_LLCORNER);
mvwaddch(startScreen, y + 10, x + 1, ACS_HLINE);
mvwaddch(startScreen, y + 10, x + 2, ACS_HLINE);
mvwaddch(startScreen, y + 9, x + 2, '_');
mvwaddch(startScreen, y + 9, x + 3, ACS_VLINE);
mvwaddch(startScreen, y + 10, x + 3, ACS_BTEE);
mvwaddch(startScreen, y + 9, x + 4, '_');
mvwaddch(startScreen, y + 10, x + 5, '_');
mvwaddch(startScreen, y + 10, x + 4, ACS_HLINE);
mvwaddch(startScreen, y + 10, x + 5, ACS_HLINE);
mvwaddch(startScreen, y + 10, x + 6, ACS_LRCORNER);


        //parte izquierda del escudo
        mvwaddch(startScreen, y + 4, x - 2, ACS_HLINE);
        mvwaddch(startScreen, y + 4, x - 1, ACS_HLINE);
        mvwaddch(startScreen, y + 4, x - 3, ACS_HLINE);
        mvwaddch(startScreen, y + 4, x - 4, ACS_ULCORNER);
        mvwaddch(startScreen, y + 4, x , ACS_HLINE);
        mvwaddch(startScreen, y + 4, x + 1 , ACS_URCORNER);

        //parte derecha del escudo
        mvwaddch(startScreen, y + 5, x + 1 , ACS_VLINE);
        mvwaddch(startScreen, y + 6, x + 1 , ACS_VLINE);
        mvwaddch(startScreen, y + 7, x + 1 , '/');

        //parte izquierda del escudo
        mvwaddch(startScreen, y + 5, x - 4, ACS_VLINE);
        mvwaddch(startScreen, y + 6, x - 4 , ACS_VLINE);
        mvwaddch(startScreen, y + 7, x - 4 , '\\');

        //parte derecha del escudo
        mvwaddch(startScreen, y + 7, x , ACS_HLINE);
        mvwaddch(startScreen, y + 7 ,x - 2, ACS_HLINE);
        mvwaddch(startScreen, y + 7, x - 1, ACS_HLINE);
        mvwaddch(startScreen, y + 7, x - 3, ACS_HLINE);

        //cuadro del centro
        mvwaddch(startScreen, y + 5, x - 1, ACS_DIAMOND);
        mvwaddch(startScreen, y + 5, x - 2, ACS_DIAMOND);
        mvwaddch(startScreen, y + 6, x - 1, ACS_DIAMOND);
        mvwaddch(startScreen, y + 6, x - 2, ACS_DIAMOND);
        //espada
        mvwaddch(startScreen, y + 5, x + 7, ' ');
        mvwaddch(startScreen, y + 4, x + 8, ACS_URCORNER);
        mvwaddch(startScreen, y + 5, x + 7, ACS_HLINE);
        mvwaddch(startScreen, y + 5, x + 8, ACS_HLINE);
        mvwaddch(startScreen, y + 5, x + 9, ACS_LRCORNER);

        //mango
        mvwaddch(startScreen, y + 4, x + 8, ACS_URCORNER );
        mvwaddch(startScreen, y + 4, x + 9, ACS_ULCORNER );

    
            mvwaddch(startScreen, y + 3, x + 8, ACS_VLINE );
            mvwaddch(startScreen, y + 2, x + 8, ACS_VLINE );
            mvwaddch(startScreen, y + 1, x + 8, ACS_VLINE );
            mvwaddch(startScreen, y , x + 8, ACS_ULCORNER );
            //filo derecho
            mvwaddch(startScreen,  y + 3, x + 9, ACS_VLINE );
            mvwaddch(startScreen, y + 2, x + 9, ACS_VLINE );
            mvwaddch(startScreen,  y + 1, x + 9, ACS_VLINE );
            mvwaddch(startScreen, y , x + 9, ACS_URCORNER );
       
    }
