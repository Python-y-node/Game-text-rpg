#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <curses.h>

#include "animations/index.h"
//importar variable del router 
 #include "../loader/loader.h"

//importar services para login
#include "../services/user_services.cpp"

void showMessage(const string message) {
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
   
    int height = 7, width = message.length() + 8;
    int start_y = (yMax - height) / 2;
    int start_x = (xMax - width) / 2; // Centrar horizontalmente

    // Crear la ventana emergente
    WINDOW *popup = newwin(height, width, start_y, start_x);
    box(popup, 0, 0);
    
    wattron(popup, COLOR_PAIR(1));
     mvwprintw(popup, height / 2 - 1, 2, "%s", message.c_str());
    wattroff(popup, COLOR_PAIR(1));

    wrefresh(popup);
    delwin(popup);
}

void loginUserScreen() {

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    bool validUser = false;

    // Crear la ventana principal
    WINDOW *win = newwin(yMax, xMax, 0, 0);
    box(win, 0, 0);

    mvwprintw(win, 3, 20, "Bienvenido, para continuar inicia sesión!");
     //Dibujar escena
    drawHouse( win, 15, 2 );
    drawCastle( win, 10, 55 );

    wrefresh(win);
    // Dimensiones y posiciones de las cajas de texto
    int height = 3, width = 20;
    int start_y1 = (yMax - height) / 2;
    int start_x1 = (xMax - width) / 2;

    int start_y2 = start_y1 + 4;

    // Crear cajas de texto independientes
    WINDOW *txt_box1 = newwin(height, width, 12, 18);
    box(txt_box1, 0, 0);
    mvwprintw(txt_box1, 0, 1, "Usuario");
    wrefresh(txt_box1);

    WINDOW *txt_box2 = newwin(height, width, 16, 18);
    box(txt_box2, 0, 0);
    mvwprintw(txt_box2, 0, 1, "Clave");
    wrefresh(txt_box2);

    // Entrada de texto
    char usernameInput[256] = {0};
    char passwordInput[256] = {0};

    // Leer entrada del usuario
    echo();
    mvwgetnstr(txt_box1, 1, 2, usernameInput, sizeof(usernameInput) - 1); // Leer usuario
   
    mvwgetnstr(txt_box2, 1, 2, passwordInput, sizeof(passwordInput) - 1); // Leer contraseña
    noecho();
    // Validar credenciales (puedes reemplazar con tu lógica real)
    validUser = userLogin(usernameInput, passwordInput);

    if ( validUser != true) {
        showMessage("Usuario inválido");
        this_thread::sleep_for( chrono::milliseconds(1000));
    } else {
        showMessage("¡Inicio de sesión exitoso!");
        this_thread::sleep_for( chrono::milliseconds(1500));
        routerMenu = 3;
    }

    // Finalizar ncurses
    delwin(txt_box1);
    delwin(txt_box2);
    delwin(win);

    endwin();
}

