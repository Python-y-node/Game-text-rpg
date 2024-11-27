#include <iostream>
#include <cstdlib>   // Para usar rand y srand
#include <ctime>     // Para usar time
#include <ncurses.h> // Para ncurses
#include "animations/index.h" //Para ocupar las animaciones


using namespace std;

// Función para iniciar el juego
void inicializar_juego(int &item) {
    item = rand() % 3; // Número aleatorio entre 0 y 2
}


// Función para pedir el intento del usuario
void pedir_intento(WINDOW *juego2, int &intento, int item) {

    cardAnimation(juego2, 20, 70);   
    cardAnimation(juego2, 20, 76);  
    cardAnimation(juego2, 20, 82);  
    mvwprintw(juego2,28 , 67.75, " 1     2     3");

    mvwprintw(juego2, 10, 15, "Introduce el número de la carta donde crees que está el poder (1, 2 o 3): ");
    wrefresh(juego2);
    intento = -1;

    while (true) {
        char c = wgetch(juego2);
        if (c >= '1' && c <= '3') {
            intento = c - '0';
            mvwprintw(juego2, 12, 15, "Elegiste la columna %d.", intento);
            wrefresh(juego2);
            break;
        } else {
            mvwprintw(juego2, 14, 15, "Opción inválida. Debes elegir un número entre 1 y 3.");
            wrefresh(juego2);
        }
    }
}

// Función principal del juego
void jugar(WINDOW *juego2) {
    srand(static_cast<unsigned int>(time(0))); // Semilla para números aleatorios
    int matriz[3] = {0};
    int item;
    inicializar_juego(item);
    matriz[item] = 1;

    // Configurar colores
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);

    wattron(juego2, COLOR_PAIR(1));
    mvwprintw(juego2, 2, 5, "Bienvenido a mis aposentos. Se que viniste en busca de mi poder para cumplir tu aventura.\n");
    mvwprintw(juego2, 4, 5, "Te tengo una propuesta. Qué tal si jugamos un juego");
    wattroff(juego2, COLOR_PAIR(1));
    wrefresh(juego2);
    
    wgetch(juego2);


    int intento;
    pedir_intento(juego2, intento, item);

      wclear(juego2);
    box(juego2, 0, 0);

    wattron(juego2, COLOR_PAIR(1));
      wizard_animation(juego2, 23.5, 110);
    if (intento - 1 == item) {
        mvwprintw(juego2, 14, 15, "¡Felicidades! Has ganado. Por lo tanto, te entrego mi poder para que puedas continuar.");
    } else {
        mvwprintw(juego2, 14, 40, "Lo siento, pero has fallado. No has mostrado ser digno de mi poder.");
    }
    

    mvwprintw(juego2, 35, 15, "Hasta la próxima, Aventurero.");

    wattroff(juego2, COLOR_PAIR(1));

    mvwprintw(juego2, 38, 15, "Presiona cualquier tecla para salir.");
    wrefresh(juego2);

    wgetch(juego2); // Esperar a que el usuario presione una tecla
    endwin();       // Finaliza ncurses
}

int main() {
    int yMax, xMax;

    // Inicializar ncurses
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    start_color();

    // Obtener dimensiones de la pantalla
    getmaxyx(stdscr, yMax, xMax);

    // Crear ventana emergente
    WINDOW *juego2 = newwin(yMax, xMax, 0, 0);
    box(juego2, 0, 0);
    wizard_animation(juego2, 23.5, 110);
    Player(juego2, 27, 30, "static", FALSE, FALSE);

    jugar(juego2); // Iniciar el juego
    return 0;
}
