#include <iostream>
#include "./screens/index.h"

using namespace std;

<<<<<<< HEAD
int main(){
    finalFightScreen();  
}
=======
int main (){

    
    string users[10];
    string passwords[10];
    string user, password;
    bool usuarioEncontrado;
    int opcion, usuariosRegistrados = 0;

    cout << "Bienvenido, iniciemos la aventura "<< endl;

do{
    cout << "Elige una opcion: "<<endl;
    cout << "1- Ingresar "<<endl;
    cout << "2- Registrarse "<<endl;
    cout << "3- Salir "<<endl;
    cin >>opcion;
    
    switch (opcion)
    {
    case 1:
        cout << "Ingrese su usuario: " << endl;
        cin >> user;
        cout << "Ingrese su contraseña: " << endl;
        cin >> password;
        
        usuarioEncontrado = false;
        for(int i = 0; i < usuariosRegistrados; i++) {
            if (users[i] == user && passwords[i] == password){
                usuarioEncontrado = true;
                cout << "Usuario Encontrado: " << usuarioEncontrado << endl;
                cout << "Usuario 1: " << users[0] << endl;
                break;
            }
           if (usuarioEncontrado){
            cout<< "Usuario encontrado correctamente, bienvenido "<<endl;
           } else{
            cout<< "Usuario o contraseña incorrecta, por favor intente de nuevo "<<endl;
           }
           break;

        }
        
        
        
        
        break;

    case 2:
        cout<< " Ingrese su usuario: "<<endl;
        cin >> user;
        cout<< " Ingrese su contraseña:"<<endl;
        cin >> password;
        
        usuarioEncontrado = false; //booleano para verdadero o falso
        for ( int i = 0; i < usuarioEncontrado; i++){ 
            if (users[i] == user){
                usuarioEncontrado = true;
                break;
            }
          
        }
          if (usuariosRegistrados){
                cout<< " Usuario registrado, por favor intente con otro nombre de usuario "<<endl;
            } else{
                users[usuariosRegistrados] = user;
                passwords[usuariosRegistrados] = password;
                usuariosRegistrados++; 
                cout<< " Usuario registrado correctamente ";
            }
        break;

    case 3: 
        cout<< " ¡Haz salido correctamente!  "<<endl;
        break;

    
    default: 
        cout<< " --Haz ingresado un numero incorrecto-- ";
        break;
    }

    
}  while ( opcion != 3);

  return 0;
}
>>>>>>> de843575a72d3d8bd9d60c6dd0ee3c7d962cd404
