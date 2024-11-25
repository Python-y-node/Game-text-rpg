#include "animations/index.h"

#include "../loader/loader.h"

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
       wattron( window, A_BOLD);
            drawTree(window, 5, 70);
            mvwprintw(window, 13, 10, "%d", playerMaxLife);
       wattroff( window, A_BOLD);
    wattroff( window, COLOR_PAIR(1));

    wattron(window, COLOR_PAIR(5));
       wattron( window, A_BOLD);
            mvwprintw(window, 13, 55, "%d", bossMaxLife);
       wattroff( window, A_BOLD);
    wattroff( window, COLOR_PAIR(5));

    mvwprintw(window, 15, 4, "Espadazo(e) \t Bola de fuejo(f)");

    char options;

    move(18, 4);
    while( ( options = wgetch(window) ) != 'q' ){
        
        switch (options)
        {
        case 'e':
            swordStroke(window);
            Boss( window, 3, 50);

                //cambiar la vida del final boss
                wattron(window, COLOR_PAIR(5));
                wattron( window, A_BOLD);
                        mvwprintw(window, 13, 55, "    ");
                        mvwprintw(window, 13, 55, "%d", bossMaxLife);
                wattroff( window, A_BOLD);
                wattroff( window, COLOR_PAIR(5));

            wrefresh(window);
            break;
        case 'f':
            fireBall(window);
            Boss( window, 3, 50);
            //cambiar la vida del final boss
                wattron(window, COLOR_PAIR(5));
                wattron( window, A_BOLD);
                        mvwprintw(window, 13, 55, "    ");
                        mvwprintw(window, 13, 55, "%d", bossMaxLife);
                wattroff( window, A_BOLD);
                wattroff( window, COLOR_PAIR(5));
            wrefresh(window);
            break;
        
        default:
            break;
        }
        std::this_thread::sleep_for( std::chrono::milliseconds(800));
        if ( options == 'f')  attackCursedArrows(window);
        else if(options == 'e') lavaBreathAttack(window); 

        Player( window, 4, 8, "static", true, true);

        //cambiar la vida del player
        wattron(window, COLOR_PAIR(1));
        wattron( window, A_BOLD);
                mvwprintw(window, 13, 10, "    ");
                mvwprintw(window, 13, 10, "%d", playerMaxLife);
        wattroff( window, A_BOLD);
        wattroff( window, COLOR_PAIR(1));

        Boss( window, 3, 50);
        wrefresh(window);
    }

    endwin();
}