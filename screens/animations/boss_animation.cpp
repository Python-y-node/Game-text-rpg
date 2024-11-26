#include <ncurses.h>

void Boss(WINDOW* window, int y, int x){

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
    
    wattron( window, A_BOLD);
        wattron( window, COLOR_PAIR(5));
            mvwprintw( window, y + 2, x, "   (0)   (0)");
            mvwprintw( window, y + 3, x, " /\\         /\\ ");
            mvwprintw( window, y + 4, x, "/__\\/\\___/\\/__\\ ");
        wattroff( window, COLOR_PAIR(5));


        wattron(window, COLOR_PAIR(1));
            mvwprintw( window, y, x, "  /\\_______/\\ ");
            mvwprintw( window, y + 1, x, "  |___   ___|");
            mvwprintw( window, y + 5, x, "\\_____________/");
            mvwprintw( window, y + 6, x-3, "/\\/____\\______/___\\/\\");
        wattroff(window, COLOR_PAIR(1));

        wattron( window, COLOR_PAIR(6));
            mvwprintw( window, y + 7, x-4, "( ` \\              / ' )");
            mvwprintw( window, y + 8, x-4, "( `  )____________(  ' )");
        wattroff( window, COLOR_PAIR(6));
    wattroff( window, A_BOLD);

}


void cursedArrows(WINDOW* window, int y, int x){ 

    wattron( window, COLOR_PAIR(5));
    wattron( window, A_BOLD);
        //primera flecha
        mvwaddch( window, y, x, '-');
        mvwaddch( window, y, x - 1 , '-');
        mvwaddch( window, y, x - 2, '-');
        mvwaddch( window, y, x - 3, '-');
        mvwaddch( window, y, x - 4, '-');
        mvwaddch( window, y, x - 5, '<');
        mvwaddch( window, y, x - 6, '<');
        mvwaddch( window, y, x + 1, '<');

        //segunda flecha
        mvwaddch( window, y + 1, x, '-');
        mvwaddch( window, y + 1, x - 1 , '-');
        mvwaddch( window, y + 1, x - 2, '-');
        mvwaddch( window, y + 1, x - 3, '-');
        mvwaddch( window, y + 1, x - 4, '-');
        mvwaddch( window, y + 1, x - 5, '<');
        mvwaddch( window, y + 1, x - 6, '<');
        mvwaddch( window, y + 1, x + 1, '<');

        //tercera flecha
        mvwaddch( window, y + 2, x, '-');
        mvwaddch( window, y + 2, x - 1 , '-');
        mvwaddch( window, y + 2, x - 2, '-');
        mvwaddch( window, y + 2, x - 3, '-');
        mvwaddch( window, y + 2, x - 4, '-');
        mvwaddch( window, y + 2, x - 5, '<');
        mvwaddch( window, y + 2, x - 6, '<');
        mvwaddch( window, y + 2, x + 1, '<');

        //cuarta flecha
        mvwaddch( window, y + 3, x, '-');
        mvwaddch( window, y + 3, x - 1 , '-');
        mvwaddch( window, y + 3, x - 2, '-');
        mvwaddch( window, y + 3, x - 3, '-');
        mvwaddch( window, y + 3, x - 4, '-');
        mvwaddch( window, y + 3, x - 5, '<');
        mvwaddch( window, y + 3, x - 6, '<');
        mvwaddch( window, y + 3, x + 1, '<');
    wattroff( window, COLOR_PAIR(5));
    wattroff( window, A_BOLD);
}

void removeCursedArrows(WINDOW* window, int y, int x){
   //primera flecha
        mvwaddch( window, y, x, ' ');
        mvwaddch( window, y, x - 1 , ' ');
        mvwaddch( window, y, x - 2, ' ');
        mvwaddch( window, y, x - 3, ' ');
        mvwaddch( window, y, x - 4, ' ');
        mvwaddch( window, y, x - 5, ' ');
        mvwaddch( window, y, x - 6, ' ');
        mvwaddch( window, y, x + 1, ' ');

        //segunda flecha
        mvwaddch( window, y + 1, x, ' ');
        mvwaddch( window, y + 1, x - 1 , ' ');
        mvwaddch( window, y + 1, x - 2, ' ');
        mvwaddch( window, y + 1, x - 3, ' ');
        mvwaddch( window, y + 1, x - 4, ' ');
        mvwaddch( window, y + 1, x - 5, ' ');
        mvwaddch( window, y + 1, x - 6, ' ');
        mvwaddch( window, y + 1, x + 1, ' ');

        //tercera flecha
        mvwaddch( window, y + 2, x, ' ');
        mvwaddch( window, y + 2, x - 1 , ' ');
        mvwaddch( window, y + 2, x - 2, ' ');
        mvwaddch( window, y + 2, x - 3, ' ');
        mvwaddch( window, y + 2, x - 4, ' ');
        mvwaddch( window, y + 2, x - 5, ' ');
        mvwaddch( window, y + 2, x - 6, ' ');
        mvwaddch( window, y + 2, x + 1, ' ');

        //cuarta flecha
        mvwaddch( window, y + 3, x, ' ');
        mvwaddch( window, y + 3, x - 1 , ' ');
        mvwaddch( window, y + 3, x - 2, ' ');
        mvwaddch( window, y + 3, x - 3, ' ');
        mvwaddch( window, y + 3, x - 4, ' ');
        mvwaddch( window, y + 3, x - 5, ' ');
        mvwaddch( window, y + 3, x - 6, ' ');
        mvwaddch( window, y + 3, x + 1, ' ');
}

