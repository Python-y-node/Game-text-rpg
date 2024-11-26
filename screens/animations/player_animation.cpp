#include <ncurses.h>
#include <iostream>
#include <thread>
#include <chrono>

#include "../../loader/loader.h"

void basePlayer(WINDOW *window, int y, int x, bool hasSword, bool hasShield)
{
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);

    wattron( window, A_STANDOUT);
    wattron( window, COLOR_PAIR(2));
        // Sombrero o casco
        mvwaddch(window, y, x, ACS_ULCORNER);
        mvwaddch(window, y, x + 1, ACS_HLINE);
        mvwaddch(window, y, x + 2, ACS_HLINE);
        mvwaddch(window, y, x + 3, ACS_HLINE);
        mvwaddch(window, y, x + 4, ACS_HLINE);
        mvwaddch(window, y, x + 5, ACS_URCORNER);
        mvwaddch(window, y + 1, x - 1, ACS_LLCORNER);
        mvwaddch(window, y + 1, x, ACS_HLINE);
        mvwaddch(window, y + 1, x + 1, ACS_HLINE);
        mvwaddch(window, y + 1, x + 2, ACS_HLINE);
        mvwaddch(window, y + 1, x + 3, ACS_HLINE);
        mvwaddch(window, y + 1, x + 4, ACS_HLINE);
        mvwaddch(window, y + 1, x + 5, ACS_HLINE);
        mvwaddch(window, y + 1, x + 6, ACS_LRCORNER);
    wattroff( window, A_STANDOUT);
    wattroff( window, COLOR_PAIR(2));

    // Cabeza
    mvwaddch(window, y + 2, x, ACS_VLINE);

    // boca
    mvwaddch(window, y + 2, x + 3, '_');

    mvwaddch(window, y + 2, x + 5, ACS_VLINE);

    // barbilla
    mvwaddch(window, y + 3, x, ACS_LLCORNER);
    mvwaddch(window, y + 3, x + 5, ACS_LRCORNER);

    wattron( window, COLOR_PAIR(4));
        // cuerpo
        mvwaddch(window, y + 3, x + 6, ACS_HLINE);
        mvwaddch(window, y + 3, x - 1, ACS_HLINE);
        mvwaddch(window, y + 5, x, ACS_LLCORNER);
        mvwaddch(window, y + 5, x + 1, ACS_HLINE);
        mvwaddch(window, y + 5, x + 2, ACS_HLINE);
        mvwaddch(window, y + 5, x + 3, ACS_HLINE);
        mvwaddch(window, y + 5, x + 4, ACS_HLINE);
        mvwaddch(window, y + 5, x + 5, ACS_LRCORNER);

        // Brazo izquierdo
        mvwaddch(window, y + 4, x - 2, ACS_VLINE);
        mvwaddch(window, y + 4, x, ACS_VLINE);
        mvwaddch(window, y + 5, x - 2, ACS_LLCORNER);
        // Brazo derecho
        mvwaddch(window, y + 4, x + 5, ACS_VLINE);
        mvwaddch(window, y + 4, x + 7, ACS_VLINE);
        mvwaddch(window, y + 5, x + 7, ACS_LRCORNER);
    wattroff( window, COLOR_PAIR(4));

    // piernas
    mvwaddch(window, y + 6, x, ACS_VLINE);
    mvwaddch(window, y + 6, x + 5, ACS_VLINE);
    mvwaddch(window, y + 7, x, ACS_VLINE);
    mvwaddch(window, y + 7, x + 5, ACS_VLINE);

    mvwaddch(window, y + 8, x, ACS_LLCORNER);
    mvwaddch(window, y + 8, x + 1, ACS_HLINE);
    mvwaddch(window, y + 8, x + 2, ACS_HLINE);
    mvwaddch(window, y + 7, x + 2, '_');
    mvwaddch(window, y + 7, x + 2, '_');
    mvwaddch(window, y + 7, x + 3, ACS_VLINE);
    mvwaddch(window, y + 8, x + 3, ACS_BTEE);
    mvwaddch(window, y + 7, x + 4, '_');
    mvwaddch(window, y + 8, x + 5, '_');
    mvwaddch(window, y + 8, x + 4, ACS_HLINE);
    mvwaddch(window, y + 8, x + 5, ACS_HLINE);
    mvwaddch(window, y + 8, x + 6, ACS_LRCORNER);

    wattron( window, COLOR_PAIR(3));
    // ojos
        mvwaddch(window, y + 2, x + 2, '0');
        mvwaddch(window, y + 2, x + 4, '0');
    wattroff( window, COLOR_PAIR(3));

    if(hasSword){
        //cambio de mano
        mvwaddch(window, y + 5, x + 7, ' ');
        mvwaddch(window, y + 4, x + 8, ACS_URCORNER);
        mvwaddch(window, y + 5, x + 7, ACS_HLINE);
        mvwaddch(window, y + 5, x + 8, ACS_HLINE);
        mvwaddch(window, y + 5, x + 9, ACS_LRCORNER);

        //mango
        mvwaddch(window,  y + 4, x + 8, ACS_URCORNER );
        mvwaddch(window,  y + 4, x + 9, ACS_ULCORNER );

        wattron( window, COLOR_PAIR(2));
            //filo izquierdo
            mvwaddch(window,  y + 3, x + 8, ACS_VLINE );
            mvwaddch(window,  y + 2, x + 8, ACS_VLINE );
            mvwaddch(window,  y + 1, x + 8, ACS_VLINE );
            mvwaddch(window,  y , x + 8, ACS_ULCORNER );
            //filo derecho
            mvwaddch(window,  y + 3, x + 9, ACS_VLINE );
            mvwaddch(window,  y + 2, x + 9, ACS_VLINE );
            mvwaddch(window,  y + 1, x + 9, ACS_VLINE );
            mvwaddch(window,  y , x + 9, ACS_URCORNER );
        wattroff( window, COLOR_PAIR(2));
       
    }

    if( hasShield ){
        //cambiar cuerpo
        mvwaddch(window, y + 5, x, ' ');
        mvwaddch(window, y + 7, x, ' ');
        mvwaddch(window, y + 6, x, ' ');
        
        wattron( window, COLOR_PAIR(4));
            //cambiar hombro
            mvwaddch(window, y + 4, x - 2, ' ');
            mvwaddch(window, y + 5, x - 2, ' ');
            mvwaddch(window, y + 3, x - 2, ACS_ULCORNER);
        wattroff( window, COLOR_PAIR(4));

        wattron( window, A_STANDOUT);
        wattron( window, COLOR_PAIR(2));
            //parte izquierda del escudo
            mvwaddch(window, y + 4, x - 2, ACS_HLINE);
            mvwaddch(window, y + 4, x - 1, ACS_HLINE);
            mvwaddch(window, y + 4, x - 3, ACS_HLINE);
            mvwaddch(window, y + 4, x - 4, ACS_ULCORNER);
            mvwaddch(window, y + 4, x , ACS_HLINE);
            mvwaddch(window, y + 4, x + 1 , ACS_URCORNER);

            //parte derecha del escudo
            mvwaddch(window, y + 5, x + 1 , ACS_VLINE);
            mvwaddch(window, y + 6, x + 1 , ACS_VLINE);
            mvwaddch(window, y + 7, x + 1 , '/');

            //parte izquierda del escudo
            mvwaddch(window, y + 5, x - 4, ACS_VLINE);
            mvwaddch(window, y + 6, x - 4 , ACS_VLINE);
            mvwaddch(window, y + 7, x - 4 , '\\');

            //parte derecha del escudo
            mvwaddch(window, y + 7, x , ACS_HLINE);
            mvwaddch(window, y + 7 ,x - 2, ACS_HLINE);
            mvwaddch(window, y + 7, x - 1, ACS_HLINE);
            mvwaddch(window, y + 7, x - 3, ACS_HLINE);
        wattroff( window, A_STANDOUT);
        wattroff( window, COLOR_PAIR(2));

        wattron( window, COLOR_PAIR(2));
            //cuadro del centro
            mvwaddch(window,  y + 5, x - 1, ACS_DIAMOND);
            mvwaddch(window,  y + 5, x - 2, ACS_DIAMOND);
            mvwaddch(window,  y + 6, x - 1, ACS_DIAMOND);
            mvwaddch(window,  y + 6, x - 2, ACS_DIAMOND);
        wattroff( window, COLOR_PAIR(2));
    }
}

