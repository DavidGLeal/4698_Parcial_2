#include "Arbol.h"

/**
 * Establece el valor de la variable privada arbol al valor del parámetro _arbol.
 * 
 * @param _arbol El nodo raíz del árbol.
 */
void Arbol::setArbol(Nodo *_arbol)
{
    arbol = _arbol;
}

/**
 * Devuelve la raíz del árbol.
 * 
 * @return El nodo raíz del árbol.
 */
Nodo *Arbol::getArbol()
{
    return arbol;
}

/**
 * Crea un nuevo nodo con el valor del parámetro.
 * 
 * @param dato El valor del nodo
 * 
 * @return Un puntero a un objeto Nodo.
 */
Nodo *Arbol::crearNodo(int dato)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->setValor(dato);
    nuevoNodo->setDerecha(NULL);
    nuevoNodo->setIzquierda(NULL);
    return nuevoNodo;
}

/**
 * Si el árbol está vacío, cree un nuevo nodo y asígnelo al árbol. De lo contrario, si los datos son
 * menores que la raíz, insértelos en el subárbol izquierdo. De lo contrario, insértelo en el subárbol
 * derecho
 * 
 * @param arbol El árbol
 * @param dato el valor a insertar
 */
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

//RECORRIDO EN PREORDEN
/**
 * *|CURSOR_MARCADOR|*
 * 
 * @param arbol es la raiz del arbol
 * 
 * @return el valor del nodo.
 */
void Arbol::preOrden(Nodo *arbol)
{
    if (arbol == NULL)
    {
        return;
        cout<<"No se encuentran datos en el arbol, \narbol vacio...\n";
    }
    else
    {
        cout<<arbol->getValor()<<"-";
        preOrden(arbol->getIzquierda());
        preOrden(arbol->getDerecha());
    }
}

