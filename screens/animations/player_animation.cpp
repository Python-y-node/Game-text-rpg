#include <ncurses.h>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void basePlayer(int y, int x, bool hasSword, bool hasShield)
{

    // Sombrero o casco
    mvaddch(y, x, ACS_ULCORNER);
    mvaddch(y, x + 1, ACS_HLINE);
    mvaddch(y, x + 2, ACS_HLINE);
    mvaddch(y, x + 3, ACS_HLINE);
    mvaddch(y, x + 4, ACS_HLINE);
    mvaddch(y, x + 5, ACS_URCORNER);
    mvaddch(y + 1, x - 1, ACS_LLCORNER);
    mvaddch(y + 1, x, ACS_HLINE);
    mvaddch(y + 1, x + 1, ACS_HLINE);
    mvaddch(y + 1, x + 2, ACS_HLINE);
    mvaddch(y + 1, x + 3, ACS_HLINE);
    mvaddch(y + 1, x + 4, ACS_HLINE);
    mvaddch(y + 1, x + 5, ACS_HLINE);
    mvaddch(y + 1, x + 6, ACS_LRCORNER);

    // Cabeza
    mvaddch(y + 2, x, ACS_VLINE);

    // boca
    mvaddch(y + 2, x + 3, '_');

    mvaddch(y + 2, x + 5, ACS_VLINE);

    // barbilla
    mvaddch(y + 3, x, ACS_LLCORNER);
    mvaddch(y + 3, x + 5, ACS_LRCORNER);

    // cuerpo
    mvaddch(y + 3, x + 6, ACS_HLINE);
    mvaddch(y + 3, x - 1, ACS_HLINE);
    mvaddch(y + 5, x, ACS_LLCORNER);
    mvaddch(y + 5, x + 1, ACS_HLINE);
    mvaddch(y + 5, x + 2, ACS_HLINE);
    mvaddch(y + 5, x + 3, ACS_HLINE);
    mvaddch(y + 5, x + 4, ACS_HLINE);
    mvaddch(y + 5, x + 5, ACS_LRCORNER);

    // Brazo izquierdo
    mvaddch(y + 4, x - 2, ACS_VLINE);
    mvaddch(y + 4, x, ACS_VLINE);
    mvaddch(y + 5, x - 2, ACS_LLCORNER);
    // Brazo derecho
    mvaddch(y + 4, x + 5, ACS_VLINE);
    mvaddch(y + 4, x + 7, ACS_VLINE);
    mvaddch(y + 5, x + 7, ACS_LRCORNER);

    // piernas
    mvaddch(y + 6, x, ACS_VLINE);
    mvaddch(y + 6, x + 5, ACS_VLINE);
    mvaddch(y + 7, x, ACS_VLINE);
    mvaddch(y + 7, x + 5, ACS_VLINE);

    mvaddch(y + 8, x, ACS_LLCORNER);
    mvaddch(y + 8, x + 1, ACS_HLINE);
    mvaddch(y + 8, x + 2, ACS_HLINE);
    mvaddch(y + 7, x + 2, '_');
    mvaddch(y + 7, x + 2, '_');
    mvaddch(y + 7, x + 3, ACS_VLINE);
    mvaddch(y + 8, x + 3, ACS_BTEE);
    mvaddch(y + 7, x + 4, '_');
    mvaddch(y + 8, x + 5, '_');
    mvaddch(y + 8, x + 4, ACS_HLINE);
    mvaddch(y + 8, x + 5, ACS_HLINE);
    mvaddch(y + 8, x + 6, ACS_LRCORNER);

    // ojos
    mvaddch(y + 2, x + 2, '0');
    mvaddch(y + 2, x + 4, '0');

    if(hasSword){
        //cambio de mano
        mvaddch(y + 5, x + 7, ' ');
        mvaddch(y + 4, x + 8, ACS_URCORNER);
        mvaddch(y + 5, x + 7, ACS_HLINE);
        mvaddch(y + 5, x + 8, ACS_HLINE);
        mvaddch(y + 5, x + 9, ACS_LRCORNER);
        //mango
        mvaddch( y + 4, x + 8, ACS_URCORNER );
        mvaddch( y + 4, x + 9, ACS_ULCORNER );

        //filo izquierdo
        mvaddch( y + 3, x + 8, ACS_VLINE );
        mvaddch( y + 2, x + 8, ACS_VLINE );
        mvaddch( y + 1, x + 8, ACS_VLINE );
        mvaddch( y , x + 8, ACS_ULCORNER );
        //filo derecho
        mvaddch( y + 3, x + 9, ACS_VLINE );
        mvaddch( y + 2, x + 9, ACS_VLINE );
        mvaddch( y + 1, x + 9, ACS_VLINE );
        mvaddch( y , x + 9, ACS_URCORNER );
       
    }

    if( hasShield ){
        //cambiar cuerpo
        mvaddch(y + 5, x, ' ');
        mvaddch(y + 7, x, ' ');
        mvaddch(y + 6, x, ' ');
        //cambiar hombro
        mvaddch(y + 4, x - 2, ' ');
        mvaddch(y + 5, x - 2, ' ');
        mvaddch(y + 3, x - 2, ACS_ULCORNER);

        //parte izquierda del escudo
        mvaddch(y + 4, x - 2, ACS_HLINE);
        mvaddch(y + 4, x - 1, ACS_HLINE);
        mvaddch(y + 4, x - 3, ACS_HLINE);
        mvaddch(y + 4, x - 4, ACS_ULCORNER);
        mvaddch(y + 4, x , ACS_HLINE);
        mvaddch(y + 4, x + 1 , ACS_URCORNER);

        //parte derecha del escudo
        mvaddch(y + 5, x + 1 , ACS_VLINE);
        mvaddch(y + 6, x + 1 , ACS_VLINE);
        mvaddch(y + 7, x + 1 , '/');

        //parte izquierda del escudo
        mvaddch(y + 5, x - 4, ACS_VLINE);
        mvaddch(y + 6, x - 4 , ACS_VLINE);
        mvaddch(y + 7, x - 4 , '\\');

        //parte derecha del escudo
        mvaddch(y + 7, x , ACS_HLINE);
        mvaddch(y + 7 ,x - 2, ACS_HLINE);
        mvaddch(y + 7, x - 1, ACS_HLINE);
        mvaddch(y + 7, x - 3, ACS_HLINE);

        //cuadro del centro
        mvaddch( y + 5, x - 1, ACS_DIAMOND);
        mvaddch( y + 5, x - 2, ACS_DIAMOND);
        mvaddch( y + 6, x - 1, ACS_DIAMOND);
        mvaddch( y + 6, x - 2, ACS_DIAMOND);

    }
}

