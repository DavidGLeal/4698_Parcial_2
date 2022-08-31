#include "Arbol.h"
int raiz1 = 0;

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
    }
    else
    {
        int raiz = arbol->getValor();
        if (dato < raiz)
        {
            insertarNodo(arbol->getIzquierda(), dato);
        }
        else
        {
            insertarNodo(arbol->getDerecha(), dato);
        }
    }
}

void Arbol::mostrar(Nodo *arbol, int contador)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        mostrar(arbol->getDerecha(), contador + 1);
        for (int i = 0; i < contador; i++)
        {
            cout << "  ";
        }
        cout << arbol->getValor() << endl;
        mostrar(arbol->getIzquierda(), contador + 1);
    }
}

int Arbol::peso(Nodo *arbol)
{
    if (arbol == NULL)
        return 0;
    else
        return 1 + peso(arbol->getIzquierda()) + peso(arbol->getDerecha());
}

int Arbol::altura(Nodo *aux)
{
	 if (aux == NULL)
	    return 0;
	 if (aux->getIzquierda() == NULL && aux ->getDerecha() == NULL) 
	    return 1;
	 return max (altura (aux->getIzquierda()), altura (aux->getDerecha())) + 1; 
}

void Arbol::nodoHijos(Nodo *aux){
    if (aux != NULL)
    {
        nodoHijos(aux->getIzquierda());
        if (aux->getValor() != 6)
        {
            cout<<aux->getValor()<<" ";
        }
        nodoHijos(aux->getDerecha());
    }
}

bool Arbol::simetria(Nodo* X, Nodo* Y){
    if (X == NULL && Y == NULL) {
        return true;
    }
    return (X != NULL && Y != NULL) &&
        simetria(X->getIzquierda(), Y->getDerecha()) &&
        simetria(X->getDerecha(), Y->getIzquierda());
}

bool Arbol::simetrias(Nodo* aux){
    if (aux == NULL) {
        return true;
    }
 
    return simetria(aux->getIzquierda(), aux->getDerecha());
}
