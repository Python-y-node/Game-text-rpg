#include "../loader/loader.h"

//importacion de pantallas
#include "../screens/index.h"

void router(){

    initscr();              // Inicializar ncurses
    noecho();               // No mostrar texto mientras se escribe
    curs_set(0);            // Ocultar el cursor
    start_color();
    curs_set(0);
    cbreak();

    // while (routerMenu >= 0)
    // {
    //     if( routerMenu == 0 ){
    //         clear();
    //         refresh();
    //         menuScreen();
    //     }

    //     if( routerMenu == 1 ){
    //         clear();
    //         refresh();
    //         loginUserScreen();
    //     }
    //     if( routerMenu == 2 ){
    //         createUserScreen();
    //     }
    //     if( routerMenu == 3 ){
    //         clear();
    //         refresh();
    //         homeScreen();
    //     }
    // }
    blackSmithScreen();
    
}