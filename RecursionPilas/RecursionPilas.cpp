//Universidad de las Fuerzas Armadas ESPE
// Enunciado: Método adicional encontrar el numero menor de una cola.
//Autores:Camila Morales, Anthony Sinchiguano.
//Fecha de creación: 16/07/2022
//Fecha de modificación: 16/07/2022
//Github: https://github.com/DavidGLeal/4698_Parcial_2/tree/Codigos_proyecto
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void ordenadoInsertar(stack<int> &stack, int key){
    // caso base: si la stack está vacía o
    // la clave es mayor que todos los elementos de la stack
    if (stack.empty() || key > stack.top())
    {
        stack.push(key);
        return;
    }
 
    //Llegamos aquí cuando la clave es más pequeña que el elemento superior 
 
    // elimina el elemento superior
    int top = stack.top();
    stack.pop();
 
    // recurre para los elementos restantes en la stack
    ordenadoInsertar(stack, key);
 
    // inserta el elemento reventado de nuevo en la stack
    stack.push(top);
}
 
// Método recursivo para ordenar una stack
void clasificarPila(stack<int> &stack){
    // caso base: la stack está vacía
    if (stack.empty()) {
        return;
    }
 
    // elimina el elemento superior
    int top = stack.top();
    stack.pop();
 
    // recurre para los elementos restantes en la stack
    clasificarPila(stack);
 
    // inserta el elemento reventado de nuevo en la stack ordenada
    ordenadoInsertar(stack, top);
}
 
void imprimirPila(stack<int> stack){
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}