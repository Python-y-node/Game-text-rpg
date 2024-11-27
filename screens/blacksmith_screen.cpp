#include <iostream>
#include <ctime>
#include <limits>
#include <ncurses.h>
#include "animations/index.h"

using namespace std;

int turnoHerrero(WINDOW*window, int herrero);

void deleteOptionMenu(WINDOW*window);
void showInstrucctions( WINDOW*window );
void showElectionMessage( WINDOW* window, int playerChoice, int blacksmithChoice );
void deleteElectionMessage( WINDOW* window, int playerChoice, int blacksmithChoice );
void showOptionMenu(WINDOW* window);

void blackSmithScreen()
{
    int jugador = 0, herrero = 0 ;
    int yMax, xMax;
    char intento;

    // Obtener dimensiones de la pantalla
    getmaxyx(stdscr, yMax, xMax);


    // Crear ventana emergente
    WINDOW *window = newwin(yMax, xMax, 0, 0);
    box(window, 0, 0);

    
    Player(window, 8, 8, "static", FALSE, FALSE);
    basePlayerNoHat(window, 7, 65);
    
    
    showInstrucctions(window); 
    showOptionMenu(window);

    wrefresh(window);
    
    int playersChoice;

    while(( playersChoice = wgetch(window)) != 113 ){
         herrero = turnoHerrero(window, herrero);
        
        if( playersChoice > 48 && playersChoice < 52){
            if (playersChoice == herrero) {
                
                wattron(window, COLOR_PAIR(7));
                mvwprintw(window, 7, 20, "'¡Es un empate! Juguemos otra vez.'");
                wattroff(window, COLOR_PAIR(7));
                deleteElectionMessage(window, playersChoice, herrero);
                wrefresh(window);

            } else {
                deleteOptionMenu(window);
                wrefresh(window);
                showElectionMessage(window, playersChoice, herrero); 
                wrefresh(window);
                break;
            }
        }else {
            deleteOptionMenu(window);
            mvwprintw(window, 7, 18, "Opcion invalida ingresa un numero entre 1 y 3.");
            wrefresh(window);
            this_thread::sleep_for( chrono::milliseconds(1000));
            showOptionMenu(window);
        }
       
    }
    wgetch(window);
    routerMenu = 4;

    // Finalizar ncurses
    endwin();
}



void showInstrucctions( WINDOW*window ){

    wattron(window, A_BOLD);

    init_pair(7, COLOR_CYAN, COLOR_BLACK); // Definir par, texto cyan fondo negro

    wattron(window, COLOR_PAIR(7));
       mvwprintw(window, 2, 10, "----------------------------------------------------");
       mvwprintw( window, 3, 10, "|");
       mvwprintw( window, 4, 10, "|");
       mvwprintw( window, 5, 10, "|");

       mvwprintw( window, 3, 11, "Bienvenido a mi tienda, enfrentate conmigo en un");
       mvwprintw( window, 4, 11, "window de piedra papel y tijera y consigue un escudo");
       mvwprintw( window, 5, 11 , "... solo si me ganas :D");
       mvwprintw( window, 3, 62, "|");
       mvwprintw( window, 4, 62, "|"); 
       mvwprintw( window, 5, 62, "|");      
       mvwprintw(window, 6, 10, "--------------------------------------------------");
       mvwprintw( window, 6, 60, "\\ |");
       mvwprintw( window, 7, 61, "\\|");
    wattroff(window, COLOR_PAIR(7));
   
}


void showOptionMenu(WINDOW* window){

        mvwprintw(window, 7, 18, "                                              ");
    // Mostrar opciones al jugador
        mvwprintw(window, 8, 20, "*********************************");
        mvwprintw(window, 9, 20, "Piedra - Papel - Tijera");
        mvwprintw(window, 10, 20, "*********************************");
        mvwprintw(window, 12, 20, "Elige tu opción:");
        mvwprintw(window, 14, 20, "Seleccione '1' para elegir Piedra");
        mvwprintw(window, 16, 20, "Seleccione '2' para elegir Papel");
        mvwprintw(window, 18, 20, "Seleccione '3' para elegir Tijera");
}

