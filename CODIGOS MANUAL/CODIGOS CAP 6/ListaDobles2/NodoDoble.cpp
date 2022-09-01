#include "NodoDoble.h" //Llamo al archivo de cabecera NodoDoble.h para implementar los métodos de la clase NodoDoble
#include <iostream>
 
using namespace std;
 
NodoDoble::NodoDoble() //Constructor por defecto de la clase NodoDoble.
{
    dato = 0;
    siguiente = NULL;
    anterior = NULL;
}
 
//Métodos setter y getter
//Setters
void NodoDoble::setDato(int dato)
{
    this->dato = dato;
}
 
void NodoDoble::setSiguiente(NodoDoble *siguiente)
{
    this->siguiente = siguiente;
}
 
void NodoDoble::setAnterior(NodoDoble *anterior)
{
    this->anterior = anterior;
}
 
//Getters
int NodoDoble::getDato()
{
    return dato;
}
 
NodoDoble *NodoDoble::getSiguiente()
{
    return siguiente;
}
 
NodoDoble *NodoDoble::getAnterior()
{
return anterior;
}
 
//Métodos definidos por el usuario
void NodoDoble::ingresarNodoDobleFinal(NodoDoble **nodoDoble, int dato, int &contarDatos) //Método en el cual se ingresan los datos a la lista doble
{
    NodoDoble *aux, *nuevo; //Declaro una variable puntero *aux de tipo NodoDoble que me va a servir para utilizarla como auxiiar que apunte a la lista doble para no trabajar directamente con la lista doblemente enlazada.
    aux = *nodoDoble; //Apunto aux a la lista doblemente enlazada
 
    if (aux->getDato() == 0) //Si la lista doble esta vacia, si aux->getDato() es 0
    {
        aux->setDato(dato); //Envio como argumento el parámetro dato al método setDato() de la clase NodoDoble
        contarDatos++; //Aumento el contador de cuantos nodos  van ingresando a la lista doble.
    }
    else //Si la lista doble no esta vacia
    {
        while (aux->getSiguiente() != NULL)
        {
            aux = aux->getSiguiente();
        }
 
        nuevo = new NodoDoble(); //Reservo un espacio en memoria para el puntero nuevo que será un nuevo puntero.
        nuevo->setDato(dato); //Envio como argumento el parámetro dato al método setDato() de la clase NodODoble
        aux->setSiguiente(nuevo);
        nuevo->setAnterior(aux); //Apunto el nuevo nodo a NULL
        contarDatos++; //Aumento el contador de cuantos nodos  van ingresando a la lista doble.
    }
}
void NodoDoble::mostrarListaDoble(NodoDoble *nodoDoble, int contarDatos) //Método en el cual se muestra la lista doble
{
    NodoDoble *aux; //Declaro una variable puntero *aux de tipo NodoDoble que me va a servir para utilizarla como auxiiar que apunte a la lista doble para no trabajar directamente con la lista doble.
    aux = nodoDoble; //Apunto aux a pila,
int posicion = 1;
    if (aux->getDato() == 0) //Si la lista doble esta vacia, si aux->getDato() es 0
    {
        cout << "\nLista Doblemente Enlazada vacia." << endl;
    }
    else
    {
        while (aux != NULL) //Recorremos la lista Doble, mientras no sea el último nodo de la lista doble.
        {
            cout << "-> " << posicion << "\t" << aux->getDato() << endl;
            posicion++;
            aux = aux->getSiguiente(); //Hago que se avance al siguiente nodo de la lista doble.
        }//Fin while()
 
        cout << "\nNumero de nodos en la lista doble: " << contarDatos << endl;
    }
}
