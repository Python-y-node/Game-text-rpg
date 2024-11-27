#include <ncurses.h>

// Agregando los dibujos
#include "animations/index.h"
#include "../loader/loader.h"

using namespace std;

void trollBridgeScreen()
{
 
  // Creacion de ventana para colocar el troll
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);
  WINDOW *win = newwin(yMax, xMax, 0, 0);
  drawTroll(win, 11, 66);
  box(win, 0, 0);

  // IMPLEMENTACION DEL PERSONAJE PRINCIPAL
  Player(win, 10, 8, "static");
  mvwprintw(win, 1, 5, "Troll: ");
  mvwprintw(win, 2, 5, "Has llegado a mi puente, todo aquel que quiera pasar, tendra que resolver ");
  mvwprintw(win, 3, 5, "mi acertijo. Si lo logras acertar te dejare pasar, sino, lo unico que te ");
  mvwprintw(win, 4, 5, "espera es la muerte! JAJA!");
  mvwprintw(win, 9, 20, "Troll: ");
  mvwprintw(win, 10, 20, "No tengo boca, pero puedo hablar.");
  mvwprintw(win, 11, 20, "No tengo ojos, pero puedo ver.");
  mvwprintw(win, 12, 20, "No tengo cuerpo, pero te sigo a todas partes.");
  mvwprintw(win, 13, 20, "¿Qué soy?");
  wrefresh(win);

  // Variables de la ventana
  int height, width, start_y, start_x;
  height = 5;
  width = 60;
  start_y = start_x = 19;

  // Creacion de la ventana de ataques
  WINDOW *win_options = newwin(height, width, start_y, start_x -4);
  box(win_options, 0, 0);
  wrefresh(win_options);

  // El usuario tiene que presionar ENTER para que aparezca el acertijo
  mvwprintw(win_options, 2, 5, "Presiona ENTER para continuar");
  wrefresh(win_options);
  
  int ch;

  while ((ch = wgetch(win)) != 10)
  {

  }

  mvwprintw(win_options, 2, 5, "                             ");
  mvwprintw(win_options, 2, 5, "Un eco(1)");
  mvwprintw(win_options, 2, 15, "Un espejo(2)");
  mvwprintw(win_options, 2, 30, "Un reflejo(3)");
  mvwprintw(win_options, 2, 45, "Una sombra(4)");

  bool isAnswer = false;
  int intentos = 2;

  // Seleccion de ataque
  while (( ch = wgetch(win_options)) != 113  && intentos > 0)
  {
    mvwprintw(win_options, 2, 5, "                                            ");
    mvwprintw(win_options, 3, 5, "                                          ");
    // COLOCAR EL ACERTIJO Y QUE ESTAS SEAN LAS OPCIONES DE RESPUESTA
    mvwprintw(win_options, 2, 5, "Un eco(1)");
    mvwprintw(win_options, 2, 15, "Un espejo(2)");
    mvwprintw(win_options, 2, 30, "Un reflejo(3)");
    mvwprintw(win_options, 2, 45, "Una sombra(4)");

    switch (ch)
    {
    case 49:
      wattron(win_options, A_STANDOUT);
         mvwprintw(win_options, 2, 5, "Un eco(1)");
      wattroff(win_options, A_STANDOUT);

      mvwprintw(win_options, 2, 15, "Un espejo(2)");
      mvwprintw(win_options, 2, 30, "Un reflejo(3)");
      mvwprintw(win_options, 2, 45, "Una sombra(4)");
      isAnswer = true;
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
    case 10:
       // Limpiar la ventana de opciones
      mvwprintw(win_options, 2, 5, "         ");
      mvwprintw(win_options, 2, 15, "            ");
      mvwprintw(win_options, 2, 30, "             ");
      mvwprintw(win_options, 2, 45, "               ");

      if( intentos > 1 && isAnswer != true){
        mvwprintw(win_options, 2, 5, "JAJAJA! Te queda un intento, insecto.");
      }
      else if( intentos > 0  && isAnswer != true ){
        mvwprintw(win_options, 2, 5, "Tu oportunidad se acabo.");
        mvwprintw(win_options, 3, 5, "Ahora lo unico que te espera es la muerte!");
      }
      intentos--;
    break;
    default:
      mvwprintw(win_options, 2, 5, "Un eco(1)");
      mvwprintw(win_options, 2, 15, "Un espejo(2)");
      mvwprintw(win_options, 2, 30, "Un reflejo(3)");
      mvwprintw(win_options, 2, 45, "Una sombra(4)");
      break;
    }
    if( isAnswer == true){

        wattron(win_options, A_STANDOUT);
          mvwprintw(win_options, 2, 5, "Un eco(1)");
        wattroff(win_options, A_STANDOUT);
        wrefresh(win_options);

        this_thread::sleep_for( chrono::milliseconds(1000));

        mvwprintw(win_options, 2, 15, "            ");
        mvwprintw(win_options, 2, 30, "             ");
        mvwprintw(win_options, 2, 45, "               ");
        
        mvwprintw(win_options, 2, 5, "¡Maldito! Has acertado mi acertijo!");
        wrefresh(win_options);

        this_thread::sleep_for( chrono::milliseconds(2000));
        break;
      }
    wrefresh(win_options);

  }

  ( isAnswer ) ? routerMenu = 9 : routerMenu = 5;

  delwin(win);
  delwin(win_options);
  endwin();
}