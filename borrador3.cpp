#include <iostream>
#include <ctime>
#include <limits>
#include <ncurses.h>

using namespace std;

int main()
{
    int jugador = 0, herrero = 0;
    char intento; // Variable para capturar la opción del jugador como carácter

    // Inicializar ncurses
    initscr();
    cbreak();             // Desactiva el buffering de línea
    noecho();             // No mostrar los caracteres que ingresa el usuario
    keypad(stdscr, TRUE); // Habilitar teclas especiales

    attron(A_BOLD);

    start_color();

    init_pair(1, COLOR_CYAN, COLOR_BLACK); // Definir par, texto cyan fondo negro

    attron(COLOR_PAIR(1));

    printw("'Bienvenido a mi tienda, enfrentate conmigo en un juego de piedra papel y tijera y consigue un escudo... solo si me ganas jajaja'\n");
    refresh();
    getch();
    attroff(COLOR_PAIR(1));

    printw("\n*************************\n");
    printw("Piedra - Papel - Tijera\n");
    printw("*************************\n");

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
        printw("Digite una opcion valida\n");

        clear();

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

    // Determinar el ganador
    if (jugador == herrero)
    {
        attron(COLOR_PAIR(1));

        printw("\n'¡Es un empate!'\n");
         attroff(COLOR_PAIR(1));

    }
    else if ((jugador == 1 && herrero == 3) || (jugador == 2 && herrero == 1) || (jugador == 3 && herrero == 2))
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
    refresh();
    getch();
    endwin();

    return 0;
}
