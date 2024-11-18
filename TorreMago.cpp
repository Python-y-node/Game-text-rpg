#include <iostream>
#include <cstdlib> // Para usar rand y srand
#include <ctime>   // Para usar time

using namespace std;

// Función para iniciar el juego
void inicializar_juego(int &item)
{
    // Generación un número aleatorio
    item = rand() % 3; // Número aleatorio entre 0 y 2
}

// Función para pedir la respuesta sobre si quiere jugar
bool pedir_respuesta()
{
    // Pedir respuesta sobre si quiere jugar
    cout << "Te apetece jugar? (sí/no): ";
    string respuesta;
    getline(cin, respuesta); // Capturamos la respuesta del jugador

    // Convertimos la respuesta a minúsculas para no tener problemas con mayúsculas/minúsculas
    for (auto &c : respuesta)
        c = tolower(c);

    if (respuesta == "si")
    {
        cout << "¡Genial! Vamos a jugar. \n";
        return true; // El jugador quiere jugar
    }
    else if (respuesta == "no")
    {
        cout << "Esta bien! Tal vez en otra ocasion. \n";
        return false; // El jugador no quiere jugar
    }
    else
    {
        cout << "Respuesta invalida. Por favor, responde con 'si' o 'no'. \n";
        return pedir_respuesta(); // Volver a pedir la respuesta si es inválida
    }
}

void pedir_intento(int &intento, int item)
{
    // Pedir al jugador que adivine la posición del objeto
    cout << "Introduce el número de la columna donde crees que está el objeto (1, 2 o 3): ";
    cin >> intento;

    // Validar que el intento esté en el rango correcto
    if (intento < 1 || intento > 3)
    {
        cout << "Opción inválida. Debes elegir un número entre 1 y 3. \n";
        pedir_intento(intento, item); // Volver a pedir el intento si es inválido
    }
}

// Función del juego
void jugar()
{
    // Esto nos asegura que el número que se genere no se repita entre intentos
    srand(static_cast<unsigned int>(time(0)));

    // Matriz de 1x3
    int matriz[3] = {0};

    // La posición del objeto se almacena en una variable
    int item;

    // Inicializamos el juego (y el objeto aleatorio)
    inicializar_juego(item);

    // Colocamos el objeto en la posición aleatoria
    matriz[item] = 1; // Marcamos con 1 la posición del objeto

    // Mostrar el mensaje de bienvenida
    cout << "Bienvenido a mis aposentos. Se que viniste en busca de mi poder para poder cumplir tu aventura. \n";
    cout << "Te tengo una propuesta. Que tal si jugamos un juego? \n";

    // Pedir si desea jugar
    if (!pedir_respuesta()) // Si no quiere jugar, terminamos
    {
        return;
    }

    // Continuar con la lógica del juego
    int intento;
    pedir_intento(intento, item); // Pedir el intento al jugador

    // Comprobar si la adivinanza es correcta
    if (intento - 1 == item)
    {
        cout << "Felicidades! Has ganado. Por lo tanto, te entrego mi poder para que puedas continuar. \n";
    }
    else
    {
        cout << "Lo siento pero has fallado. No has mostrado ser digno de mi poder. \n";
    }

    cout << "Hasta la proxima, Aventurero.\n";
}

int main()
{
    jugar(); // Iniciar el juego
    return 0;
}
