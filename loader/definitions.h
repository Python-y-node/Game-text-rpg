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

struct PlayerType{
    string name = "";
    int maxDamagePerAttack = 0;
    int maxLife = 0;
    int shield = 0;
    string description = "";
};

struct FinalBossType
{
    string name = "";
    int maxDamagePerAttack = 0;
    int maxLife = 0;
    string description = "";
};

struct GameType
{
    int id =0;
    string userBelonging;
    int avance = 0;
    bool isSave = false;
};

//funcion global que verifica si estas autenticado
bool isUserAuthenticated( ){
    return ( isAuthenticated == true ) ? true : false;
}

//definiciones de el cargador de la partida y el reinicio de ella
void loadGame(){
   //TODO
}

void unloadGame(){
 //TODO   
}
