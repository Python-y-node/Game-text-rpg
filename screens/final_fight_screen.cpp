#include "animations/player_animation.cpp"



void finalFightScreen(){
    initscr(); 
    curs_set(0); 

    keypad(stdscr, TRUE);

    Player( 4, 8, "static", true, true); 

    Player( 4, 50, "static", true, true); 

    move( 15, 4 );
    printw("Espadazo(e) \t  Golpe normal \t  Lujuria \t Bola de fuejo");
    char options;

    while( ( options = getch() ) != 'q' ){
        switch (options)
        {
        case 'e':
            cout << "Ha dado espadazo" << endl;
            break;
        
        default:
            break;
        }
    }

    getch();

    endwin();
}