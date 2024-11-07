//si ustedes definen un archivo .h que es un archivo de C, este archivo se tomara
// como una libreria, lo que hace c++ a la hora de compilar es hacer un solo archivo
// donde todo el codigo definido en varios archivos sea trasnformado en uno solo pero 
// a un lenguaje de bajo nivel( binario o ensamblador), por ende podriamos definir todas
// nuestras importaciones necesarias en un archivo y solo importar ese archivo en los demas
// archivos donde queramos usar las librerias, estos archivos normalmente se les llama:
// "archivo barril"

//libreria que usamos para manipular archivos
#include <fstream>

//libreria estandar que usamos para leer entrada y dar salidas ( en la terminal)
#include <iostream>

// importacion de libreria curses
#include <ncurses.h>

//declaracion del espacio de nombres std
using namespace std;

