#include <ncurses.h>
#include <unistd.h>
#include <iostream>

//Agregando el personaje 
#include "animations/index.h"

void credits_window()
{
    initscr();
    noecho();

    //Dimensiones de la ventana
    int height, width, start_y, start_x;
    height=20;
    width= 110;
    start_y = start_x = 1;

    WINDOW * win = newwin(height, width, start_y, start_x);
    box(win, 0, 0);

    basePlayer(win, 50, 40, TRUE, TRUE);
    mvwprintw(win, 1, 1,"                   PROYECTO FINAL                                 ");
    mvwprintw(win, 2, 1,"                                                                  ");
    mvwprintw(win, 3, 1," Creadores:                                                       ");
    mvwprintw(win, 4, 1," *Kalet Adonay Chavez Alvarenga                                   ");
    mvwprintw(win, 5, 1," *Mario Alexander Molina Fuentes                                  ");
    mvwprintw(win, 6, 1," *Adriana Lisbeth Reyes Perez                                     ");
    mvwprintw(win, 7, 1," *Carlos Alejandro Reyes Segovia                                  ");
    mvwprintw(win, 8, 1," *Gladys Alejandra Rivera Iraheta                                 ");
    mvwprintw(win, 9, 1,"                                                                  ");
    mvwprintw(win, 10, 1," Agradecimiento:                                                  ");
    mvwprintw(win, 11, 1," Agradezco a mis compañeros por su dedicacion y trabajo en equipo ");
    mvwprintw(win, 12, 1," Gracias a nuestro catedratico Miguel por su apoyo y colaboración ");
    mvwprintw(win, 13, 1,"                                                                  ");
    mvwprintw(win, 14, 1," Presiona una tecla para salir. Nos vemos pronto......");
    wrefresh(win);

    wgetch(win);
}

/* void mostrar_creditos(){
    clear();
    
    mvwprintw(win, 1, 40,"------------------------------------------------------------------\n");
    mvwprintw(win, 1, 40,"-                  PROYECTO FINAL                                -\n");
    mvwprintw(win, 1, 40,"-                                                                -\n");
    mvwprintw(win, 1, 40,"-Creadores:                                                      -\n");
    mvwprintw(win, 1, 40,"-*Kalet Adonay Chavez Alvarenga                                  -\n");
    mvwprintw(win, 1, 40,"-*Mario Alexander Molina Fuentes                                 -\n");
    mvwprintw(win, 1, 40,"-*Adriana Lisbeth Reyes Perez                                    -\n");
    mvwprintw(win, 1, 40,"-*Carlos Alejandro Reyes Segovia                                 -\n");
    mvwprintw(win, 1, 40,"-*Gladys Alejandra Rivera Iraheta                                -\n");
    mvwprintw(win, 1, 40,"-                                                                -\n");
    mvwprintw(win, 1, 40,"-Agradecimiento:                                                 -\n");
    mvwprintw(win, 1, 40,"-Agradezco a mis compañeros por su dedicacion y trabajo en equipo-\n");
    mvwprintw(win, 1, 40,"-Gracias a nuestro catedratico Miguel por su apoyo y colaboración-\n");
    mvwprintw(win, 1, 40,"------------------------------------------------------------------\n");
    mvwprintw(win, 1, 40,"\n");
    mvwprintw(win, 1, 40,"Presiona una tecla para salir. Nos vemos pronto......");

    refresh();
    getch();
}
*/
int main(){
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

   //mostrar_creditos();
    credits_window();

    endwin();
    return 0;

}