void removePlayer(int y, int x, bool hasSword, bool hasShield)
{

    // Sombrero o casco
    mvaddch(y, x, ' ');
    mvaddch(y, x + 1, ' ');
    mvaddch(y, x + 2, ' ');
    mvaddch(y, x + 3, ' ');
    mvaddch(y, x + 4, ' ');
    mvaddch(y, x + 5, ' ');
    mvaddch(y + 1, x - 1, ' ');
    mvaddch(y + 1, x, ' ');
    mvaddch(y + 1, x + 1, ' ');
    mvaddch(y + 1, x + 2, ' ');
    mvaddch(y + 1, x + 3, ' ');
    mvaddch(y + 1, x + 4, ' ');
    mvaddch(y + 1, x + 5, ' ');
    mvaddch(y + 1, x + 6, ' ');

    // Cabeza
    mvaddch(y + 2, x, ' ');

    // boca
    mvaddch(y + 2, x + 3, '_');

    mvaddch(y + 2, x + 5, ' ');

    // barbilla
    mvaddch(y + 3, x, ' ');
    mvaddch(y + 3, x + 5, ' ');

    // cuerpo
    mvaddch(y + 3, x + 6, ' ');
    mvaddch(y + 3, x - 1, ' ');
    mvaddch(y + 5, x, ' ');
    mvaddch(y + 5, x + 1, ' ');
    mvaddch(y + 5, x + 2, ' ');
    mvaddch(y + 5, x + 3, ' ');
    mvaddch(y + 5, x + 4, ' ');
    mvaddch(y + 5, x + 5, ' ');

    // Brazo izquierdo
    mvaddch(y + 4, x - 2, ' ');
    mvaddch(y + 4, x, ' ');
    mvaddch(y + 5, x - 2, ' ');
    // Brazo derecho
    mvaddch(y + 4, x + 5, ' ');
    mvaddch(y + 4, x + 7, ' ');
    mvaddch(y + 5, x + 7, ' ');

    // piernas
    mvaddch(y + 6, x, ' ');
    mvaddch(y + 6, x + 5, ' ');
    mvaddch(y + 7, x, ' ');
    mvaddch(y + 7, x + 5, ' ');

    mvaddch(y + 8, x, ' ');
    mvaddch(y + 8, x + 1, ' ');
    mvaddch(y + 8, x + 2, ' ');
    mvaddch(y + 7, x + 2, '_');
    mvaddch(y + 7, x + 2, '_');
    mvaddch(y + 7, x + 3, ' ');
    mvaddch(y + 8, x + 3, ' ');
    mvaddch(y + 7, x + 4, '_');
    mvaddch(y + 8, x + 5, '_');
    mvaddch(y + 8, x + 4, ' ');
    mvaddch(y + 8, x + 5, ' ');
    mvaddch(y + 8, x + 6, ' ');

    // ojos
    mvaddch(y + 2, x + 2, ' ');
    mvaddch(y + 2, x + 4, ' ');

    if(hasSword){
        //cambio de mano
        mvaddch(y + 5, x + 7, ' ');
        mvaddch(y + 4, x + 8, ' ');
        mvaddch(y + 5, x + 7, ' ');
        mvaddch(y + 5, x + 8, ' ');
        mvaddch(y + 5, x + 9, ' ');
        //mango
        mvaddch( y + 4, x + 8, ' ' );
        mvaddch( y + 4, x + 9, ' ' );

        //filo izquierdo
        mvaddch( y + 3, x + 8, ' ' );
        mvaddch( y + 2, x + 8, ' ' );
        mvaddch( y + 1, x + 8, ' ' );
        mvaddch( y , x + 8, ' ');
        //filo derecho
        mvaddch( y + 3, x + 9, ' ' );
        mvaddch( y + 2, x + 9, ' ' );
        mvaddch( y + 1, x + 9, ' ' );
        mvaddch( y , x + 9, ' ' );
       
    }


    if( hasShield ){
        //cambiar cuerpo
        mvaddch(y + 5, x, ' ');
        mvaddch(y + 7, x, ' ');
        mvaddch(y + 6, x, ' ');
        //cambiar hombro
        mvaddch(y + 4, x - 2, ' ');
        mvaddch(y + 5, x - 2, ' ');
        mvaddch(y + 3, x - 2, ' ');

        //parte izquierda del escudo
        mvaddch(y + 4, x - 2, ' ');
        mvaddch(y + 4, x - 1, ' ');
        mvaddch(y + 4, x - 3, ' ');
        mvaddch(y + 4, x - 4, ' ');
        mvaddch(y + 4, x , ' ');
        mvaddch(y + 4, x + 1 , ' ');

        //parte derecha del escudo
        mvaddch(y + 5, x + 1 , ' ');
        mvaddch(y + 6, x + 1 , ' ');
        mvaddch(y + 7, x + 1 , '/');

        //parte izquierda del escudo
        mvaddch(y + 5, x - 4, ' ');
        mvaddch(y + 6, x - 4 , ' ');
        mvaddch(y + 7, x - 4 , ' ');

        //parte derecha del escudo
        mvaddch(y + 7, x , ' ');
        mvaddch(y + 7 ,x - 2, ' ');
        mvaddch(y + 7, x - 1, ' ');
        mvaddch(y + 7, x - 3, ' ');

        //cuadro del centro
        mvaddch( y + 5, x - 1, ' ');
        mvaddch( y + 5, x - 2, ' ');
        mvaddch( y + 6, x - 1, ' ');
        mvaddch( y + 6, x - 2, ' ');

    }
}