void attackCursedArrows( WINDOW* window){

    int initialPositonX = 45;
    int initialPositionY = 6;

    while( true ){
       
       cursedArrows( window, initialPositionY, initialPositonX );
       wrefresh(window);
       std::this_thread::sleep_for( std::chrono::milliseconds(80) );
       removeCursedArrows( window, initialPositionY, initialPositonX );
       wrefresh(window);
       initialPositonX--;

       if(initialPositonX == 10) break;

    }
    playerMaxLife = playerMaxLife - 300 ;
}

void lavaBreath(WINDOW* window, int y, int x){
    
    wattron( window, A_STANDOUT);
    wattron( window, COLOR_PAIR(5));
        mvwaddch(window, y + 2, x -1, ACS_DIAMOND );

        mvwaddch(window, y + 1, x , ACS_DIAMOND );
        mvwaddch(window, y + 2, x, ACS_DIAMOND );
        mvwaddch(window, y + 3, x, ACS_DIAMOND );
        mvwaddch(window, y + 4, x, ACS_DIAMOND );

        mvwaddch(window, y , x + 1, ACS_DIAMOND );
        mvwaddch(window,y + 1, x + 1, ACS_DIAMOND );
        mvwaddch(window, y + 2, x + 1, ACS_DIAMOND );
        mvwaddch(window, y + 3, x + 1, ACS_DIAMOND );
        mvwaddch(window, y + 4,x + 1, ACS_DIAMOND );

        mvwaddch(window, y,  x + 2, ACS_DIAMOND );
        mvwaddch(window,y + 1,  x + 2, ACS_DIAMOND );
        mvwaddch(window, y + 2,  x + 2, ACS_DIAMOND );
        mvwaddch(window, y + 3,  x + 2, ACS_DIAMOND );
        mvwaddch(window, y + 4, x + 2, ACS_DIAMOND );
        
        mvwaddch(window, y, x + 3, ACS_DIAMOND );
        mvwaddch(window,y + 1, x + 3, ACS_DIAMOND );
        mvwaddch(window, y + 2, x + 3, ACS_DIAMOND );
        mvwaddch(window, y + 3, x + 3, ACS_DIAMOND );
        mvwaddch(window, y + 4, x + 3, ACS_DIAMOND );

        mvwaddch(window, y, x + 4, ACS_DIAMOND );
        mvwaddch(window,y + 1, x + 4, ACS_DIAMOND );
        mvwaddch(window, y + 2, x + 4, ACS_DIAMOND );
        mvwaddch(window, y + 3, x + 4, ACS_DIAMOND );
        mvwaddch(window, y + 4, x + 4, ACS_DIAMOND );

        mvwaddch(window, y, x + 5, ACS_DIAMOND );
        mvwaddch(window,y + 1, x + 5, ACS_DIAMOND );
        mvwaddch(window, y + 2, x + 5, ACS_DIAMOND );
        mvwaddch(window, y + 3, x + 5, ACS_DIAMOND );
        mvwaddch(window, y + 4, x + 5, ACS_DIAMOND );

        mvwaddch(window, y, x + 6, ACS_DIAMOND );
        mvwaddch(window, y + 1, x + 6, ACS_DIAMOND );
        mvwaddch(window, y + 2, x + 6, ACS_DIAMOND );
        mvwaddch(window, y + 3, x + 6, ACS_DIAMOND );
        mvwaddch(window, y + 4, x + 6, ACS_DIAMOND );

        mvwaddch(window, y, x + 7, ACS_DIAMOND );
        mvwaddch(window, y + 1, x + 7, ACS_DIAMOND );
        mvwaddch(window, y + 2, x + 7, ACS_DIAMOND );
        mvwaddch(window, y + 3, x + 7, ACS_DIAMOND );
        mvwaddch(window, y + 4, x + 7, ACS_DIAMOND );

        mvwaddch(window, y, x + 8, ACS_DIAMOND );
        mvwaddch(window, y + 1, x + 8, ACS_DIAMOND );
        mvwaddch(window, y + 2, x + 8, ACS_DIAMOND );
        mvwaddch(window, y + 3, x + 8, ACS_DIAMOND );
        mvwaddch(window, y + 4, x + 8, ACS_DIAMOND );

        mvwaddch(window, y, x + 9, ACS_DIAMOND );
        mvwaddch(window, y + 1, x + 9, ACS_DIAMOND );
        mvwaddch(window, y + 2, x + 9, ACS_DIAMOND );
        mvwaddch(window, y + 3, x + 9, ACS_DIAMOND );
        mvwaddch(window, y + 4, x + 9, ACS_DIAMOND );

        mvwaddch(window, y, x + 10, ACS_DIAMOND );
        mvwaddch(window, y + 1, x + 10, ACS_DIAMOND );
        mvwaddch(window, y + 2, x + 10, ACS_DIAMOND );
        mvwaddch(window, y + 3, x + 10, ACS_DIAMOND );
        mvwaddch(window, y + 4, x + 10, ACS_DIAMOND );

    wattroff( window, A_STANDOUT);
    wattroff( window, COLOR_PAIR(5));
}

