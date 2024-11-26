#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

// Ruta del archivo
const string USERS_FILE = "../db/users.txt";

// Función para verificar si un usuario ya existe
bool userExits(const string &username)
{
    fstream userFile;
    string line;

    userFile.open(USERS_FILE, ios::in); // Abrir archivo en modo lectura
    if (!userFile)
    {
        cerr << "Error: No se ha podido abrir el archivo de usuarios (" << USERS_FILE << ")." << endl;
        return false; // Archivo no encontrado o no se puede abrir
    }

    while (getline(userFile, line))
    {
        size_t usernamePos = line.find("username: ");
        size_t commaPos = line.find(",");
        if (usernamePos != string::npos && commaPos != string::npos)
        {
            string archivoUser = line.substr(usernamePos + 10, commaPos - (usernamePos + 10)); // Extrae el nombre de usuario
            if (archivoUser == username)
            {
                userFile.close();
                return true; // Usuario encontrado 
            }
        }
    }

    userFile.close();
    return false; // Usuario no encontrado
}

// Función para verificar si el usuario y la contraseña coinciden
bool userLogin(const string &username, const string &password)
{
    fstream userFile;
    string line;

    userFile.open(USERS_FILE, ios::in); // Abrir archivo en modo lectura
    if (!userFile)
    {
        cerr << "Error: No se ha podido abrir el archivo de usuarios (" << USERS_FILE << ")." << endl;
        return false;
    }

    while (getline(userFile, line))
    {
        size_t usernamePos = line.find("username: ");
        size_t commaPos = line.find(",");
        size_t passwordPos = line.find("password: ");

        if (usernamePos != string::npos && commaPos != string::npos && passwordPos != string::npos)
        {
            string archivoUser = line.substr(usernamePos + 10, commaPos - (usernamePos + 10)); // Extrae el nombre de usuario
            string archivoPassword = line.substr(passwordPos + 10); // Extrae la contraseña
            if (archivoUser == username && archivoPassword == password)
            {
                userFile.close();
                return true; // Usuario y contraseña coinciden
            }
        }
    }

    userFile.close();
    return false; // Usuario o contraseña incorrectos
}

// Función para crear un nuevo usuario
bool createUser(const string &username, const string &password)
{
    if (userExits(username))
    {
        cerr << "Error: El usuario ya existe." << endl;
        return false; // Usuario ya existe
    }

    fstream userFile;
    userFile.open(USERS_FILE, ios::in | ios::out | ios::app); // Abrir archivo en modo append
    if (!userFile)
    {
        cerr << "Error: No se ha podido abrir el archivo de usuarios (" << USERS_FILE << ") para escritura." << endl;
        return false;
    }

    // Verificar si el archivo termina con un salto de línea
    userFile.seekg(-1, ios::end); // Moverse al último carácter
    char lastChar;
    userFile.get(lastChar);

    if (lastChar != '\n') // Si no hay salto de línea, agregar uno
    {
        userFile.seekp(0, ios::end); // Moverse al final para escribir
        userFile.put('\n');
    }

    // Escribir el usuario y contraseña en una sola línea
    userFile << "username:" << username << ",password:" << password << endl;
    userFile.close();

    return true; // Usuario registrado exitosamente
}

int main()
{
    string username, password;

    cout << "Ingrese su usuario: ";
    cin >> username;

    cout << "Ingrese su contraseña: ";
    cin >> password;

    if (userExits(username))
    {
        if (userLogin(username, password))
        {
            cout << "Ingreso exitoso!" << endl;
        }
        else
        {
            cout << "Contraseña incorrecta." << endl;
        }
    }
    else
    {
        if (createUser(username, password))
        {
            cout << "Usuario registrado exitosamente!" << endl;
        }
        else
        {
            cout << "No se ha podido registrar el usuario." << endl;
        }
    }

    return 0;
}
