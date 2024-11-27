#include "../loader/loader.h"
    // importacion de pantallas
#include "../screens/index.h"

void router(){

    initscr();             //  Inicializar ncurses
    noecho();                //No mostrar texto mientras se escribe
    curs_set(0);            // Ocultar el cursor
    start_color();
    curs_set(0);
    cbreak();


    while (routerMenu >= 0)
    {
        if( routerMenu == 0 ){
            clear();
            refresh();
            menuScreen();
        }
        if( routerMenu == 1 ){
            clear();
            refresh();
            loginUserScreen();
        }
        if( routerMenu == 2 ){
            clear();
            refresh();
            homeScreen();
        }
        if( routerMenu == 3 ){
            clear();
            refresh();
            homeScreen();
        }
        if( routerMenu == 4 ){
            clear();
            refresh();
            storyStartScreen();
        }
        if( routerMenu == 5 ){
            clear();
            refresh();
            menuGameScreen();
        }
        if( routerMenu == 6){
            if(passedWithBlacksmith == true){
                clear();
                refresh();
                errorScreen();
            }
            else {
                clear();
                refresh();
                blackSmithScreen();
            }
        }
        if( routerMenu == 7){
            if( passedWithWizard == true ){
                clear();
                refresh();
                errorScreen();
            }
            else{
                clear();
                refresh();
                wizardScreen();
            }
        }
        if( routerMenu == 8){
            clear();
            refresh();
            trollBridgeScreen();
        }
        if( routerMenu == 9){
            clear();
            refresh();
            finalFightScreen();
        }
         if( routerMenu == 10){
            clear();
            refresh();
            creditsScreen();
        }
    }
   

}