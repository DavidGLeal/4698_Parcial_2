//Universidad de las Fuerzas Armadas ESPE
// Enunciado: Método adicional encontrar el numero menor de una cola.
//Autores:Camila Morales, Anthony Sinchiguano.
//Fecha de creación: 16/07/2022
//Fecha de modificación: 16/07/2022
//Github: https://github.com/DavidGLeal/4698_Parcial_2/tree/Codigos_proyecto
#include <iostream>
#include <conio.h>
#include "RecursionPilas.cpp"
using namespace std;

int main(){
    vector<int> list = { 5, -2, 9, -7, 3 };
 
    stack<int> stack;
    for (int i: list) {
        stack.push(i);
    }
 
    cout << "Pila antes de clasificar: ";
    imprimirPila(stack);
 
    clasificarPila(stack);
 
    cout << "Pila despues de clasificar: ";
    imprimirPila(stack);
 
    return 0;
}