void removeLavaBreath(WINDOW* window, int y, int x){
     mvwaddch(window,  y + 2, x -1, ' ' );

    mvwaddch(window,  y + 1, x , ' ' );
    mvwaddch(window,  y + 2, x, ' ' );
    mvwaddch(window,  y + 3, x, ' ' );
    mvwaddch(window,  y + 4, x, ' ' );

    mvwaddch(window,  y , x + 1, ' ' );
    mvwaddch(window, y + 1, x + 1, ' ' );
    mvwaddch(window,  y + 2, x + 1, ' ' );
    mvwaddch(window,  y + 3, x + 1, ' ' );
    mvwaddch(window,  y + 4,x + 1, ' ' );

    mvwaddch(window,  y,  x + 2, ' ' );
    mvwaddch(window, y + 1,  x + 2, ' ' );
    mvwaddch(window,  y + 2,  x + 2, ' ' );
    mvwaddch(window,  y + 3,  x + 2, ' ' );
    mvwaddch(window,  y + 4, x + 2, ' ' );
    
    mvwaddch(window,  y, x + 3, ' ' );
    mvwaddch(window, y + 1, x + 3, ' ' );
    mvwaddch(window,  y + 2, x + 3, ' ' );
    mvwaddch(window,  y + 3, x + 3, ' ' );
    mvwaddch(window,  y + 4, x + 3, ' ' );

    mvwaddch(window,  y, x + 4, ' ' );
    mvwaddch(window, y + 1, x + 4, ' ' );
    mvwaddch(window,  y + 2, x + 4, ' ' );
    mvwaddch(window,  y + 3, x + 4, ' ' );
    mvwaddch(window,  y + 4, x + 4, ' ' );

    mvwaddch(window,  y, x + 5, ' ' );
    mvwaddch(window, y + 1, x + 5, ' ' );
    mvwaddch(window,  y + 2, x + 5, ' ' );
    mvwaddch(window,  y + 3, x + 5, ' ' );
    mvwaddch(window,  y + 4, x + 5, ' ' );

    mvwaddch(window,  y, x + 6, ' ' );
    mvwaddch(window,  y + 1, x + 6, ' ' );
    mvwaddch(window,  y + 2, x + 6, ' ' );
    mvwaddch(window,  y + 3, x + 6, ' ' );
    mvwaddch(window,  y + 4, x + 6, ' ' );

    mvwaddch(window,  y, x + 7, ' ' );
    mvwaddch(window, y + 1, x + 7, ' ' );
    mvwaddch(window,  y + 2, x + 7, ' ' );
    mvwaddch(window,  y + 3, x + 7, ' ' );
    mvwaddch(window,  y + 4, x + 7, ' ' );

    mvwaddch(window,  y, x + 8, ' ' );
    mvwaddch(window,  y, x + 8, ' ' );
    mvwaddch(window, y + 1, x + 8, ' ' );
    mvwaddch(window,  y + 2, x + 8, ' ' );
    mvwaddch(window,  y + 3, x + 8, ' ' );
    mvwaddch(window,  y + 4, x + 8, ' ' );

    mvwaddch(window,  y, x + 9, ' ' );
    mvwaddch(window, y + 1, x + 9, ' ' );
    mvwaddch(window,  y + 2, x + 9, ' ' );
    mvwaddch(window,  y + 3, x + 9, ' ' );
    mvwaddch(window,  y + 4, x + 9, ' ' );

    mvwaddch(window,  y, x + 10, ' ' );
    mvwaddch(window,  y + 1, x + 10, ' ' );
    mvwaddch(window,  y + 2, x + 10, ' ' );
    mvwaddch(window,  y + 3, x + 10, ' ' );
    mvwaddch(window,  y + 4, x + 10, ' ' );
}


void lavaBreathAttack(WINDOW* window){

    int initialPositonX = 35;
    int initialPositionY = 6;

    while( true ){
       
       lavaBreath( window, initialPositionY, initialPositonX );
       wrefresh(window);
       std::this_thread::sleep_for( std::chrono::milliseconds(80) );
       removeLavaBreath( window, initialPositionY, initialPositonX );
       wrefresh(window);
       initialPositonX--;

       if(initialPositonX == 10) break;

    }
    playerMaxLife = playerMaxLife - 50;
}