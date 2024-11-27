
#include <iostream>
#include <ctime>
#include <limits>
#include <ncurses.h>
#include "animations/index.h"

using namespace std;

void mostrarInstrucciones(WINDOW*juego);
int turnoJugador(WINDOW*juego, int intento, int jugador);
int turnoHerrero(WINDOW*juego, int herrero);
int elegirGanador(WINDOW*juego, int jugador, int herrero);

void blackSmithScreen()
{
    int jugador = 0, herrero = 0 , empate = 0;
    int yMax, xMax;
    char intento;

// Inicializar ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    start_color();

    // Obtener dimensiones de la pantalla
    getmaxyx(stdscr, yMax, xMax);

    // Crear ventana emergente
    WINDOW *juego = newwin(yMax, xMax, 0, 0);
    box(juego, 0, 0);

    
    Player(juego, 27, 30, "static", FALSE, FALSE);
    basePlayerNoHat(juego, 26.5, 110);
    
    
    mostrarInstrucciones(juego);

    // Limpiar ventana después de las instrucciones para iniciar juego
    wrefresh(juego); 
    
do {

    jugador = turnoJugador(juego, jugador, intento);
    herrero = turnoHerrero(juego, herrero);

    // en caso de empate
    if (jugador == herrero) {
        wattron(juego, COLOR_PAIR(7));
        mvwprintw(juego, 20, 50, "'¡Es un empate! Juguemos otra vez.'");
        wattroff(juego, COLOR_PAIR(7));
        wrefresh(juego);
        wgetch(juego); // Esperar entrada antes de repetir
        empate = true;
    } else {
        empate = false;
        elegirGanador(juego, jugador, herrero); 
        wrefresh(juego);
    }
} while (empate );

    // Finalizar ncurses
    endwin();
}


void mostrarInstrucciones(WINDOW*juego){

    wattron(juego, A_BOLD);

    init_pair(7, COLOR_CYAN, COLOR_BLACK); // Definir par, texto cyan fondo negro

    wattron(juego, COLOR_PAIR(7));

    mvwprintw(juego, 2, 5, "'Bienvenido a mi tienda, enfrentate conmigo en un juego de piedra papel y tijera y consigue un escudo... solo si me ganas jajaja'\n");
    wattroff(juego, COLOR_PAIR(7));
    wrefresh(juego);
    wgetch(juego);
   

}

int turnoJugador(WINDOW *juego, int intento, int jugador) {
    do {
        // Mostrar opciones al jugador
        mvwprintw(juego, 10, 55, "*********************************\n");
        mvwprintw(juego, 11, 60, "Piedra - Papel - Tijera\n");
        mvwprintw(juego, 12, 55, "*********************************\n");
        mvwprintw(juego, 16, 55, "Elige tu opción:\n");
        mvwprintw(juego, 18, 55, "Seleccione '1' para elegir Piedra\n");
        mvwprintw(juego, 20, 55, "Seleccione '2' para elegir Papel\n");
        mvwprintw(juego, 22, 55, "Seleccione '3' para elegir Tijera\n");

        wrefresh(juego);

        // Capturar entrada del usuario
        intento = wgetch(juego);

        // Validar la entrada del usuario
        if (intento == '1')
            jugador = 1;
        else if (intento == '2')
            jugador = 2;
        else if (intento == '3')
            jugador = 3;
        else {
            // Mostrar mensaje de 
             init_pair(8, COLOR_YELLOW, COLOR_BLACK);
            wattron(juego, COLOR_PAIR(8));
            mvwprintw(juego, 24, 55, "Opción inválida. Intente de nuevo.");
            wattroff(juego, COLOR_PAIR(8));
            wrefresh(juego);
            continue; // Pedir otra entrada
        }

        // Limpiar la ventana para mostrar la elección
        wclear(juego);
        box(juego, 0, 0);

        // Mostrar la opción elegida
        mvwprintw(juego, 15, 55, "Has elegido: ");
            wattron(juego, COLOR_PAIR(8));
        switch (jugador) {
        case 1:
            mvwprintw(juego, 15, 79, "Piedra");
            break;
        case 2:
            mvwprintw(juego, 15, 79, "Papel");
            break;
        case 3:
            mvwprintw(juego, 15, 79, "Tijera");
            break;
        }

        wattroff(juego, COLOR_PAIR(8));

        wrefresh(juego);

    } while (jugador != 1 && jugador != 2 && jugador != 3);

    return jugador;
}


int turnoHerrero(WINDOW*juego, int herrero){


    // Generar la elección aleatoria del herrero (opción del programa)
    srand(time(0));
    herrero = rand() % 3 + 1; // Genera un número aleatorio entre 1 y 3

    // Mostrar la opción del herrero
    mvwprintw(juego, 17, 55, "El Herrero eligió: ");
 
    wattron(juego, COLOR_PAIR(8));


    switch (herrero)
    {
    case 1:
        mvwprintw(juego, 17, 80, "Piedra\n");
        break;
    case 2:
        mvwprintw(juego, 17, 80, "Papel\n");
        break;
    case 3:
        mvwprintw(juego, 17, 80, "Tijera\n");
        break;
    }
      wattroff(juego, COLOR_PAIR(8));

    return herrero;
}

int elegirGanador(WINDOW *juego, int jugador, int herrero) {
  

    // Determinar el ganador
    if ((jugador == 1 && herrero == 3) || (jugador == 2 && herrero == 1) || (jugador == 3 && herrero == 2)) {
        // Jugador gana
        wattron(juego, COLOR_PAIR(7));
        mvwprintw(juego, 20, 45, "'¡Rayos, me has vencido! Te he otorgado un escudo.'");
        wattroff(juego, COLOR_PAIR(7));
    } else {
        // Herrero gana
        wattron(juego, COLOR_PAIR(7));
        mvwprintw(juego, 20, 40, "'¡Te he vencido esta vez... será a la próxima. Buena suerte!'");
        wattroff(juego, COLOR_PAIR(7));
    }

    // Instrucción adicional para el usuario
    mvwprintw(juego, 35, 24, "Presiona cualquier tecla para continuar...");
    wrefresh(juego);

    // Esperar a que el jugador presione una tecla
    wgetch(juego);

    return 0;
}
