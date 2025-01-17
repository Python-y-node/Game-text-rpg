#include "loader.h"

int main(){
    /* este es un texto quemado en este archivo se encuentran referencias de los metodos
     que se utilizan al manipular texto. */

    string texto1 = ""; 

    //Saber el tamaño de un texto
    cout << "Ingrese lo que quisiera escribir: \n";
    cin >> texto1;

    /* tanto la funcion length como size sirven para lo mismo y no hay alguna diferencia en usar
     una u otra */
    cout << "Usando length: " << texto1.length() << endl;
    cout << "Usando size: " << texto1.size() << endl;

    //----------------------------------------------------------------------------------------------------------//

    // Para saber si la cadena esta vacia usamos empty que retorna true si esta vacia 

    string texto2 = "";

    cout << ( texto2.empty() == true ) ? "Esta vacia\n" : "Esta llena\n";

    // Si quieres retornar el caracter desde una posicion usas ya sea at o la sintaxis []

    string texto3 = "Jugando Pelota";

    cout << "Caracter( usando at ) en el indice 4: " << texto3.at(4) << "\n";
    cout << "Caracter( Usando [] ) en el indice 4: " << texto3[4] << endl;

    /* la diferencia entre at y "[]", es que at lanza una excepcion cuando el indice esta fuera de rango
     y [] no la lanza lo que puede provocar errores no controlados */

    //----------------------------------------------------------------------------------------------------------//

    // Para insertar texto o caracter al final de el texto podemos usar append(), este solo insertara al final

    string texto4 = "Hablando con: ";
    string nuevaPlabra = "";

    cout << "Texto inicial: " << texto4 << "\n";

    cout << "Ingrese nuevo texto: \n";
    cin >> nuevaPlabra;

    texto4.append(nuevaPlabra);

    cout << "Su nueva frase es: " << texto4 << endl;


    //----------------------------------------------------------------------------------------------------------//

    // Para insertar texto en cualquier posicion que se te antoje puedes usar insert

    string texto5 = "Hola ";
    string nuevaPalabra = "";
    short index = 0; /* short es un valor entero a diferencia de int que usa 4 bytes para guardar y es un rango mayor
                      short solo usa 2 bytes y es un rango menor.*/

    cout << "Palabra incial: " << texto5 << "\n";

    cout << "Ingrese en que posicion de la palabra quiere insertar el texto: \n";
    cin >> index;

    cout << "Ingrese la nueva palabra: " << endl;
    cin >> nuevaPalabra;

    texto5.insert( index, nuevaPalabra );

    cout << "Su nueva frase es: " << texto5 << endl;

    //----------------------------------------------------------------------------------------------------------//

    /* Para eliminar caracteres de un string podemos usar el metodo erase, el cual recibe como parametros lo que 
     seria la posicion y la cantidad de carateres a eliminar desde la posicion indicada*/
    
    string texto6 = "Hola, buen mundo";

    cout << "Frase inicial: " << texto6 << endl;
               //posicion , cantidad de caracteres
    texto6.erase( 6, 4);

    cout << "Nueva frase: " << texto6 << endl;

    //----------------------------------------------------------------------------------------------------------//

    /* Para extraer una palabra o cadena de caracteres puedes usar el metodo substr, el cual recibe como parametros lo que
    seria la posicion y la cantidad de caracteres que quieres extraer*/
    string texto7 = "Juan no comio mucho";

    cout << "Frase inicial: " << texto7 << "\n";

    string extract = texto7.substr( 5, 2);

    cout << "palabra extraida" << extract << endl;

    //----------------------------------------------------------------------------------------------------------//

    /* Para saber si una palabra existe en una cadena podemos usar el metodo find, el cual recibe lo que seria como 
    parametro la palabra, tambien es de saber que este retorna la posicion de la primera coincidencia si no retorna
    npos que es una constante estatica (su significado es no posicion) */

    string texto8 = "Juan fue al mercado";
    size_t posicion = texto8.find("fue");

    cout << ( posicion != string::npos ) 
    ? "fue esta en la posicion: " + posicion
    : "No se encontro la palabra"; 
    
    cout << "\n";

}
