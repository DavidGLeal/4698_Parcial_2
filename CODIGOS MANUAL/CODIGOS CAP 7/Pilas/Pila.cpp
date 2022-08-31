#include "Pila.h"
Pila::Pila()
{
    this->actual = NULL;
    this->inicio = NULL;
}
Pila::~Pila()
{
    delete actual;
    delete inicio;
}
Nodo* Pila::getInicio(void)
{
    return this->inicio;
}
void Pila::setInicio(Nodo* newInicio)
{
    this->inicio = newInicio;
}

Nodo* Pila::getActual(void)
{
    return this->actual;
}
void Pila::setActual(Nodo* newActual)
{
    this->actual = newActual;
}
bool Pila::listaVacia(void)
{
    return (this->inicio == NULL);
}
void Pila::push(float v)
{
    Nodo* nuevo = new Nodo();
    nuevo->setDato(v);

    if (listaVacia()) {
        setInicio(nuevo);
    }
    else {
        nuevo->setSiguiente(inicio);
        setInicio(nuevo);
    }
}
void Pila::mostrar(void)
{
    for (Nodo* aux = inicio; aux != NULL; aux = aux->getSiguiente()) {
        cout << aux->getDato() << "\n";
    }
}
void Pila::pop() {
    Nodo* aux = inicio;
    inicio = inicio->getSiguiente();
    aux->setSiguiente(nullptr);
    delete aux;
}
