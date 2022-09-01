#include "Cola.h"
Cola::Cola()
{
    this->actual = NULL;
    this->inicio = NULL;
}
Cola::~Cola()
{
    delete actual;
    delete inicio;
}
Nodo* Cola::getInicio(void)
{
    return this->inicio;
}
void Cola::setInicio(Nodo* newInicio)
{
    this->inicio = newInicio;
}
Nodo* Cola::getActual(void)
{
    return this->actual;
}
void Cola::setActual(Nodo* newActual)
{
    this->actual = newActual;
}
bool Cola::listaVacia(void)
{
    return (this->inicio == NULL);
}
void Cola::enqueue(int v) //añadir en cola
{
    Nodo* nuevo = new Nodo();
    nuevo->setDato(v);
    if (listaVacia()) {
        setInicio(nuevo);
    }
    else {
        Nodo* aux = getInicio();
        while (aux->getSiguiente() != NULL)
            aux = aux->getSiguiente();
        aux->setSiguiente(nuevo);
    }
}
void Cola::dequeue() //eliminar en cola
{
    if (listaVacia()) {
        cout << "Cola Vacia\n";
    }
    else {
        Nodo* aux = inicio;
        inicio = inicio->getSiguiente();
        aux->setSiguiente(nullptr);
        delete aux;
    }
}
void Cola::mostar(void)
{
    for (Nodo* aux = inicio; aux != NULL; aux = aux->getSiguiente()) {
        cout << aux->getDato() << "\n";
    }
}
