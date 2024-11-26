#include <ncurses.h>

// Agregando los dibujos
#include "animations/index.h"

using namespace std;


void trollBridgeScreen()
{
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);


  // Creacion de ventana para colocar el troll
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);
  WINDOW *win = newwin(yMax, xMax, 0, 0);
  drawTroll(win, 5, 90);
  box(win, 0, 0);


  // IMPLEMENTACION DEL PERSONAJE PRINCIPAL
  basePlayer(win, 10, 20, TRUE, TRUE);
  mvwprintw(win, 1, 5, "Troll: ");
  mvwprintw(win, 2, 5, "Has llegado a mi puente, todo aquel que quiera pasar, tendra que resolver mi acertijo.");
  mvwprintw(win, 3, 5, "Si lo logras acertar te dejare pasar, sino, lo unico que te espera es la muerte! JAJA!");
  mvwprintw(win, 9, 35, "Troll: ");
  mvwprintw(win, 10, 35, "No tengo boca, pero puedo hablar.");
  mvwprintw(win, 11, 35, "No tengo ojos, pero puedo ver.");
  mvwprintw(win, 12, 35, "No tengo cuerpo, pero te sigo a todas partes. ¿Qué soy?");
  wrefresh(win);


  // Variables de la ventana
  int height, width, start_y, start_x;
  height = 5;
  width = 60;
  start_y = start_x = 24;


  // Creacion de la ventana de ataques
  WINDOW *win_options = newwin(height, width, start_y, start_x);
  box(win_options, 0, 0);
  wrefresh(win_options);


  // Opciones para atacar y sus posiciones dentro de la ventana win_options
  // COLOCAR EL ACERTIJO Y QUE ESTAS SEAN LAS OPCIONES DE RESPUESTA
  mvwprintw(win_options, 2, 5, "Un eco(1)");
  mvwprintw(win_options, 2, 15, "Un espejo(2)");
  mvwprintw(win_options, 2, 30, "Un reflejo(3)");
  mvwprintw(win_options, 2, 45, "Una sombra(4)");

  //Variables para las opciones
  bool firstTry = false;


  // Seleccion de ataque
  int ch;
  while (ch = wgetch(win_options))
  {
    switch (ch)
    {
    case 49:
      wattron(win_options, A_STANDOUT);
      mvwprintw(win_options, 2, 5, "Un eco(1)");
      wattroff(win_options, A_STANDOUT);
      mvwprintw(win_options, 2, 15, "Un espejo(2)");
      mvwprintw(win_options, 2, 30, "Un reflejo(3)");
      mvwprintw(win_options, 2, 45, "Una sombra(4)");
      break;
    case 50:
      wattron(win_options, A_STANDOUT);
      mvwprintw(win_options, 2, 15, "Un espejo(2)");
      wattroff(win_options, A_STANDOUT);
      mvwprintw(win_options, 2, 5, "Un eco(1)");
      mvwprintw(win_options, 2, 30, "Un reflejo(3)");
      mvwprintw(win_options, 2, 45, "Una sombra(4)");
      break;
    case 51:
      wattron(win_options, A_STANDOUT);
      mvwprintw(win_options, 2, 30, "Un reflejo(3)");
      wattroff(win_options, A_STANDOUT);
      mvwprintw(win_options, 2, 5, "Un eco(1)");
      mvwprintw(win_options, 2, 15, "Un espejo(2)");
      mvwprintw(win_options, 2, 45, "Una sombra(4)");
      break;
    case 52:
      wattron(win_options, A_STANDOUT);
      mvwprintw(win_options, 2, 45, "Una sombra(4)");
      wattroff(win_options, A_STANDOUT);
      mvwprintw(win_options, 2, 5, "Un eco(1)");
      mvwprintw(win_options, 2, 15, "Un espejo(2)");
      mvwprintw(win_options, 2, 30, "Un reflejo(3)");
      break;
    default:
      mvwprintw(win_options, 2, 5, "Un eco(1)");
      mvwprintw(win_options, 2, 15, "Un espejo(2)");
      mvwprintw(win_options, 2, 30, "Un reflejo(3)");
      mvwprintw(win_options, 2, 45, "Una sombra(4)");
      break;
    }
    if (ch == 49)
    {
      mvwprintw(win_options, 2, 5, "Maldito! Has acertado mi acertijo!");

      wrefresh(win_options);
    }
  }
  wgetch(win_options);
  endwin();
}