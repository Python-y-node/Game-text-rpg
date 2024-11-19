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
  WINDOW * win = newwin(yMax/2, xMax/2, yMax/4, xMax/4);
  box(win, 0, 0);

  //OPCIONES DEL MENU
  mvwprintw(win, 6, 10, "Cargar partida");
  mvwprintw(win, 8, 10, "Iniciar partida");

  //LOOP
  char ch;
  while (ch = wgetch(win))
  {
    switch (ch)
    {
      case 'u':
        wattron(win, A_STANDOUT);
        mvwprintw(win, 6, 10, "Cargar Partida");
        wattroff(win, A_STANDOUT);
      break;
      case 'c':
        wattron(win, A_STANDOUT);
        mvwprintw(win, 8, 10, "Iniciar partida");
        wattroff(win, A_STANDOUT);
      break;
      default:
        mvwprintw(win, 6, 10, "Cargar partida");
        mvwprintw(win, 8, 10, "Iniciar partida");
      break;
    }
  }
  

  wgetch(win);
  //FINALIZA NCURSES
  endwin();
  return 0;
}
