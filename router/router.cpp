

//importacion de pantallas
#include "../screens/menu_screen.cpp"
#include "../screens/login_user_screen.cpp"
#include "../screens/create_user_screen.cpp"

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