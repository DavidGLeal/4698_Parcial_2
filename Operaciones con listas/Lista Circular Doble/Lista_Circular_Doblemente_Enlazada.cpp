#include "Lista_Circular_Doblemente_Enlazada.h"

Lista_Circular_Doblemente_Enlazada::Lista_Circular_Doblemente_Enlazada()
{
    this->cabeza = nullptr;
    this->actual = nullptr;
}

Lista_Circular_Doblemente_Enlazada::~Lista_Circular_Doblemente_Enlazada()
{
    while (cabeza)
    {
        cabeza = cabeza->getSiguiente();
    }
}

void Lista_Circular_Doblemente_Enlazada::Insertar(int valor)
{
    Nodo *nuevo = new Nodo(valor, nullptr);
    Nodo *tmp = cabeza;
    if (ListaVacia())
    {
        nuevo->setSiguiente(nuevo);
        nuevo->setPrevio(nuevo);
        this->cabeza = nuevo;
    }
    else if (tmp->getPrevio() == cabeza && tmp->getSiguiente() == cabeza)
    {
        nuevo->setSiguiente(tmp);
        nuevo->setPrevio(tmp->getPrevio());
        tmp->setPrevio(nuevo);
        tmp->setSiguiente(nuevo);
    }
    else
    {
        nuevo->setSiguiente(tmp);
        nuevo->setPrevio(tmp->getPrevio());
        tmp->getPrevio()->setSiguiente(nuevo);
        tmp->setPrevio(nuevo);
    }
}

void Lista_Circular_Doblemente_Enlazada::Eliminar(int eliminar)
{
    Nodo *nuevo = new Nodo(eliminar, nullptr);
    Nodo *tmp = new Nodo();
    tmp = cabeza;
    if (ListaVacia())
    {
        std::cout << "La lista se encuentra vacía" << std::endl;
    }
    else
    {
        while (tmp->getSiguiente() != cabeza && tmp->getValor() == eliminar)
        {
            tmp = tmp->getSiguiente();
        }
    }
    tmp->getPrevio()->setSiguiente(tmp->getSiguiente());
    tmp->getSiguiente()->setPrevio(tmp->getPrevio());
    tmp->setSiguiente(nullptr);
    tmp->setPrevio(nullptr);
    delete tmp;
}

void Lista_Circular_Doblemente_Enlazada::Buscar(int buscar)
{
    if (ListaVacia())
    {
        std::cout << "La lista está vacía, no se puede buscar" << std::endl;
    }
    else
    {
        Nodo *tmp = cabeza;
        do
        {
            if (tmp->getValor() == buscar)
            {
                std::cout << "Elemento encontrado con éxito" << std::endl;
            }

        } while (tmp != cabeza);
    }
}

void Lista_Circular_Doblemente_Enlazada::Mostrar()
{
    Nodo *nuevo = cabeza;
    while (nuevo->getSiguiente() != cabeza)
    {
        std::cout << nuevo->getValor() << std::endl;
        nuevo = nuevo->getSiguiente();
    }
    std::cout << nuevo->getValor() << std::endl;
}

void Lista_Circular_Doblemente_Enlazada::InsertarPorCola(Nodo **cabeza, int valor)
{
    if (*cabeza == NULL)
    {
        Nodo *aux = new Nodo();
        aux->setValor(valor);
        aux->setSiguiente(aux->getPrevio());
        *cabeza = aux;
        return;
    }

    Nodo *anterior = (*cabeza)->getPrevio();
    Nodo *aux1 = new Nodo();
    aux1->setValor(valor);
    aux1->setSiguiente(*cabeza);
    aux1->setPrevio(anterior);
    anterior->setSiguiente(aux1);
}

void Lista_Circular_Doblemente_Enlazada::InsertarPorCabeza(Nodo **cabeza, int valor)
{
    Nodo *ultimo = (*cabeza)->getPrevio();

    Nodo *nuevo = new Nodo;
    nuevo->setValor(valor);
    nuevo->setSiguiente(*cabeza);
    nuevo->setPrevio(ultimo);

    ultimo->setSiguiente((*cabeza)->getPrevio());
    *cabeza = nuevo;
}

void Lista_Circular_Doblemente_Enlazada::InsertarDespues(Nodo **cabeza, int val1, int val2)
{
    Nodo *nuevo = new Nodo;
    nuevo->setValor(val1);
    Nodo *temp = *cabeza;
    while (temp->getValor() != val2)
        temp = temp->getSiguiente();
    Nodo *siguiente = temp->getSiguiente();

    temp->setSiguiente(nuevo);
    nuevo->setPrevio(temp);
    nuevo->setSiguiente(siguiente);
    siguiente->setPrevio(nuevo);
}