void removePlayer(WINDOW* window, int y, int x, bool hasSword, bool hasShield)
{

    // Sombrero o casco
    mvwaddch(window, y, x, ' ');
    mvwaddch(window, y, x + 1, ' ');
    mvwaddch(window, y, x + 2, ' ');
    mvwaddch(window, y, x + 3, ' ');
    mvwaddch(window, y, x + 4, ' ');
    mvwaddch(window, y, x + 5, ' ');
    mvwaddch(window, y + 1, x - 1, ' ');
    mvwaddch(window, y + 1, x, ' ');
    mvwaddch(window, y + 1, x + 1, ' ');
    mvwaddch(window, y + 1, x + 2, ' ');
    mvwaddch(window, y + 1, x + 3, ' ');
    mvwaddch(window, y + 1, x + 4, ' ');
    mvwaddch(window, y + 1, x + 5, ' ');
    mvwaddch(window, y + 1, x + 6, ' ');

    // Cabeza
    mvwaddch(window, y + 2, x, ' ');

    // boca
    mvwaddch(window, y + 2, x + 3, '_');

    mvwaddch(window, y + 2, x + 5, ' ');

    // barbilla
    mvwaddch(window, y + 3, x, ' ');
    mvwaddch(window, y + 3, x + 5, ' ');

    // cuerpo
    mvwaddch(window, y + 3, x + 6, ' ');
    mvwaddch(window, y + 3, x - 1, ' ');
    mvwaddch(window, y + 5, x, ' ');
    mvwaddch(window, y + 5, x + 1, ' ');
    mvwaddch(window, y + 5, x + 2, ' ');
    mvwaddch(window, y + 5, x + 3, ' ');
    mvwaddch(window, y + 5, x + 4, ' ');
    mvwaddch(window, y + 5, x + 5, ' ');

    // Brazo izquierdo
    mvwaddch(window, y + 4, x - 2, ' ');
    mvwaddch(window, y + 4, x, ' ');
    mvwaddch(window, y + 5, x - 2, ' ');
    // Brazo derecho
    mvwaddch(window, y + 4, x + 5, ' ');
    mvwaddch(window, y + 4, x + 7, ' ');
    mvwaddch(window, y + 5, x + 7, ' ');

    // piernas
    mvwaddch(window, y + 6, x, ' ');
    mvwaddch(window, y + 6, x + 5, ' ');
    mvwaddch(window, y + 7, x, ' ');
    mvwaddch(window, y + 7, x + 5, ' ');

    mvwaddch(window, y + 8, x, ' ');
    mvwaddch(window, y + 8, x + 1, ' ');
    mvwaddch(window, y + 8, x + 2, ' ');
    mvwaddch(window, y + 7, x + 2, '_');
    mvwaddch(window, y + 7, x + 2, '_');
    mvwaddch(window, y + 7, x + 3, ' ');
    mvwaddch(window, y + 8, x + 3, ' ');
    mvwaddch(window, y + 7, x + 4, '_');
    mvwaddch(window, y + 8, x + 5, '_');
    mvwaddch(window, y + 8, x + 4, ' ');
    mvwaddch(window, y + 8, x + 5, ' ');
    mvwaddch(window, y + 8, x + 6, ' ');

    // ojos
    mvwaddch(window, y + 2, x + 2, ' ');
    mvwaddch(window, y + 2, x + 4, ' ');

    if(hasSword){
        //cambio de mano
        mvwaddch(window, y + 5, x + 7, ' ');
        mvwaddch(window, y + 4, x + 8, ' ');
        mvwaddch(window, y + 5, x + 7, ' ');
        mvwaddch(window, y + 5, x + 8, ' ');
        mvwaddch(window, y + 5, x + 9, ' ');
        //mango
        mvwaddch(window,  y + 4, x + 8, ' ' );
        mvwaddch(window,  y + 4, x + 9, ' ' );

        //filo izquierdo
        mvwaddch(window,  y + 3, x + 8, ' ' );
        mvwaddch(window,  y + 2, x + 8, ' ' );
        mvwaddch(window,  y + 1, x + 8, ' ' );
        mvwaddch(window,  y , x + 8, ' ');
        //filo derecho
        mvwaddch(window,  y + 3, x + 9, ' ' );
        mvwaddch(window,  y + 2, x + 9, ' ' );
        mvwaddch(window,  y + 1, x + 9, ' ' );
        mvwaddch(window,  y , x + 9, ' ' );
       
    }


    if( hasShield ){
        //cambiar cuerpo
        mvwaddch(window, y + 5, x, ' ');
        mvwaddch(window, y + 7, x, ' ');
        mvwaddch(window, y + 6, x, ' ');
        //cambiar hombro
        mvwaddch(window, y + 4, x - 2, ' ');
        mvwaddch(window, y + 5, x - 2, ' ');
        mvwaddch(window, y + 3, x - 2, ' ');

        //parte izquierda del escudo
        mvwaddch(window, y + 4, x - 2, ' ');
        mvwaddch(window, y + 4, x - 1, ' ');
        mvwaddch(window, y + 4, x - 3, ' ');
        mvwaddch(window, y + 4, x - 4, ' ');
        mvwaddch(window, y + 4, x , ' ');
        mvwaddch(window, y + 4, x + 1 , ' ');

        //parte derecha del escudo
        mvwaddch(window, y + 5, x + 1 , ' ');
        mvwaddch(window, y + 6, x + 1 , ' ');
        mvwaddch(window, y + 7, x + 1 , '/');

        //parte izquierda del escudo
        mvwaddch(window, y + 5, x - 4, ' ');
        mvwaddch(window, y + 6, x - 4 , ' ');
        mvwaddch(window, y + 7, x - 4 , ' ');

        //parte derecha del escudo
        mvwaddch(window, y + 7, x , ' ');
        mvwaddch(window, y + 7 ,x - 2, ' ');
        mvwaddch(window, y + 7, x - 1, ' ');
        mvwaddch(window, y + 7, x - 3, ' ');

        //cuadro del centro
        mvwaddch(window,  y + 5, x - 1, ' ');
        mvwaddch(window,  y + 5, x - 2, ' ');
        mvwaddch(window,  y + 6, x - 1, ' ');
        mvwaddch(window,  y + 6, x - 2, ' ');

    }
}

