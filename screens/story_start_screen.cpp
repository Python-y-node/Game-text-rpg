#include <iostream>
#include <ncurses.h>
#include "animations/index.h"

using namespace std;

void storyStartScreen() {

    int yMax, xMax;
    
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    start_color();

    getmaxyx(stdscr, yMax, xMax);

    WINDOW *startScreen = newwin(yMax, xMax, 0, 0);
    box(startScreen, 0, 0);

    init_pair(7, COLOR_CYAN, COLOR_BLACK); 
    wattron(startScreen, COLOR_PAIR(7));

    mvwprintw(startScreen, 5, 10, "Tu padre ha sido seleccionado para una mision importante");
    mvwprintw(startScreen, 6, 10, "contra la bestia.");

    Player(startScreen, 12, 20, "static", FALSE, FALSE);
    soldier(startScreen, 10, 60);
    
    wrefresh(startScreen);
    wgetch(startScreen);

    wclear(startScreen);
    box(startScreen, 0, 0);
    
    mvwprintw(startScreen, 5, 10, "No, no puedo peritir que vaya. El no aguantaria esa mision.");

    Player(startScreen, 12, 20, "static", FALSE, FALSE);
    soldier(startScreen, 10, 60);

    wrefresh(startScreen);
    wgetch(startScreen);

    wclear(startScreen);
    box(startScreen, 0, 0);

    init_pair(7, COLOR_CYAN, COLOR_BLACK); 
    wattron(startScreen, COLOR_PAIR(7));

    mvwprintw(startScreen, 5, 10, "En ese caso ven conmigo y enfrentate tu...");

    Player(startScreen, 12, 20, "static", FALSE, FALSE);
    soldier(startScreen, 10, 60);

    wrefresh(startScreen);
    wgetch(startScreen);

  WINDOW *aceptar = newwin(yMax - 27, xMax - 120, 12, 20);
  box(aceptar, 0, 0);                    
  wrefresh(aceptar);                      

  mvwprintw(aceptar, 2, 12, "Aceptas esta mision?");

  init_pair(8, COLOR_YELLOW, COLOR_BLACK); 
  wattron(aceptar,COLOR_PAIR(8)) ;
  mvwprintw(aceptar, 4.5, 18, "ACEPTAR");     
  wattroff(aceptar, COLOR_PAIR(8));

  wrefresh(aceptar);                      
  wgetch(aceptar);         



    endwin();

  
}
