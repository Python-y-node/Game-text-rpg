#include <ncurses.h>
#include <unistd.h>
#include <iostream>

void mostrar_creditos(){
    clear();
    
    printw("------------------------------------------------------------------\n");
    printw("-                  PROYECTO FINAL                                -\n");
    printw("-                                                                -\n");
    printw("-Creadores:                                                      -\n");
    printw("-*Kalet Adonay Chavez Alvarenga                                  -\n");
    printw("-*Mario Alexander Molina Fuentes                                 -\n");
    printw("-*Adriana Lisbeth Reyes Perez                                    -\n");
    printw("-*Carlos Alejandro Reyes Segovia                                 -\n");
    printw("-*Gladys Alejandra Rivera Iraheta                                -\n");
    printw("-                                                                -\n");
    printw("-Agradecimiento:                                                 -\n");
    printw("-Agradezco a mis compañeros por su dedicacion y trabajo en equipo-\n");
    printw("-Gracias a nuestro catedratico Miguel por su apoyo y colaboración-\n");
    printw("------------------------------------------------------------------\n");
    printw("\n");
    printw("Presiona una tecla para salir. Nos vemos pronto......");

    refresh();
    getch();
}

int main(){
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

    mostrar_creditos();

    endwin();

    return 0;

}