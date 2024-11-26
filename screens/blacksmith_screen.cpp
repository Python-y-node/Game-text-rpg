

#include <iostream>
#include <ctime>
#include <limits>
#include <ncurses.h>

#include "animations/index.h"

using namespace std;

void mostrarInstrucciones(WINDOW*juego);
int turnoJugador(int intento, int jugador);
int turnoHerrero(int herrero);
int elegirGanador(int jugador, int herrero);

void blacksmithScreen()
{
    int jugador = 0, herrero = 0 , empate = 0;
    int yMax, xMax;
    int start_x, start_y;
    char intento ; // Variable para capturar la opción del jugador como carácter


  //CODIGO PARA CREAR LA VENTANA EMERGENTE
   getmaxyx(stdscr, yMax, xMax);


    // Crear ventana emergente
    WINDOW *juego = newwin(yMax, xMax, 0, 0);
    box(juego, 0, 0);

    Player(juego, 10,30,"static", FALSE, FALSE) ;
    basePlayerNoHat(juego,8.5, 70);


      mostrarInstrucciones(juego);

    wrefresh(juego);

    // Esperar entrada del usuario para cerrar
    wgetch(juego);

    // Finalizar ncurses
    endwin();


  
    
       do {
        
        jugador = turnoJugador(jugador, intento);
        herrero = turnoHerrero(herrero);

        
        if (jugador == herrero) {
            
            attron(COLOR_PAIR(1));
            printw("\n'¡Es un empate! Juguemos otra vez.'\n");
            attroff(COLOR_PAIR(1));
            refresh();
            getch();
            empate = true; // Vuele a jugar si empate
        } else {
            elegirGanador(jugador, herrero);
            empate = false; // Ya no lo repite
        }
    } while (empate);

    refresh();
    getch();
    endwin();

}

void mostrarInstrucciones(WINDOW*juego){

     wattron(juego, A_BOLD);

    start_color();

    init_pair(1, COLOR_CYAN, COLOR_BLACK); // Definir par, texto cyan fondo negro

    wattron(juego, COLOR_PAIR(1));

    mvwprintw(juego, 2, 5, "'Bienvenido a mi tienda, enfrentate conmigo en un juego de piedra papel y tijera y consigue un escudo... solo si me ganas jajaja'\n");
    wrefresh(juego);
    wgetch(juego);
    wattroff(juego, COLOR_PAIR(1));

    mvwprintw(juego , 7, 6, "\n*************************\n");
    mvwprintw(juego , 7 , 8, "Piedra - Papel - Tijera\n");
    mvwprintw(juego, 7, 10,"*************************\n");

}

int turnoJugador(int intento, int jugador){

      // turno del jugador
    do
    {
        printw("\nElige tu opción:\n");

        attroff(A_BOLD);

        printw("Seleccione '1' para elegir Piedra\n");
        printw("Seleccione '2' para elegir Papel\n");
        printw("Seleccione '3' para elegir Tijera\n");

        intento = getch();
        refresh();

        // Validación de la entrada del jugador
        if (intento == '1')
            jugador = 1;
        else if (intento == '2')
            jugador = 2;
        else if (intento == '3')
            jugador = 3;
        else

       
            init_pair(2, COLOR_YELLOW, COLOR_BLACK);

        attron(COLOR_PAIR(2));

         clear(); 
        
        printw("Digite una opcion valida\n");

    

        attroff(COLOR_PAIR(2));

    } while (jugador != 1 && jugador != 2 && jugador != 3); // se epetira hasta que el jugador elija una opción válida

    // Mostrar la opción elegida por el jugador
    clear();
    printw("Has elegido: ");
    switch (jugador)
    {
    case 1:
        printw("Piedra\n");
        break;
    case 2:
        printw("Papel\n");
        break;
    case 3:
        printw("Tijera\n");
        break;
    }

    return jugador;
}

int turnoHerrero(int herrero){


    // Generar la elección aleatoria del herrero (opción del programa)
    srand(time(0));
    herrero = rand() % 3 + 1; // Genera un número aleatorio entre 1 y 3

    // Mostrar la opción del herrero
    printw("El Herrero eligió: ");
    switch (herrero)
    {
    case 1:
        printw("Piedra\n");
        break;
    case 2:
        printw("Papel\n");
        break;
    case 3:
        printw("Tijera\n");
        break;
    }

    return herrero;
}

 int elegirGanador(int jugador, int herrero){


      // Determinar el ganador
  
    if ((jugador == 1 && herrero == 3) || (jugador == 2 && herrero == 1) || (jugador == 3 && herrero == 2))
    {
        attron(COLOR_PAIR(1));
        printw("\n'¡Rayos, me has vencido! Te he otorgado un escudo.'\n");
         attroff(COLOR_PAIR(1));
    }
    else
    {

        attron(COLOR_PAIR(1));
        printw("\n'¡Te he vencido esta vez... será a la próxima. Buena suerte!'\n");
         attroff(COLOR_PAIR(1));
    }

    printw("\nPresiona cualquier tecla para salir...");



    return 0;
}