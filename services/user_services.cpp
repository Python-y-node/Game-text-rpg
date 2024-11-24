#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool userLogin( string username, string password ){

}

bool userExits( string username ){
    
    fstream userFile;
    string line;
    
    userFile.open("usuarios.txt", ios::in);  // Abrir archivo solo para lectura
    
    if (!userFile) {
        return false;
    }

    while ( getline(userFile, line) ) {
       
        stringstream ss(line);
        
        string archivoUser, archivoPassword;

        if (getline(ss, archivoUser, ' ') && getline(ss, archivoPassword)) {
            // Verificar si el usuario y la contraseña coinciden
            if (archivoUser == username ) {
                userFile.close();
                return true;  // Usuario y contraseña correctos
            }
        }
    }

    userFile.close();
    return false;  // Usuario no encontrado o contraseña incorrecta
}

bool verifyPassword(){}

bool createUser(){
     fstream archivoUsuarios;
    string linea;

    // Verificar si el usuario ya existe en el archivo
    archivoUsuarios.open("usuarios.txt", ios::in);
    if (!archivoUsuarios) {
        return false;
    }

    while (getline(archivoUsuarios, linea)) {
        stringstream ss(linea);
        string archivoUser, archivoPassword;
        if (getline(ss, archivoUser, ' ') && getline(ss, archivoPassword)) {
            if (archivoUser == user) {
                archivoUsuarios.close();
                return false;  // El usuario ya existe
            }
        }
    }
    archivoUsuarios.close();

    // Si el usuario no existe, lo registramos
    archivoUsuarios.open("usuarios.txt", ios::app);  // Abrir archivo en modo "append" para agregar nuevos usuarios
    if (!archivoUsuarios) {
        cout << "Error al abrir el archivo de usuarios para registro." << endl;
        return false;
    }

    // Escribir el nuevo usuario y su contraseña en el archivo
    archivoUsuarios << user << " " << password << endl;
    archivoUsuarios.close();

    return true;  // Usuario registrado correctamente
}