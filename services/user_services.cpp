#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <filesystem>
#include <thread>
#include <chrono>

using namespace std;

// Ruta del archivo
string USERS_FILE = filesystem::current_path().string()  + "/services/db/users.txt";

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
bool userLogin(string username, string password)
{
    string line;

    ifstream userFile(USERS_FILE); // Abrir archivo en modo lectura

    if (!userFile.is_open() )
    {  
        return false;
    }

    while (getline(userFile, line))
    {
        
        size_t usernamePos = line.find_first_of(":");
        size_t commaPos = line.find(",");
        size_t passwordPos = line.find(":", commaPos);
        size_t finalPosition = line.find_last_not_of(" ");

        if (usernamePos != string::npos && commaPos != string::npos && passwordPos != string::npos)
        {
            string archivoUser = line.substr(usernamePos + 1 , ( commaPos - usernamePos - 1)); // Extrae el nombre de usuario
            string archivoPassword = line.substr(passwordPos + 1,( finalPosition - passwordPos) ); // Extrae la contraseña
            
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

