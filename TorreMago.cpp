#include <iostream>
#include <cstdlib>   // Para usar rand y srand
#include <ctime>     // Para usar time
#include <ncurses.h> // Para ncurses

using namespace std;

// Función para iniciar el juego
void inicializar_juego(int &item)
{
    item = rand() % 3; // Número aleatorio entre 0 y 2
}

// Función para pedir la respuesta sobre si quiere jugar
bool pedir_respuesta()
{
    printw("Te apetece jugar? (sí/no): ");
    refresh();
    string respuesta;
    char c;

    while (true)
    {
        c = getch(); // Obtener un carácter
        if (c == '\n') break;
        respuesta.push_back(tolower(c));
    }

    if (respuesta == "si")
    {
        printw("\n¡Genial! Vamos a jugar.\n");
        refresh();
        return true;
    }
    else if (respuesta == "no")
    {
        printw("\nEstá bien. Tal vez en otra ocasión.\n");
        refresh();
        return false;
    }
    else
    {
        printw("\nRespuesta inválida. Por favor, responde con 'sí' o 'no'.\n");
        refresh();
        return pedir_respuesta();
    }
}

// Función para pedir el intento del usuario
void pedir_intento(int &intento, int item)
{
    printw("Introduce el número de la columna donde crees que está el objeto (1, 2 o 3): ");
    refresh();
    intento = -1;

    while (true)
    {
        char c = getch();
        if (c >= '1' && c <= '3')
        {
            intento = c - '0';
            printw("\nElegiste la columna %d.\n", intento);
            refresh();
            break;
        }
        else
        {
            printw("\nOpción inválida. Debes elegir un número entre 1 y 3.\n");
            refresh();
            printw("Introduce nuevamente tu elección (1, 2 o 3): ");
            refresh();
        }
    }
}

// Función principal del juego
void jugar()
{
    srand(static_cast<unsigned int>(time(0))); // Semilla para números aleatorios
    int matriz[3] = {0};
    int item;
    inicializar_juego(item);
    matriz[item] = 1;

    initscr();     // Inicializa ncurses
    start_color(); // Inicia colores

    init_color(201, 1000, 0, 1000); 
    init_pair(1, 201, COLOR_BLACK);

    attron(COLOR_PAIR(1));
    printw("Bienvenido a mis aposentos. Se que viniste en busca de mi poder para cumplir tu aventura.\n");
    printw("Te tengo una propuesta. Qué tal si jugamos un juego?\n");
    attroff(COLOR_PAIR(1));

    if (!pedir_respuesta())
    {
        endwin();
        return;
    }

    int intento;
    pedir_intento(intento, item);

    attron(COLOR_PAIR(1));
    if (intento - 1 == item)
    {
        printw("¡Felicidades! Has ganado. Por lo tanto, te entrego mi poder para que puedas continuar.\n");
    }
    else
    {
        printw("Lo siento, pero has fallado. No has mostrado ser digno de mi poder.\n");
    }
    attroff(COLOR_PAIR(1));

    printw("Hasta la próxima, Aventurero.\n");
    printw("Presiona cualquier tecla para salir.");
    refresh();

    getch(); // Esperar a que el usuario presione una tecla
    endwin(); // Finaliza ncurses
}

int main()
{
    jugar(); // Iniciar el juego
    return 0;
}