void Player(WINDOW* window ,int initialPositionY, int initialPositionX, std::string typePlayer, bool hasSword, bool hasShield)
{

    int maxPosition = 70;


    if (typePlayer == "static")
    {
        basePlayer(window, initialPositionY, initialPositionX, hasSword, hasShield);
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
                    removePlayer(window, initialPositionY, initialPositionX - 1, hasSword, hasShield);
                    basePlayer(window, initialPositionY, initialPositionX, hasSword, hasShield);
                    initialPositionX++;
                    wrefresh(window);
                }
                break;
            case KEY_LEFT:
                if (initialPositionX == 2)
                {
                    break;
                }
                else
                {
                    removePlayer(window, initialPositionY, initialPositionX + 1, hasSword, hasShield);
                    basePlayer(window, initialPositionY, initialPositionX, hasSword, hasShield);
                    initialPositionX--;
                    wrefresh(window);
                }
                break;
            default:
                break;
            }
        }
    }
}


void sword(WINDOW* window, int y, int x){
    mvwaddch(window,  y, x , ACS_ULCORNER);
    mvwaddch(window,  y - 1, x, ACS_LLCORNER);
    mvwaddch(window,  y, x - 1, ACS_HLINE);
    mvwaddch(window,  y - 1, x - 1, ACS_HLINE);
    mvwaddch(window,  y, x , ACS_VLINE);
    mvwaddch(window,  y - 1, x, ACS_VLINE);

    mvwaddch(window,  y - 1, x + 1, ACS_HLINE);
    mvwaddch(window,  y - 1, x + 2, ACS_HLINE);
    mvwaddch(window,  y - 1, x + 3, ACS_HLINE);
    mvwaddch(window,  y - 1, x + 4, ACS_HLINE);
    mvwaddch(window,  y - 1, x + 5, ACS_HLINE);
    mvwaddch(window,  y - 1, x + 6, ACS_HLINE);
    mvwaddch(window,  y - 1, x + 7, ACS_HLINE);

    mvwaddch(window,  y, x + 1, ACS_HLINE);
    mvwaddch(window,  y, x + 2, ACS_HLINE);
    mvwaddch(window,  y, x + 3, ACS_HLINE);
    mvwaddch(window,  y, x + 4, ACS_HLINE);
    mvwaddch(window,  y, x + 5, ACS_HLINE);
    mvwaddch(window,  y, x + 6, ACS_HLINE);
    mvwaddch(window,  y, x + 7, ACS_HLINE);

    
    mvwaddch(window,  y - 1, x + 8, ACS_URCORNER );
    mvwaddch(window,  y, x + 8, ACS_LRCORNER );
}

