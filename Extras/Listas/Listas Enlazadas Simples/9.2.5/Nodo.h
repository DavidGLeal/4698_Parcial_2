#pragma once
#include <iostream>

class Nodo
{
public:
    struct nodo
    {
        int dato;
        nodo *siguiente;
    } * primero, *ultimo;
    Nodo();
    void insertarNodo();
    void buscarNodo();
    void modificarNodo();
    void eliminarNodo();
    void desplegarLista();
};