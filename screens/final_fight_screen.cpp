#include "animations/index.h"

void finalFightScreen(){
    initscr(); 
    curs_set(0); 

    keypad(stdscr, TRUE);

    Player( 4, 8, "static", true, true); 

    Player( 4, 50, "static", true, true); 

    move( 15, 4 );
    printw("Espadazo(e) \t Bola de fuejo(f)");
    char options;

    move(18, 4);
    while( ( options = getch() ) != 'q' ){
        switch (options)
        {
        case 'e':
            swordStroke();
            Player( 4, 50, "static", true, true);
            refresh();
            break;
        case 'f':
            fireBall();
            Player( 4, 50, "static", true, true);
            refresh();
            break;
        
        default:
            break;
        }
        refresh();
    }

    endwin();
}