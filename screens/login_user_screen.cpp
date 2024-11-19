#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <curses.h>
using namespace std;

//FUNCION QUE CREA UNA VENTANA EMERGENTE
void show_popup(const string &message)
{
  //PARAMETROS PARA LA VENTANA EMERGENTE
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  int height=7, width=message.length() +4;
  int start_y= (yMax - height)/2;
  int star_x= (xMax - width);

  //CODIGO PARA CREAR LA VENTANA EMERGENTE
  WINDOW *popup = newwin(height, width, start_y, star_x);
  box(popup, 0, 0);

  //POSICION DE LA VENTANA EMERGENTE
  mvwprintw(popup, height / 2, 2, "%s", message.c_str());
  mvwprintw(popup, height -2, 2, "ENTER para continuar"); //Mensaje adicional

  wrefresh(popup);

  getch();
  delwin(popup);
}
int main(int argc, char const *argv[])
{
  //INICIA NCURSES
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);

  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  //CREACION DE LA VENTANA
  WINDOW * win = newwin(yMax/2, xMax/2, yMax/4, xMax/4);
  box(win, 0, 0);

  //OPCIONES DEL MENU
  mvwprintw(win, 6, 10, "Usuario");
  mvwprintw(win, 8, 10, "Contraseña");

  //LOOP
  char ch;
  while (ch = wgetch(win))
  {
    switch (ch)
    {
      case 'u':
        wattron(win, A_STANDOUT);
        mvwprintw(win, 6, 10, "Usuario");
        wattroff(win, A_STANDOUT);
      break;
      case 'c':
        wattron(win, A_STANDOUT);
        mvwprintw(win, 8, 10, "Contraseña");
        wattroff(win, A_STANDOUT);
      break;
      default:
        mvwprintw(win, 6, 10, "Usuario");
        mvwprintw(win, 8, 10, "Contraseña");
      break;
    }
  }
  //MOSTRAR EL MENSAJE EMERGENTE
  //NO FUNCIONA TODAVIA LA VENTANA EMERGENTE PORQUE CUANDO SE ACTIVARA CUANDO EL USUARIO O CONTRASENA SEA LA INCORRECTA
  show_popup("Usuario invalido");
  show_popup("Contraseña invalida");

  wgetch(win);
  //FINALIZA NCURSES
  endwin();
  return 0;
}
