#include <iostream>
#include "./screens/index.h"

using namespace std;

int main(){
    initscr(); 
    curs_set(0); 
    keypad(stdscr, TRUE);
    Player(4,4);

    refresh(); 
    getch();   
    endwin();  
    
    

}