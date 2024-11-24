#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <curses.h>

//importaciones locales
// #include "animations/scene_animation.h"

using namespace std;

//FUNCION QUE CREA UNA VENTANA EMERGENTE
void warningError(const string &message)
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

void createUserScreen()
{
  //INICIA NCURSES
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  start_color();

  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);

  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  //CREACION DE LA VENTANA
  WINDOW * win = newwin(yMax, xMax, 0, 0);
  box(win, 0, 0);

  wattron(win, COLOR_PAIR(1));
  drawTree(win, 15, 2);
  wattroff(win, COLOR_PAIR(1));

  wattron(win, COLOR_PAIR(2));
  drawHouse(win, 15, 51);
  wattroff(win, COLOR_PAIR(2));

  wattron(win, COLOR_PAIR(1));
  drawTree(win, 15, 42);
  wattroff(win, COLOR_PAIR(1));

  wattron(win, COLOR_PAIR(2));
  drawHouse(win, 15, 63);
  wattroff(win, COLOR_PAIR(2));

  //OPCIONES DEL MENU
  wattron(win, A_STANDOUT);
  mvwprintw(win, 3, 10, "Bienvenido para continuar cree un usuario.");
  wattroff(win, A_STANDOUT);
  mvwprintw(win, 8, 10, "Ingrese contraseña");

  

  //LOOP
  int ch;
  while (ch = wgetch(win))
  {
    switch (ch)
    {
      case 117:
        wattron(win, A_STANDOUT);
        mvwprintw(win, 6, 10, "Ingrese usuario");
        wattroff(win, A_STANDOUT);
        wgetch(win);
      break;
      case 112:
        wattron(win, A_STANDOUT);
        mvwprintw(win, 8, 10, "Ingrese contraseña");
        wattroff(win, A_STANDOUT);
        wgetch(win);
      break;
      default:
        mvwprintw(win, 6, 10, "Ingrese usuario");
        mvwprintw(win, 8, 10, "Ingrese contraseña");
      break;
    }
  }


  //MOSTRAR EL MENSAJE EMERGENTE
  //NO FUNCIONA TODAVIA LA VENTANA EMERGENTE PORQUE CUANDO SE ACTIVARA CUANDO EL USUARIO CREE EL PERSONAJE
  warningError("Usuario guardado exitosamente!");

  endwin();
  
}