void deleteOptionMenu(WINDOW*window){
        mvwprintw(window, 8, 20, "                                 ");
        mvwprintw(window, 9, 20, "                       ");
        mvwprintw(window, 10, 20, "                                 ");
        mvwprintw(window, 12, 20, "                ");
        mvwprintw(window, 14, 20, "                                 ");
        mvwprintw(window, 16, 20, "                                ");
        mvwprintw(window, 18, 20, "                                 ");
}

void showElectionMessage( WINDOW* window, int playerChoice, int blacksmithChoice ){
        mvwprintw(window, 10, 20, "Has elegido: ");   
        switch (playerChoice) {
        case 1:
            mvwprintw(window, 11, 22, "Piedra");
            break;
        case 2:
            mvwprintw(window, 11, 22, "Papel");
            break;
        case 3:
            mvwprintw(window, 11, 22, "Tijera");
            break;
        }

        mvwprintw(window, 12, 20, "El Herrero eligió: ");
 
        switch ( blacksmithChoice )
        {
        case 1:
            mvwprintw(window, 13, 22, "Piedra");
            break;
        case 2:
            mvwprintw(window, 13, 22, "Papel");
            break;
        case 3:
            mvwprintw(window, 13, 22, "Tijera");
            break;
        }

        if ((playerChoice == 1 && blacksmithChoice == 3) || (playerChoice == 2 && blacksmithChoice == 1) || (playerChoice == 3 && blacksmithChoice == 2)) {
            
            wattron(window, COLOR_PAIR(7));
            mvwprintw(window, 8, 17, "'¡Rayos, me has vencido! Te he ");
            mvwprintw(window, 9,17, "otorgado un escudo.'");
            wattroff(window, COLOR_PAIR(7));
        } else {
            
            wattron(window, COLOR_PAIR(7));
            mvwprintw(window, 8, 17, "'¡Te he vencido esta vez... será a la");
            mvwprintw(window, 9,17, "  próxima. Buena suerte!'");
            wattroff(window, COLOR_PAIR(7));
        }

    
        mvwprintw(window, 15, 17, "Presiona cualquier tecla para continuar...");
        wrefresh(window);
}

void deleteElectionMessage( WINDOW* window, int playerChoice, int blacksmithChoice ){
        
        mvwprintw(window, 10, 20, "             ");   
       
        switch (playerChoice) {
        case 1:
            mvwprintw(window, 11, 22, "      ");
            break;
        case 2:
            mvwprintw(window, 11, 22, "     ");
            break;
        case 3:
            mvwprintw(window, 11, 22, "      ");
            break;
        }

        mvwprintw(window, 12, 20, "                   ");

        switch ( blacksmithChoice )
        {
        case 1:
            mvwprintw(window, 13, 22, "      ");
            break;
        case 2:
            mvwprintw(window, 13, 22, "     ");
            break;
        case 3:
            mvwprintw(window, 13, 22, "      ");
            break;
        }

        if ((playerChoice == 1 && blacksmithChoice == 3) || (playerChoice == 2 && blacksmithChoice == 1) || (playerChoice == 3 && blacksmithChoice == 2)) {

            mvwprintw(window, 8, 17, "                               ");
            mvwprintw(window, 9,17, "                    ");
          
        } else {
            
            mvwprintw(window, 8, 17, "                                     ");
            mvwprintw(window, 9,17, "                         ");
        }
}


int turnoHerrero(WINDOW*window, int herrero){

    // Generar la elección aleatoria del herrero (opción del programa)
    srand(time(0));
    herrero = rand() % 3 + 1; // Genera un número aleatorio entre 1 y 3

    return herrero;
}
