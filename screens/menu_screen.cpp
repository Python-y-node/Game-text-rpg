#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <curses.h>

#include "animations/scene_animation.h"
#include "../loader/loader.h"


void menuScreen()
{

  //INICIA NCURSES
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  start_color();

  init_pair(1, COLOR_GREEN, COLOR_BLACK);

  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  //CREACION DE LA VENTANA
  WINDOW * win = newwin(yMax, xMax, 0, 0);
  box(win, 0, 0);

  //OPCIONES DEL MENU
  wattron( win, A_STANDOUT );
  mvwprintw(win, 3, 5, "AQUI TIENE QUE IR EL TITULO DEL VIDEOJUEGO");
  wattroff( win, A_STANDOUT );

  mvwprintw(win, 10, 10, "Iniciar sesion (i).");
  mvwprintw(win, 10, 30, "Crear usuario (c).");

  drawTree(win, 15, 2);
  drawCastle(win, 10, 51),
  drawTree(win, 15, 42);
  //LOOP
  int ch;
  int option = 0;

  while ((ch = wgetch(win)) != 113)
  {
    switch (ch)
    {
      case 105:
        wattron(win, A_STANDOUT);
        wattron(win, COLOR_PAIR(1));
        mvwprintw(win, 10, 10, "Iniciar sesion (i).");
        wattroff(win, COLOR_PAIR(1));
        wattroff(win, A_STANDOUT);

        mvwprintw(win, 10, 30, "Crear usuario (c).");
        option = 1;
        
      break;
      case 99:

        wattron(win, A_STANDOUT);
        wattron(win, COLOR_PAIR(1));
        mvwprintw(win, 10, 30, "Crear usuario (c).");
        wattroff(win, COLOR_PAIR(1));
        wattroff(win, A_STANDOUT);

        mvwprintw(win, 10, 10, "Iniciar sesion (i).");
        option = 2;
      break;
      case 10:
         if(option == 1){
          routerMenu = 1;
         } else if( option == 2 ){
          routerMenu = 2;
         }
      break;
      default:
        mvwprintw(win, 10, 10, "Iniciar sesion (i).");
        mvwprintw(win, 10, 30, "Crear usuario (c).");
      break;
    }
    
    wrefresh(win);
    if( ch == 10 ){
      break;
    }
  }
  
  clear();
  endwin();
}