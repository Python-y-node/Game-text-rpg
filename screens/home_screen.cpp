#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <curses.h>

#include "../loader/loader.h"

void homeScreen()
{
 
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  //CREACION DE LA VENTANA
  WINDOW * win = newwin(yMax/2, xMax/2, yMax/4, xMax/4);
  box(win, 0, 0);

  //OPCIONES DEL MENU
  mvwprintw(win, 8, 10, "Iniciar partida(1)");

  //LOOP
  int ch;
  while ((ch = wgetch(win))!= 113)
  {
    switch (ch)
    {
      case 49:
        wattron(win, A_STANDOUT);
        mvwprintw(win, 8, 10, "Iniciar partida(1)");
        wattroff(win, A_STANDOUT);
      break;
      default:
        mvwprintw(win, 8, 10, "Iniciar partida(1)");
      break;
    }
    wrefresh(win);
    this_thread::sleep_for(chrono::milliseconds(1000));
    if( ch = 10){
      routerMenu = 4;
      break;
    }
    
  }
  this_thread::sleep_for(chrono::milliseconds(1500));
  //FINALIZA NCURSES
  endwin();
  
}
