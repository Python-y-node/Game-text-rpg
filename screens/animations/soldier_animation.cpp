
#include <ncurses.h>
#include <iostream>

void soldier( int y, int x){

//  (O)
mvaddch( y, x + 2, 'O'); 

//  (/ \)
mvaddch( y + 1, x + 1, '/');
mvaddch( y + 1, x + 4, '\\');
mvaddch( y + 1 , x + 2, '|');

//  (/_____\)
mvaddch( y + 2, x, '/');
mvaddch( y + 2, x + 1, ' ');
mvaddch( y + 2, x + 2, '_');
mvaddch( y + 2, x + 3, '_');
mvaddch( y + 2, x + 4, '_');
mvaddch( y + 2, x + 5, '\\');
    
// Ojos
mvaddch( y + 3, x + 2, '0');
mvaddch( y + 3, x + 4, '0');
// cabeza
mvaddch( y + 4, x, ACS_LLCORNER);
mvaddch( y + 4, x + 5, ACS_LRCORNER);

// Body 
mvaddch( y + 5, x + 6, ACS_HLINE);
mvaddch( y + 5, x - 1, ACS_HLINE);
mvaddch( y + 7, x, ACS_LLCORNER);
mvaddch( y + 7, x + 1, ACS_HLINE);
mvaddch( y + 7, x + 2, ACS_HLINE);
mvaddch( y + 7, x + 3, ACS_HLINE);
mvaddch( y + 7, x + 4, ACS_HLINE);
mvaddch( y + 7, x + 5, ACS_LRCORNER);

// Legs (shifted down)
mvaddch( y + 8, x, ACS_VLINE);
mvaddch( y + 8, x + 5, ACS_VLINE);
mvaddch( y + 9, x, ACS_VLINE);
mvaddch( y + 9, x + 5, ACS_VLINE);

mvaddch( y + 10, x, ACS_LLCORNER);
mvaddch( y + 10, x + 1, ACS_HLINE);
mvaddch( y + 10, x + 2, ACS_HLINE);
mvaddch( y + 9, x + 2, '_');
mvaddch( y + 9, x + 3, ACS_VLINE);
mvaddch( y + 10, x + 3, ACS_BTEE);
mvaddch( y + 9, x + 4, '_');
mvaddch( y + 10, x + 5, '_');
mvaddch( y + 10, x + 4, ACS_HLINE);
mvaddch( y + 10, x + 5, ACS_HLINE);
mvaddch( y + 10, x + 6, ACS_LRCORNER);


        //parte izquierda del escudo
        mvaddch( y + 4, x - 2, ACS_HLINE);
        mvaddch( y + 4, x - 1, ACS_HLINE);
        mvaddch( y + 4, x - 3, ACS_HLINE);
        mvaddch( y + 4, x - 4, ACS_ULCORNER);
        mvaddch( y + 4, x , ACS_HLINE);
        mvaddch( y + 4, x + 1 , ACS_URCORNER);

        //parte derecha del escudo
        mvaddch( y + 5, x + 1 , ACS_VLINE);
        mvaddch( y + 6, x + 1 , ACS_VLINE);
        mvaddch( y + 7, x + 1 , '/');

        //parte izquierda del escudo
        mvaddch( y + 5, x - 4, ACS_VLINE);
        mvaddch( y + 6, x - 4 , ACS_VLINE);
        mvaddch( y + 7, x - 4 , '\\');

        //parte derecha del escudo
        mvaddch( y + 7, x , ACS_HLINE);
        mvaddch( y + 7 ,x - 2, ACS_HLINE);
        mvaddch( y + 7, x - 1, ACS_HLINE);
        mvaddch( y + 7, x - 3, ACS_HLINE);

        //cuadro del centro
        mvaddch(  y + 5, x - 1, ACS_DIAMOND);
        mvaddch(  y + 5, x - 2, ACS_DIAMOND);
        mvaddch(  y + 6, x - 1, ACS_DIAMOND);
        mvaddch(  y + 6, x - 2, ACS_DIAMOND);
        //espada
        mvaddch( y + 5, x + 7, ' ');
        mvaddch( y + 4, x + 8, ACS_URCORNER);
        mvaddch( y + 5, x + 7, ACS_HLINE);
        mvaddch( y + 5, x + 8, ACS_HLINE);
        mvaddch( y + 5, x + 9, ACS_LRCORNER);

        //mango
        mvaddch(  y + 4, x + 8, ACS_URCORNER );
        mvaddch(  y + 4, x + 9, ACS_ULCORNER );

    
            mvaddch(  y + 3, x + 8, ACS_VLINE );
            mvaddch(  y + 2, x + 8, ACS_VLINE );
            mvaddch(  y + 1, x + 8, ACS_VLINE );
            mvaddch(  y , x + 8, ACS_ULCORNER );
            //filo derecho
            mvaddch(  y + 3, x + 9, ACS_VLINE );
            mvaddch(  y + 2, x + 9, ACS_VLINE );
            mvaddch(  y + 1, x + 9, ACS_VLINE );
            mvaddch(  y , x + 9, ACS_URCORNER );
       
    }
