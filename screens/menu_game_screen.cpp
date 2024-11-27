#include <iostream>
#include <ncurses.h>          // Para ncurses
#include "animations/index.h" //Para ocupar las animaciones
#include "../loader/loader.h"

void menuGameScreen()
{

  int yMax, xMax;
  int i;

  getmaxyx(stdscr, yMax, xMax);

  // CREACION DE LA VENTANA
  WINDOW *ScreenMenu = newwin(yMax, xMax, 0, 0);
  box(ScreenMenu, 0, 0);
  wrefresh(ScreenMenu);

  wattron(ScreenMenu, A_BOLD);
  mvwprintw(ScreenMenu, 2, 20, "Elige adonde comenzaras tu aventura.");
  wattron(ScreenMenu, A_BOLD);

  basePlayerNoHat(ScreenMenu, 9, 35);
  wizardAnimation(ScreenMenu, 8, 45);
  Player(ScreenMenu, 12, 15, "static");
  drawTree(ScreenMenu, 5, 2);
  drawTree(ScreenMenu, 12, 60);
  drawHouse(ScreenMenu, 3, 65);

  wrefresh(ScreenMenu);

  WINDOW *menuP = newwin(yMax / 4, xMax / 3, 3, 25);
  box(menuP, 0, 0);
  wrefresh(menuP);

  keypad(menuP, true); // Nos permite ocupar flechas

  string choices[3] = {"Ir donde el herrero", "Ir donde el mago", "Ir con el troll"};
  int choice;

  int highlight = 0;

  while (1)
  { // 1 para que siempre entra en el bucle infinito

    for (int i = 0; i < 3; i++)
    {

      if (i == highlight)
        wattron(menuP, A_REVERSE);
      mvwprintw(menuP, i + 1, 1, "%s", choices[i].c_str()); // Mostrar opciones y visulizar la seleccionada acutalmente
      wattroff(menuP, A_REVERSE);
    }

    choice = wgetch(menuP);

    switch (choice)
    {

    case KEY_UP:
      if (highlight > 0)
      {
        highlight--;
      }
      break;

    case KEY_DOWN:
      if (highlight < 2)
      {
        highlight++;
      }
      break;

    default:
      break;
    }
    if (choice == 10)
    {
      if (highlight == 0)
      {
    
        routerMenu = 6;
        break;
      }
      else if (highlight == 1)
      {
        routerMenu = 7;
        break;
      }
      else if (highlight == 2)
      {
        routerMenu = 8;
        break;
      }
    };
  }
  this_thread::sleep_for(chrono::milliseconds(400));
  endwin();
}