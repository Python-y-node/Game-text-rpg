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
void pedir_intento(WINDOW *juego2, int item) {
    
    int key ;
    
    while (( key = wgetch(juego2)) != 113) {
        
        if (key > 48 && key < 52 ) {

            mvwprintw(juego2, 16, 22, "                                  ");
            mvwprintw(juego2,17,22, "                    ");
            
            wattron(juego2, COLOR_PAIR(24));
              wattron(juego2, A_BOLD);
                mvwprintw(juego2, 19, 24, "Elegiste la columna %d.", key - 48);
              wattroff(juego2, A_BOLD);
            wattroff(juego2, COLOR_PAIR(24));
            
            break;
        } else {
            mvwprintw(juego2, 16, 22, "Opción inválida. Debes elegir un");
            mvwprintw(juego2, 17, 22, "número entre 1 y 3.");
           
        }
        wrefresh(juego2);

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

    wattron(juego2, COLOR_PAIR(1));
        mvwprintw(juego2, 2, 3, "Bienvenido a mis aposentos. Se que viniste en busca de mi poder para");
        mvwprintw(juego2, 3, 3, "cumplir tu aventura.Te tengo una propuesta. Qué tal si jugamos un juego");
    wattroff(juego2, COLOR_PAIR(1));
  


    int intento;
    pedir_intento(juego2, item);

    box(juego2, 0, 0);

    if (intento - 1 == item) {
        mvwprintw(juego2, 17, 24, "¡Felicidades! Has ganado. Por lo tanto te");
        mvwprintw(juego2, 18, 24, "entrego mi poder para que puedas continuar.");
    } else {
        mvwprintw(juego2, 17, 24, "Lo siento, pero has fallado. No has ");
        mvwprintw(juego2, 18, 24, "mostrado ser digno de mi poder.");
    }
    

    mvwprintw(juego2, 20, 24, "Hasta la próxima, Aventurero.");

}

void wizardScreen() {
    
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    int yMax, xMax;

    // Obtener dimensiones de la pantalla
    getmaxyx(stdscr, yMax, xMax);

    // Crear ventana emergente
    WINDOW *juego2 = newwin(yMax, xMax, 0, 0);
    box(juego2, 0, 0);
    wizardAnimation(juego2,10, 65);
    Player(juego2, 14, 10, "static", FALSE, FALSE);

    cardAnimation(juego2, 10, 32);   
    cardAnimation(juego2, 10, 38);  
    cardAnimation(juego2, 10, 44);  
    mvwprintw(juego2, 14 , 29, " 1     2     3");

    mvwprintw(juego2, 7, 20, "Introduce el número de la carta donde");
    mvwprintw( juego2, 8, 20, " crees que está el poder (1, 2 o 3):");
    wrefresh(juego2);

    jugar(juego2); // Iniciar el juego

    wgetch(juego2);
    routerMenu = 4;
    delwin(juego2);
    
    endwin();
   
}
