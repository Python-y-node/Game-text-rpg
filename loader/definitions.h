#include <iostream>

using namespace std;

//Variables globales
bool isAuthenticated = false;
bool isActive = false;
int avance = 0; // 5 valores posibles ( 0, 25, 50, 75, 100 )

//tipos
struct UserType{
    string username;
};


struct GameType
{
    int id =0;
    string userBelonging;
    int avance = 0;
    bool isSave = false;
};


//Definicion de variables globales


//funcion global que verifica si estas autenticado
bool isUserAuthenticated( ){
    return ( isAuthenticated == true ) ? true : false;
}

//definiciones de el cargador de la partida y el reinicio de ella
void loadGame(){
    
}

void unloadGame(){
 //TODO   
}