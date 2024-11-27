#include <iostream>
#include <ncurses.h> // Para ncurses
#include "animations/index.h" //Para ocupar las animaciones

int main(){

  int yMax, xMax;
  int i;

    initscr();
    noecho();
    cbreak();
  getmaxyx(stdscr, yMax, xMax);

  //CREACION DE LA VENTANA
  WINDOW * ScreenMenu = newwin(yMax, xMax, 0, 0);
  box(ScreenMenu, 0, 0);
  wrefresh(ScreenMenu);


    wattron(ScreenMenu, A_BOLD);
    mvwprintw(ScreenMenu, 10, 45, "Elige adonde comenzaras tu aventura.");
    wattron(ScreenMenu, A_BOLD);

    basePlayerNoHat(ScreenMenu, 26.5, 110);
    wizard_animation(ScreenMenu, 23.5, 45);
    Player(ScreenMenu, 27, 25, "static", FALSE, FALSE);
    Boss(ScreenMenu, 27, 70 );
    drawTree(ScreenMenu,  22, 10 );
     drawTree(ScreenMenu,  22,140 );
    drawHouse(ScreenMenu, 20, 120);

  wrefresh(ScreenMenu);

 WINDOW * menuP = newwin(yMax-30, xMax-80, 12, 40);
  box(menuP, 0, 0);
  wrefresh(menuP);

  keypad (menuP, true); //Nos permite ocupar flechas

    string choices[3]= {"Ir donde el herrero", "Ir donde el mago", "Ir con el final boss"};
    int choice;

    int highlight = 0 ;

    while(1){ // 1 para que siempre entra en el bucle infinito

        for(int i = 0; i < 3 ; i++){ 

            if(i == highlight)
            wattron(menuP, A_REVERSE);
            mvwprintw(menuP, i + 1, 1, "%s", choices[i].c_str()); //Mostrar opciones y visulizar la seleccionada acutalmente
            wattroff(menuP, A_REVERSE);
        }
        choice = wgetch(menuP);

        switch(choice){

            case KEY_UP:
            highlight --;
            break;

            case KEY_DOWN:
            highlight++;
            break;

            default:
            break;
        }


        if( choice == 10 )// 10 = enter 
        break;

    }


getch();
endwin();

return 0;

}