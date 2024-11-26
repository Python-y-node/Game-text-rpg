#include  <ncurses.h>
#include <unistd.h>

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
printw(\n);
printw("Presiona una tecla para salir. Nos vemos pronto......");

refresh();

}

int num_lineas = sizeof(creditosfinales) / sizeof(creditosfinales[0])

start_color();
init_pair(1,color_white, color_green);

for (int i = 0; i < num_lineas + max_y; i++) {
clear();
}

for (int j = 0; j < num_lineas; j++) {
if ( i - j >=0 && i -j < max_y) {
attron(color_pair(1));
mvprintw(i - j, 0, creditos[j]);
}
}


refresh();

usleep(150000);

int main(){
initscr();
raw();
keypad(stdscr, true);
noecho();
curs_set(0);

mostrar_creditos();
getch();
endwin();

return 0;

}