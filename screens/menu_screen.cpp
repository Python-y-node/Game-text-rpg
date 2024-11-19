#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <curses.h>
using namespace std;

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
  WINDOW * win = newwin(yMax, xMax, 0, 0);
  box(win, 0, 0);

  //OPCIONES DEL MENU
  mvwprintw(win, 3, 10, "AQUI TIENE QUE IR EL TITULO DEL VIDEOJUEGO");
  mvwprintw(win, 10, 5, "Iniciar sesion");
  mvwprintw(win, 10, 40, "Crear usuario");

  //LOOP
  int ch;
  while (ch = wgetch(win))
  {
    switch (ch)
    {
      case KEY_LEFT:
        wattron(win, A_STANDOUT);
        mvwprintw(win, 10, 5, "Iniciar sesion");
        wattroff(win, A_STANDOUT);
      break;
      case KEY_RIGHT:
        wattron(win, A_STANDOUT);
        mvwprintw(win, 10, 40, "Crear usuario");
        wattroff(win, A_STANDOUT);
      break;
      default:
        mvwprintw(win, 10, 5, "Iniciar sesion");
        mvwprintw(win, 10, 40, "Crear usuario");
      break;
    }
  }

  //CODIGO PARA LA CREACION DEL FONDO DE PANTALLA  
  wgetch(win);
  //FINALIZA NCURSES
  endwin();
  return 0;
}