void Player(int initialPositionY, int initialPositionX, string typePlayer, bool hasSword, bool hasShield)
{

    int maxPosition = 70;


    if (typePlayer == "static")
    {
        basePlayer(initialPositionY, initialPositionX, hasSword, hasShield);
    }
    else if (typePlayer == "dinamic")
    {
        int key;
        while ((key = getch()) != 'q')
        {
            switch (key)
            {
            case KEY_RIGHT:
                if (initialPositionX == maxPosition)
                {
                    break;
                }
                else
                {
                    removePlayer(initialPositionY, initialPositionX - 1, hasSword, hasShield);
                    basePlayer(initialPositionY, initialPositionX, hasSword, hasShield);
                    initialPositionX++;
                    refresh();
                }
                break;
            case KEY_LEFT:
                if (initialPositionX == 2)
                {
                    break;
                }
                else
                {
                    removePlayer(initialPositionY, initialPositionX + 1, hasSword, hasShield);
                    basePlayer(initialPositionY, initialPositionX, hasSword, hasShield);
                    initialPositionX--;
                    refresh();
                }
                break;
            default:
                break;
            }
        }
    }
}


void sword(int y, int x){
    mvaddch( y, x , ACS_ULCORNER);
    mvaddch( y - 1, x, ACS_LLCORNER);
    mvaddch( y, x - 1, ACS_HLINE);
    mvaddch( y - 1, x - 1, ACS_HLINE);
    mvaddch( y, x , ACS_VLINE);
    mvaddch( y - 1, x, ACS_VLINE);

    mvaddch( y - 1, x + 1, ACS_HLINE);
    mvaddch( y - 1, x + 2, ACS_HLINE);
    mvaddch( y - 1, x + 3, ACS_HLINE);
    mvaddch( y - 1, x + 4, ACS_HLINE);
    mvaddch( y - 1, x + 5, ACS_HLINE);
    mvaddch( y - 1, x + 6, ACS_HLINE);
    mvaddch( y - 1, x + 7, ACS_HLINE);

    mvaddch( y, x + 1, ACS_HLINE);
    mvaddch( y, x + 2, ACS_HLINE);
    mvaddch( y, x + 3, ACS_HLINE);
    mvaddch( y, x + 4, ACS_HLINE);
    mvaddch( y, x + 5, ACS_HLINE);
    mvaddch( y, x + 6, ACS_HLINE);
    mvaddch( y, x + 7, ACS_HLINE);

    
    mvaddch( y - 1, x + 8, ACS_URCORNER );
    mvaddch( y, x + 8, ACS_LRCORNER );
}

