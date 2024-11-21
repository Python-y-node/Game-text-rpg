#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


// <<<<<<< HEAD
// int main(){

//     while (routerMenu >= 0)
//     {
//         if( routerMenu == 0 ){
//             menuScreen();
//         }

//         if( routerMenu == 1 ){
//             loginUserScreen();
//         }
//         if( routerMenu == 2 ){
//             createUserScreen();
//         }
//     }
    
// }
// =======
struct usuario {
    string user;
    string password;
};

// Función para cargar usuarios desde el archivo y verificar login
bool verificarLogin(string user, string password) {  // Pasado por valor
    fstream archivoUsuarios;
    string linea;
    archivoUsuarios.open("usuarios.txt", ios::in);  // Abrir archivo solo para lectura
    if (!archivoUsuarios) {
        cout << "Error al abrir el archivo de usuarios." << endl;
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

// Función para registrar un nuevo usuario
bool registrarUsuario(string user, string password) {  // Pasado por valor
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

int main() {
    string user, password;
    int opcion;

    cout << "Bienvenido, iniciemos la aventura" << endl;

    do {
        cout << "Elige una opcion: " << endl;
        cout << "1- Ingresar" << endl;
        cout << "2- Registrarse" << endl;
        cout << "3- Salir" << endl;
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Username: " << endl;
            cin >> user;
            cout << "Password: " << endl;
            cin >> password;

            bool usuarioVerificado = verificarLogin(user, password);

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

    } while (opcion != 3);

    return 0;
}
>>>>>>> adriana18
