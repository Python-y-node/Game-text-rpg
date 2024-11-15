#include <ncurses.h>


int main(){
    initscr();  

    //Sombrero o casco
    mvaddch( 4, 3, ACS_ULCORNER);
    mvaddch( 4, 4, ACS_HLINE);
    mvaddch( 4, 5, ACS_HLINE);
    mvaddch( 4, 6, ACS_HLINE);
    mvaddch( 4, 7, ACS_HLINE);
    mvaddch( 4, 8, ACS_URCORNER);
    mvaddch( 5, 2, ACS_LLCORNER);
    mvaddch( 5, 3, ACS_HLINE);
    mvaddch( 5, 4, ACS_HLINE);
    mvaddch( 5, 5, ACS_HLINE);
    mvaddch( 5, 6, ACS_HLINE);
    mvaddch( 5, 7, ACS_HLINE);
    mvaddch( 5, 8, ACS_HLINE);
    mvaddch( 5, 9, ACS_LRCORNER);

    //Cabeza
    mvaddch(6,3, ACS_VLINE);
    //ojos
    mvaddch(6,5, '0');
    mvaddch(6,7, '0');

    //boca
    mvaddch(6,6, '_');

    mvaddch(6,8, ACS_VLINE);

    //barbilla
    mvaddch(7,3, ACS_LLCORNER);
    mvaddch(7,8, ACS_LRCORNER);

    refresh(); 
    getch();   
    endwin();  


}