void removeSword(WINDOW* window, int y, int x){
    mvwaddch(window,  y, x , ' ');
    mvwaddch(window,  y - 1, x, ' ');
    mvwaddch(window,  y, x - 1, ' ');
    mvwaddch(window,  y - 1, x - 1, ' ');
    mvwaddch(window,  y, x , ' ');
    mvwaddch(window,  y - 1, x, ' ');

    mvwaddch(window,  y - 1, x + 1, ' ');
    mvwaddch(window,  y - 1, x + 2, ' ');
    mvwaddch(window,  y - 1, x + 3, ' ');
    mvwaddch(window,  y - 1, x + 4, ' ');
    mvwaddch(window,  y - 1, x + 5, ' ');
    mvwaddch(window,  y - 1, x + 6, ' ');
    mvwaddch(window,  y - 1, x + 7, ' ');

    mvwaddch(window,  y, x + 1, ' ');
    mvwaddch(window,  y, x + 2, ' ');
    mvwaddch(window,  y, x + 3, ' ');
    mvwaddch(window,  y, x + 4, ' ');
    mvwaddch(window,  y, x + 5, ' ');
    mvwaddch(window,  y, x + 6, ' ');
    mvwaddch(window,  y, x + 7, ' ');

    
    mvwaddch(window,  y - 1, x + 8, ' ');
    mvwaddch(window,  y, x + 8, ' ' );
}

