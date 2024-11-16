#include <ncurses.h>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void eyes(int y, int x, char eyes){
    mvaddch( y + 2, x + 2, eyes);
    mvaddch( y + 2, x + 4, eyes);
}

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

    printw("Bienvenido");

    //Animacion de parpadeo de ojos del personaje
    int seconds = 0;
    while (true) {
        char eyeChar = (seconds % 2 == 0) ? '-' : '0'; 
        eyes(y, x, eyeChar);                           
        refresh();                                     
        this_thread::sleep_for( chrono::milliseconds(1500) ); 
        seconds++;
    }
    
}

int main(){
    initscr();  

    player(5, 5);
   
    refresh(); 
    getch();   
    endwin();  


}