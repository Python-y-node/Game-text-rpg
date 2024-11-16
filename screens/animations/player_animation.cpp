#include <ncurses.h>
#include <iostream>

using namespace std;

void player( int y, int x ){

     //Sombrero o casco
    mvaddch( y, x , ACS_ULCORNER);
    mvaddch( y, x + 1, ACS_HLINE);
    mvaddch( y, x + 2, ACS_HLINE);
    mvaddch( y, x + 3, ACS_HLINE);
    mvaddch( y, x + 4, ACS_HLINE);
    mvaddch( y, x + 5, ACS_URCORNER);
    mvaddch( y + 1, x - 1 , ACS_LLCORNER);
    mvaddch( y + 1, x, ACS_HLINE);
    mvaddch( y + 1, x + 1, ACS_HLINE);
    mvaddch( y + 1, x + 2, ACS_HLINE);
    mvaddch( y + 1, x + 3, ACS_HLINE);
    mvaddch( y + 1, x + 4, ACS_HLINE);
    mvaddch( y + 1, x + 5, ACS_HLINE);
    mvaddch( y + 1, x + 6, ACS_LRCORNER);

    //Cabeza
    mvaddch( y + 2, x, ACS_VLINE);

    //boca
    mvaddch( y + 2, x + 3 , '_');

    mvaddch( y + 2, x + 5, ACS_VLINE);

    //barbilla
    mvaddch( y + 3, x, ACS_LLCORNER);
    mvaddch( y + 3, x + 5, ACS_LRCORNER);

    //cuerpo
    mvaddch( y + 3, x + 6, ACS_HLINE);
    mvaddch( y + 3, x - 1, ACS_HLINE);
    mvaddch( y + 5, x, ACS_LLCORNER);
    mvaddch( y + 5, x + 1, ACS_HLINE);
    mvaddch( y + 5, x + 2, ACS_HLINE);
    mvaddch( y + 5, x + 3, ACS_HLINE);
    mvaddch( y + 5, x + 4, ACS_HLINE);
    mvaddch( y + 5, x + 5, ACS_LRCORNER);
    
    //Brazo izquierdo
    mvaddch( y + 4, x - 2, ACS_VLINE);
    mvaddch( y + 4 , x, ACS_VLINE);
    mvaddch( y + 5, x - 2, ACS_LLCORNER );
    //Brazo derecho
    mvaddch( y + 4, x + 5, ACS_VLINE);
    mvaddch( y + 4, x + 7, ACS_VLINE);
    mvaddch( y + 5, x + 7, ACS_LRCORNER );

    //piernas
    mvaddch( y + 6 , x, ACS_VLINE );
    mvaddch( y + 6, x + 5, ACS_VLINE );
    mvaddch( y + 7, x, ACS_VLINE );
    mvaddch( y + 7, x + 5, ACS_VLINE );

    mvaddch( y + 8, x, ACS_LLCORNER );
    mvaddch( y + 8, x + 1, ACS_HLINE );
    mvaddch( y + 8, x + 2, ACS_HLINE );
    mvaddch( y + 7 , x + 2, '_');
    mvaddch( y + 7 , x + 2, '_');
    mvaddch( y + 7 , x + 3, ACS_VLINE);
    mvaddch( y + 8 , x + 3, ACS_BTEE );
    mvaddch( y + 7, x + 4, '_');
    mvaddch( y + 8, x + 5, '_');
    mvaddch( y + 8, x + 4, ACS_HLINE );
    mvaddch( y + 8, x + 5, ACS_HLINE );
    mvaddch( y + 8, x + 6, ACS_LRCORNER );

    //ojos
    mvaddch( y + 2, x + 2, '0');
    mvaddch( y + 2, x + 4, '0'); 
    
}

void removePlayer( int y, int x ){

     //Sombrero o casco
    mvaddch( y, x , ' ');
    mvaddch( y, x + 1, ' ');
    mvaddch( y, x + 2, ' ');
    mvaddch( y, x + 3, ' ');
    mvaddch( y, x + 4, ' ');
    mvaddch( y, x + 5, ' ');
    mvaddch( y + 1, x - 1 , ' ');
    mvaddch( y + 1, x, ' ');
    mvaddch( y + 1, x + 1, ' ');
    mvaddch( y + 1, x + 2, ' ');
    mvaddch( y + 1, x + 3, ' ');
    mvaddch( y + 1, x + 4, ' ');
    mvaddch( y + 1, x + 5, ' ');
    mvaddch( y + 1, x + 6, ' ');

    //Cabeza
    mvaddch( y + 2, x, ' ');

    //boca
    mvaddch( y + 2, x + 3 , '_');

    mvaddch( y + 2, x + 5, ' ');

    //barbilla
    mvaddch( y + 3, x,' ');
    mvaddch( y + 3, x + 5, ' ');

    //cuerpo
    mvaddch( y + 3, x + 6, ' ');
    mvaddch( y + 3, x - 1, ' ');
    mvaddch( y + 5, x, ' ');
    mvaddch( y + 5, x + 1, ' ');
    mvaddch( y + 5, x + 2, ' ');
    mvaddch( y + 5, x + 3, ' ');
    mvaddch( y + 5, x + 4, ' ');
    mvaddch( y + 5, x + 5, ' ');
    
    //Brazo izquierdo
    mvaddch( y + 4, x - 2, ' ');
    mvaddch( y + 4 , x, ' ');
    mvaddch( y + 5, x - 2, ' ' );
    //Brazo derecho
    mvaddch( y + 4, x + 5, ' ');
    mvaddch( y + 4, x + 7, ' ');
    mvaddch( y + 5, x + 7, ' ' );

    //piernas
    mvaddch( y + 6 , x, ' ' );
    mvaddch( y + 6, x + 5, ' ' );
    mvaddch( y + 7, x, ' ' );
    mvaddch( y + 7, x + 5, ' ' );

    mvaddch( y + 8, x, ' ' );
    mvaddch( y + 8, x + 1, ' ' );
    mvaddch( y + 8, x + 2, ' ' );
    mvaddch( y + 7 , x + 2, '_');
    mvaddch( y + 7 , x + 2, '_');
    mvaddch( y + 7 , x + 3, ' ');
    mvaddch( y + 8 , x + 3, ' ' );
    mvaddch( y + 7, x + 4, '_');
    mvaddch( y + 8, x + 5, '_');
    mvaddch( y + 8, x + 4, ' ' );
    mvaddch( y + 8, x + 5, ' ' );
    mvaddch( y + 8, x + 6, ' ' );

    //ojos
    mvaddch( y + 2, x + 2, ' ');
    mvaddch( y + 2, x + 4, ' '); 

}


void Player(int initialPositionX,  int initialPositionY){

    int maxPosition = 70;
    int movents = 0;

    int key;
    while( (key = getch()) != 'q' ){
        switch (key)
        {
        case KEY_RIGHT:
            if( initialPositionX == maxPosition ){
                break;
            }else{
                removePlayer( initialPositionY, initialPositionX -1 );
                player( initialPositionY, initialPositionX);
                initialPositionX++;
                refresh();
            }
            break;
        case KEY_LEFT:
        if( initialPositionX == 2 ){
                break;
            }else{
                removePlayer( initialPositionY, initialPositionX + 1 );
                player( initialPositionY, initialPositionX);
                initialPositionX--;
                refresh();
            }
            break;
        default:
            break;
        }
    }


}