void swordStroke(WINDOW* window){

    int initialPositonX = 20;
    int initialPositionY = 9;

    int move = 0;

    while( true ){
       
       sword(window, initialPositionY, initialPositonX + move );
       wrefresh(window);
       std::this_thread::sleep_for( std::chrono::milliseconds(80) );
       removeSword(window, initialPositionY, initialPositonX + move );
       wrefresh(window);
       move++;

       if(move == 30) break;
    }

    bossMaxLife -=70;
}

void ball(WINDOW* window, int y, int x){

    init_pair( 5, COLOR_RED, COLOR_BLACK );

    wattron( window, A_STANDOUT);
    wattron( window, COLOR_PAIR(5));
        mvwaddch(window, y + 2, x -1, ACS_DIAMOND );

        mvwaddch(window, y + 1, x , ACS_DIAMOND );
        mvwaddch(window, y + 2, x, ACS_DIAMOND );
        mvwaddch(window, y + 3, x, ACS_DIAMOND );

        mvwaddch(window, y , x + 1, ACS_DIAMOND );
        mvwaddch(window,y + 1, x + 1, ACS_DIAMOND );
        mvwaddch(window, y + 2, x + 1, ACS_DIAMOND );
        mvwaddch(window, y + 3, x + 1, ACS_DIAMOND );
        mvwaddch(window, y + 4,x + 1, ACS_DIAMOND );

        mvwaddch(window, y,  x + 2, ACS_DIAMOND );
        mvwaddch(window,y + 1,  x + 2, ACS_DIAMOND );
        mvwaddch(window, y + 2,  x + 2, ACS_DIAMOND );
        mvwaddch(window, y + 3,  x + 2, ACS_DIAMOND );
        mvwaddch(window, y + 4, x + 2, ACS_DIAMOND );
        
        mvwaddch(window, y, x + 3, ACS_DIAMOND );
        mvwaddch(window,y + 1, x + 3, ACS_DIAMOND );
        mvwaddch(window, y + 2, x + 3, ACS_DIAMOND );
        mvwaddch(window, y + 3, x + 3, ACS_DIAMOND );
        mvwaddch(window, y + 4, x + 3, ACS_DIAMOND );

        mvwaddch(window, y, x + 4, ACS_DIAMOND );
        mvwaddch(window,y + 1, x + 4, ACS_DIAMOND );
        mvwaddch(window, y + 2, x + 4, ACS_DIAMOND );
        mvwaddch(window, y + 3, x + 4, ACS_DIAMOND );
        mvwaddch(window, y + 4, x + 4, ACS_DIAMOND );

        mvwaddch(window,y + 1, x + 5, ACS_DIAMOND );
        mvwaddch(window, y + 2, x + 5, ACS_DIAMOND );
        mvwaddch(window, y + 3, x + 5, ACS_DIAMOND );
        
        mvwaddch(window, y + 1, x + 6, ACS_DIAMOND );
        mvwaddch(window, y + 2, x + 6, ACS_DIAMOND );
        mvwaddch(window, y + 3, x + 6, ACS_DIAMOND );
    wattroff( window, A_STANDOUT);
    wattroff( window, COLOR_PAIR(5));
}

