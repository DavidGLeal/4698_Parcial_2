// Librerias
#include <conio.h>       //Libreria que contiene la función getch() para capturar un cara´cter ingresado por teclado.
#include <stdio.h>       //Libreria que contiene las funciones de ingreso e impresion de datos scanf() y printf() respectivamente.
#include <iostream>      //Libreria que contiene las funciones de ingreso e impresión de datos cin y cout.
#include "NodoDoble.cpp" //Libreria que contiene la clase NodoDoble
using namespace std;
// Función principal main()
int main()
{
    // Declaración de variables locales de la función main()
    int dato, contarDatos = 0;
    char opc = ' ';
    char opcNodoDoble = ' ';
    int posicion = 0;
    NodoDoble *nodoDoble = new NodoDoble(); // Instancio un objeto pila de tipo NodoDoble, es la lista doblemente enlazada en donde se van a almacenar los datos ingresados a la lista.
    nodoDoble->setSiguiente(NULL);          // Hago que la lista doble apunte a NULL, la lista doble esta vacia.
    nodoDoble->setAnterior(NULL);
    do
    {
        system("cls");
        cout << "***   MENU   ***" << endl
             << endl; // Impresión del menu
        cout << "1.- Generar aleatoriamente la lista doblemente enlazada " << endl;
        cout << "2.- Mostrar lista doblemente enlazada" << endl;
        cout << "3.- Eliminar nodo" << endl;
        cout << "0.- Salir" << endl
             << endl;
        cout << "Elija una opcion valida" << endl;
        opc = getch(); // Capturo la opcíon ingresada
        switch (opc)
        {
        case '1': // Ingresar datos al inicio
            system("cls");
            cout << "***   GENERAR ALEATORIAMENTE LISTA DOBLEMENTE ENLAZADA   ***" << endl
                 << endl;
            cout << "Ingrese cuantos nodos desea generar: ";
            cin >> dato;
            nodoDoble->generarNodoDoble(&nodoDoble, dato, contarDatos);
            cout << "Se genero exitosamente la lista doblemente enlazada" << endl;
            system("PAUSE");

            break;
        case '2': // Mostar lista doblemente enlazada.
            system("cls");
            cout << "***   MOSTRAR LISTA DOBLEMENTE ENLAZADA   ***" << endl
                 << endl;
            nodoDoble->mostrarListaDoble(nodoDoble, contarDatos);
            system("PAUSE");
            break;
        case '3': // Eliminar nodo
            system("cls");
            cout << "***    ELIMINAR NODO   ***" << endl
                 << endl;
            nodoDoble->mostrarListaDoble(nodoDoble, contarDatos);
            do
            {
                cout << "\nIngrese posicion: ";
                cin >> posicion;
            } while (posicion > contarDatos);

            nodoDoble->eliminarNodoDoble(&nodoDoble, posicion, contarDatos);
            cout << "\nSe elimino correctamente el nodo" << endl;
            system("PAUSE");
            break;

        case '0': // Salir del programa
            system("cls");
            cout << "Gracias por utilizar este programa." << endl;
            system("PAUSE");
            exit(0);
            break;
        } // Fin switch()

    } while (opc != '1' || opc != '2' || opc != '3' || opc != '0'); // Utilizo una estructura de iteración do - while() para hacer que se repita la impresión del menú hasta que se ingrese el 0 para salir del programa.
} // Fin funcion principal main()
