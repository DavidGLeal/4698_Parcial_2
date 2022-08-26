/*
Universidad de las Fuerzas Armadas "ESPE"
Departamento de Ciencias de la Computación
Ingeniería en Sistemas e Informática

Integrantes:		   Jonathan Lema, Kelly Landazuri, David Llerena
Materia:  Estructuras de Datos

Enunciado:   	Implementar una función que recibe una lista de enteros  y un número
entero n de forma que se cuente cuantas veces esta el número dentro de la lista.
*/

// Librerias
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include "Nodo.h"
#include <math.h>
using namespace std;


int main(){
    int productoTodos = 1;
    char op = ' ';
    char op2 = ' ';
    int num;
    Nodo *cabeza;
    int numero;
    int contador = 0;
    cabeza = new Nodo();
    do
    {
        system("cls");
        cout << "***   EJERCICIO 1 LISTAS SIMPLES   ***" << endl
             << endl;
        cout << "1.- Agregar Numeros" << endl;
        cout << "2.- Mostrar Numeros" << endl;
        cout << "3.- Ingresar numero" << endl;
        cout << "0.- Salir" << endl;
        cout << "\nIngrese una opcion valida: ";
        op = _getch();

        switch (op)
        {
        case '1': // Agregar Numeros
            do
            {
                system("cls");
                cout << "***   AGREGAR NUMEROS   ***\n"
                     << endl;
                cout << "Ingrese el numero: ";
                cin >> num;

                cabeza->agregarNodo(cabeza, num);
                cout << "Desea ingresar otro numero?: s/n: ";
                cin >> op2;
            } while (op2 == 's' || op2 == 'S');
            system("PAUSE");
            break;
        case '2': // Mostrar Numeros
            system("cls");
            cout << "*** MOSTRAR LISTA ***" << endl
                 << endl;
            cabeza->mostrarLista(&cabeza);
            // obj.mostrarLista(cabeza);
            system("PAUSE");
            break;
        case '3': // Ingresar número
            system("cls");
            cout << "***   INGRESAR NUMERO   ***" << endl
                 << endl;
            cout << "Ingrese numero: ";
            cin >> numero;
            contador = 0;
            cout << "Numero de veces que se repite el numero en la lista: " << cabeza->ContarValor(&cabeza, numero, contador) << endl;
            system("PAUSE");
            break;

        case '0': // Salir
            system("cls");
            cout << "***   Salir   ***" << endl;
            system("PAUSE");
            exit(0);
            break;

        } // Fin swicth()

    } while (op != '1' || op != '2' || op != '3' || op != '0');
    return 0;

}// Fin main()