void removeSword(int y, int x){
    mvaddch( y, x , ' ');
    mvaddch( y - 1, x, ' ');
    mvaddch( y, x - 1, ' ');
    mvaddch( y - 1, x - 1, ' ');
    mvaddch( y, x , ' ');
    mvaddch( y - 1, x, ' ');

    mvaddch( y - 1, x + 1, ' ');
    mvaddch( y - 1, x + 2, ' ');
    mvaddch( y - 1, x + 3, ' ');
    mvaddch( y - 1, x + 4, ' ');
    mvaddch( y - 1, x + 5, ' ');
    mvaddch( y - 1, x + 6, ' ');
    mvaddch( y - 1, x + 7, ' ');

    mvaddch( y, x + 1, ' ');
    mvaddch( y, x + 2, ' ');
    mvaddch( y, x + 3, ' ');
    mvaddch( y, x + 4, ' ');
    mvaddch( y, x + 5, ' ');
    mvaddch( y, x + 6, ' ');
    mvaddch( y, x + 7, ' ');

    
    mvaddch( y - 1, x + 8, ' ');
    mvaddch( y, x + 8, ' ' );
}

void swordStroke(){

    int initialPositonX = 20;
    int initialPositionY = 9;

    int move = 0;

    while( true ){
       
       sword( initialPositionY, initialPositonX + move );
       refresh();
       this_thread::sleep_for( chrono::milliseconds(150) );
       removeSword( initialPositionY, initialPositonX + move );
       refresh();
       move++;

       if(move == 25) break;

    }
}