void removeBall(WINDOW* window, int y, int x){
   mvwaddch(window,  y + 2, x -1, ' ' );

    mvwaddch(window,  y + 1, x , ' ' );
    mvwaddch(window,  y + 2, x, ' ' );
    mvwaddch(window,  y + 3, x, ' ' );

    mvwaddch(window,  y , x + 1, ' ' );
    mvwaddch(window, y + 1, x + 1, ' ' );
    mvwaddch(window,  y + 2, x + 1, ' ' );
    mvwaddch(window,  y + 3, x + 1, ' ' );
    mvwaddch(window,  y + 4,x + 1, ' ' );

    mvwaddch(window,  y,  x + 2, ' ' );
    mvwaddch(window, y + 1,  x + 2, ' ' );
    mvwaddch(window,  y + 2,  x + 2, ' ' );
    mvwaddch(window,  y + 3,  x + 2, ' ' );
    mvwaddch(window,  y + 4, x + 2, ' ' );
    
    mvwaddch(window,  y, x + 3, ' ' );
    mvwaddch(window, y + 1, x + 3, ' ' );
    mvwaddch(window,  y + 2, x + 3, ' ' );
    mvwaddch(window,  y + 3, x + 3, ' ' );
    mvwaddch(window,  y + 4, x + 3, ' ' );

    mvwaddch(window,  y, x + 4, ' ' );
    mvwaddch(window, y + 1, x + 4, ' ' );
    mvwaddch(window,  y + 2, x + 4, ' ' );
    mvwaddch(window,  y + 3, x + 4, ' ' );
    mvwaddch(window,  y + 4, x + 4, ' ' );

    mvwaddch(window, y + 1, x + 5, ' ' );
    mvwaddch(window,  y + 2, x + 5, ' ' );
    mvwaddch(window,  y + 3, x + 5, ' ' );
    
    mvwaddch(window,  y + 1, x + 6, ' ' );
    mvwaddch(window,  y + 2, x + 6, ' ' );
    mvwaddch(window,  y + 3, x + 6, ' ' );
}


void fireBall(WINDOW* window){

    int initialPositonX = 20;
    int initialPositionY = 6;

    int move = 0;

    while( true ){
       
       ball( window, initialPositionY, initialPositonX + move );
       wrefresh(window);
       std::this_thread::sleep_for( std::chrono::milliseconds(80) );
       removeBall( window, initialPositionY, initialPositonX + move );
       wrefresh(window);
       move++;

       if(move == 30) break;
    }
    bossMaxLife -=170;
}