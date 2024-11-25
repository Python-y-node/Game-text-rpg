#include "animations/index.h"

void finalFightScreen(){

    //Variables a las cuales se les dara el maximo de columnas y filas de la pantalla estandar
    int maxColumns, maxRows;
    //Esta funcion asigna a las variables el maximo de tamaño de columnas y filas de la pantalla estanda stdsrc
    getmaxyx(stdscr, maxColumns, maxRows);

    //Se crea una pantalla con los valores esta funcion recibe( tamaño de columnas, tamaño de filas, inicio en y, inicio en x )
    WINDOW* window = newwin( maxColumns, maxRows, 0, 0);
    //Le crea un marco a la ventana
    box(window, 0,0);
     
    Player( window, 4, 8, "static", true, true); 

    Boss( window, 3, 50);
    
    wattron(window, COLOR_PAIR(1));
       drawTree(window, 5, 70);
    wattroff( window, COLOR_PAIR(1));

    mvwprintw(window, 15, 4, "Espadazo(e) \t Bola de fuejo(f)");
    char options;

    move(18, 4);
    while( ( options = wgetch(window) ) != 'q' ){
        switch (options)
        {
        case 'e':
            swordStroke(window);
            Boss( window, 3, 50);
            wrefresh(window);
            break;
        case 'f':
            fireBall(window);
            Boss( window, 3, 50);
            wrefresh(window);
            break;
        
        default:
            break;
        }
        wrefresh(window);
    }

    endwin();
}