void ball(int y, int x){

    mvaddch( y + 2, x -1, '@' );

    mvaddch( y + 1, x , '@' );
    mvaddch( y + 2, x, '@' );
    mvaddch( y + 3, x, '@' );

    mvaddch( y , x + 1, '@' );
    mvaddch(y + 1, x + 1, '@' );
    mvaddch( y + 2, x + 1, '@' );
    mvaddch( y + 3, x + 1, '@' );
    mvaddch( y + 4,x + 1, '@' );

    mvaddch( y,  x + 2, '@' );
    mvaddch(y + 1,  x + 2, '@' );
    mvaddch( y + 2,  x + 2, '@' );
    mvaddch( y + 3,  x + 2, '@' );
    mvaddch( y + 4, x + 2, '@' );
    
    mvaddch( y, x + 3, '@' );
    mvaddch(y + 1, x + 3, '@' );
    mvaddch( y + 2, x + 3, '@' );
    mvaddch( y + 3, x + 3, '@' );
    mvaddch( y + 4, x + 3, '@' );

    mvaddch( y, x + 4, '@' );
    mvaddch(y + 1, x + 4, '@' );
    mvaddch( y + 2, x + 4, '@' );
    mvaddch( y + 3, x + 4, '@' );
    mvaddch( y + 4, x + 4, '@' );

    mvaddch(y + 1, x + 5, '@' );
    mvaddch( y + 2, x + 5, '@' );
    mvaddch( y + 3, x + 5, '@' );
    
    mvaddch( y + 1, x + 6, ACS_DIAMOND );
    mvaddch( y + 2, x + 6, ACS_DIAMOND );
    mvaddch( y + 3, x + 6, ACS_DIAMOND );
}

void removeBall(int y, int x){
   mvaddch( y + 2, x -1, ' ' );

    mvaddch( y + 1, x , ' ' );
    mvaddch( y + 2, x, ' ' );
    mvaddch( y + 3, x, ' ' );

    mvaddch( y , x + 1, ' ' );
    mvaddch(y + 1, x + 1, ' ' );
    mvaddch( y + 2, x + 1, ' ' );
    mvaddch( y + 3, x + 1, ' ' );
    mvaddch( y + 4,x + 1, ' ' );

    mvaddch( y,  x + 2, ' ' );
    mvaddch(y + 1,  x + 2, ' ' );
    mvaddch( y + 2,  x + 2, ' ' );
    mvaddch( y + 3,  x + 2, ' ' );
    mvaddch( y + 4, x + 2, ' ' );
    
    mvaddch( y, x + 3, ' ' );
    mvaddch(y + 1, x + 3, ' ' );
    mvaddch( y + 2, x + 3, ' ' );
    mvaddch( y + 3, x + 3, ' ' );
    mvaddch( y + 4, x + 3, ' ' );

    mvaddch( y, x + 4, ' ' );
    mvaddch(y + 1, x + 4, ' ' );
    mvaddch( y + 2, x + 4, ' ' );
    mvaddch( y + 3, x + 4, ' ' );
    mvaddch( y + 4, x + 4, ' ' );

    mvaddch(y + 1, x + 5, ' ' );
    mvaddch( y + 2, x + 5, ' ' );
    mvaddch( y + 3, x + 5, ' ' );
    
    mvaddch( y + 1, x + 6, ' ' );
    mvaddch( y + 2, x + 6, ' ' );
    mvaddch( y + 3, x + 6, ' ' );
}


void fireBall(){

    int initialPositonX = 20;
    int initialPositionY = 6;

    int move = 0;

    while( true ){
       
       ball( initialPositionY, initialPositonX + move );
       refresh();
       this_thread::sleep_for( chrono::milliseconds(150) );
       removeBall( initialPositionY, initialPositonX + move );
       refresh();
       move++;

       if(move == 25) break;

    }
}