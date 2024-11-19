#include <iostream>
#include "./screens/index.h"


int main(){

    while (routerMenu >= 0)
    {
        if( routerMenu == 0 ){
            menuScreen();
        }

        if( routerMenu == 1 ){
            loginUserScreen();
        }
        if( routerMenu == 2 ){
            createUserScreen();
        }
    }
    
}