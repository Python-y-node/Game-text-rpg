#include <iostream>

using namespace std;

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
        cout<< " Ingrese su usuario: "<<endl;
        cin >> user;
        cout<< " Ingrese su contraseña: "<<endl;
        cin >> password;
        
        for(int i = 0; i <10; i++) {
           usuarioEncontrado = users[i] == user;
        }
        cout<< " Usuario Encontrado: " << usuarioEncontrado<<endl;
        cout<< " Usuario 1: "<<users[0]<<endl;
        
        
        
        
        break;

    case 2:
        cout<< " Ingrese su usuario: "<<endl;
        cin >> user;
        cout<< " Ingrese su contraseña:"<<endl;
        cin >> password;
        users[usuariosRegistrados] = user;
        passwords[usuariosRegistrados] = password;
        usuariosRegistrados++; 
        cout<< " Usuario registrado correctamente ";
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
