#include "Arbol.h"

void Arbol::setArbol(Nodo *_arbol)
{
    arbol = _arbol;
}
Nodo *Arbol::getArbol()
{
    return arbol;
}
Nodo *Arbol::crearNodo(int dato)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->setValor(dato);
    nuevoNodo->setDerecha(NULL);
    nuevoNodo->setIzquierda(NULL);
    return nuevoNodo;
}
void Arbol::insertarNodo(Nodo *&arbol, int dato)
{
    if (arbol == NULL)
    {
        Nodo *nuevoNodo = crearNodo(dato);
        arbol = nuevoNodo;
        cout<<"Dato ingresado correctamente...\n";
    }
    else
    {
        int raiz = arbol->getValor();
        if (dato < raiz)
        {
            insertarNodo(arbol->getIzquierda(), dato);
            cout<<"Dato ingresado correctamente...\n";
        }
        else
        {
            insertarNodo(arbol->getDerecha(), dato);
            cout<<"Dato ingresado correctamente...\n";
        }
    }
}
