#include  <ncurses.h>
#include <unistd.h>


char*creditosfinales[] = {

    "*Kalet Adonay Chavez Alvarenga",
    "*Mario Alexander Molina Fuentes",
    "*Adriana Lisbeth Reyes Perez",
    "*Carlos Alejandro Reyes Segovia",
    "*Gladys Alejandra Rivera Iraheta",

};

void mostrar_creditos(){
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

}

int main(){
initscr();
raw();
keypad(stdscr, TRUE);
noecho();
curs_set(0);

int num_lineas = sizeof(creditosfinales) / sizeof(creditosfinales[0]);

int max_y, max_x;
getmaxyx(stdscr, max_y,max_x);

start_color();
init_pair(1, COLOR_WHITE, COLOR_GREEN);

clear();

mostrar_creditos();

for (int i = 0; i < num_lineas && i < max_y; i++) {
        attron(COLOR_PAIR(1));
        mvprintw(i,0, %s, creditosfinales[i]);
        attroff(COLOR_PAIR(1));
    }
   
   refresh(); 

usleep(150000);

getch();
endwin();

return 0;

}