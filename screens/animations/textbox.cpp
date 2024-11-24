#include <ncurses.h>

using namespace std;

void textBox(WINDOW* mainWindow)
{

//Initializes the screen
initscr();
noecho();
cbreak();
keypad(stdscr, TRUE);
curs_set(1);

//Valores del marco de la caja de texto
int height, width, stary, starx1, starx2, stary2;

height=3, width=20;

stary=(LINES - height)/2;

starx1=(COLS - (2 * width + 2))/2;
starx2= starx1;
stary2= stary + 6;

//Creacion de la ventana
WINDOW *txt_box1= subwin(mainWindow, height, width, stary, starx1);
box(txt_box1, 0 ,0 );
wrefresh(txt_box1);

WINDOW * txt_box2= subwin(mainWindow, height, width, stary2, starx2 );
box(txt_box2, 0, 0);
wrefresh(txt_box2);

//Entrada de texto
char user_input[256]={0};
char password_input[256]={0};

echo();
mvwgetnstr(txt_box1, 1, 1, user_input, sizeof(user_input) - 1);
noecho();

mvwgetnstr(txt_box2, 1, 1, password_input, sizeof(password_input) - 1);


//Eliminar las cajas de texto
wclear(txt_box1);
delwin(txt_box1);
wclear(txt_box2);
delwin(txt_box2);

//Codigo que muestra el codigo ingresado
mvprintw(LINES - 3, 0 ,"Usuario: %s", user_input);
mvprintw(LINES - 2, 0, "Contraseña: %s", password_input);
refresh();

//ends ncurses
getch();
endwin();

}