#include <fstream>
#include <string>

using namespace std;

bool userLogin( string user, string password ){

    fstream archivoUsuarios;
    string linea;
    archivoUsuarios.open("usuarios.txt", ios::in);  // Abrir archivo solo para lectura
    if (!archivoUsuarios) {
        return false;
    }

    while (getline(archivoUsuarios, linea)) {
        stringstream ss(linea);
        string archivoUser, archivoPassword;
        if (getline(ss, archivoUser, ' ') && getline(ss, archivoPassword)) {
            // Verificar si el usuario y la contraseña coinciden
            if (archivoUser == user && archivoPassword == password) {
                archivoUsuarios.close();
                return true;  // Usuario y contraseña correctos
            }
        }
    }

    archivoUsuarios.close();
    return false;  // Usuario no encontrado o contraseña incorrecta
}

bool userExits(){}

bool verifyPassword(){}

bool createUser(){
     fstream archivoUsuarios;
    string linea;

    // Verificar si el usuario ya existe en el archivo
    archivoUsuarios.open("usuarios.txt", ios::in);
    if (!archivoUsuarios) {
        cout << "Error al abrir el archivo de usuarios." << endl;
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