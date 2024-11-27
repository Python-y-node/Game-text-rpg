#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct usuario {
    string user;
    string password;
};

// Función para cargar usuarios desde el archivo y verificar login
bool verificarLogin(string user, string password) {  // Pasado por valor
    // Esta libreria sirve pra esritur y lectura de archivos de texto 
    fstream archivoUsuarios;
    // Esta variable sirve para leer las lineas de el archivo de usuarios
    string linea;
    archivoUsuarios.open("usuarios.txt", ios::in);  // Abrir archivo solo para lectura
    // Valida si el archivo se pudo abrir o no
    if (!archivoUsuarios) {
        cout << "Error al abrir el archivo de usuarios." << endl;
        return false;
    }

    // Con este bucle leemos las lineas que contiene el archivo hasta encontrar las credenciales correctas
    while (getline(archivoUsuarios, linea)) {
        //Se usa para leer las lineas con espacios
        stringstream ss(linea);
        string archivoUser, archivoPassword;
        if (getline(ss, archivoUser, ' ') && getline(ss, archivoPassword)) {
            // Verificar si el usuario y la contraseña coinciden
            if (archivoUser == user && archivoPassword == password) {
                // Cerramos el archivo porque ya se encontro el usuario
                archivoUsuarios.close();
                return true;  // Usuario y contraseña correctos
            }
        }
    }

    archivoUsuarios.close();
    return false;  // Usuario no encontrado o contraseña incorrecta
}

// Función para registrar un nuevo usuario
// Devuelve true si el usuario ue registrado y false si no se pudo registrar
bool registrarUsuario(string user, string password) {  // Pasado por valor
    // Esta libreria sirve pra esritur y lectura de archivos de texto 
    fstream archivoUsuarios;
    // Esta variable sirve para leer las lineas de el archivo de usuarios
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

int main() {
    string user, password;
    int opcion;

    cout << "Bienvenido, iniciemos la aventura" << endl;

    // Ocupamos un do while para hacer un bucle hasta que el usuario digite la opcion salir
    do {
        cout << "Elige una opcion: " << endl;
        cout << "1- Ingresar" << endl;
        cout << "2- Registrarse" << endl;
        cout << "3- Salir" << endl;
        cin >> opcion;

        //Evaluamos la opcin que el cliente ha ingresado
        switch (opcion) {
        case 1:
            cout << "Username: " << endl;
            cin >> user;
            cout << "Password: " << endl;
            cin >> password;

            //Devuelve true si los datos son correctos o false si son incorrectos
            bool usuarioVerificado = verificarLogin(user, password); //mandamos a llamar a la funcion verificar login que le enviamos usuario y contrase;a

            if (usuarioVerificado) {
                cout << "Usuario encontrado correctamente, bienvenido." << endl;
            } else {
                cout << "Usuario o contraseña incorrecta, por favor intente de nuevo." << endl;
            }
            break;

        case 2:
            cout << "Ingrese su usuario: " << endl;
            cin >> user;
            cout << "Ingrese su contraseña: " << endl;
            cin >> password;

            //para ver si el usuario existe si no existe se registra 
            bool usuarioRegistrado = registrarUsuario(user, password);
            
            if (usuarioRegistrado) {
                cout << "Usuario registrado correctamente." << endl;
            } else {
                cout << "El usuario ya está registrado, por favor intente con otro nombre de usuario." << endl;
            }
            break;

        case 3:
            cout << "¡Haz salido correctamente!" << endl;
            break;

        default:
            cout << "--Has ingresado un número incorrecto--" << endl;
            break;
        }

    // Mientras la opcion sea diferente a 3 se sigue repitiendo el menu
    } while (opcion != 3);
    

//un for no se puede utilizar por que se usa para recorrer listas o arreglos por que es algo definido que se ejecute un x cantidad 
//do while me garantiza ejecutar el codigo almenos una vez y el while no me lo mostraria 


// El for se usa si es una cantidad especifica de veces, el while y do while si no conoces cuantas veces, pero el do while nos permite ejecutar almenos una vez el menu
    return 0;
}
