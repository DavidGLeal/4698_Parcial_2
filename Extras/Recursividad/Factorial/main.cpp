/*Universidad de las Fuerzas Armadas ESPE
  Enunciado del problema: Recursividad
  Autor: Johanna Pila
  Fecha de creacion: 13/05/2022
  Fecha de modificacion: 13/05/2022
  github: 
*/

/* Recursividad: Funcion que se llama a ella misma 
con Caso base y uno General

Factorial es un ejemplo de recursividad 
*/

#include <iostream>
#include <conio.h>
#include "factorial.h"

using namespace std;

int factoriales(int);


int main(){

    int a;

    cout<<"Ingrese numero: ";
    cin>>a;
    cout<<"Factorial del numero "<< a<< " es "<<factoriales(a)<<endl;
    
    getch();
    return 0;
}