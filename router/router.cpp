#include "../loader/loader.h"

//importacion de pantallas
#include "../screens/index.h"

void router(){

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