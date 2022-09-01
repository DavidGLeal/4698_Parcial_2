#pragma once
#include <iostream>
using namespace std;
class Nodo
{
public:
    // Atributos
    int clave;
    Nodo *izquierdo;
    Nodo *derecho;
    int altura;
    // Funciones
    int max(int a, int b);
    int calcularAltura(Nodo *N);
    Nodo *crearNuevoNodo(int clave);
    Nodo *rotarALaDerecha(Nodo *y);
    Nodo *rotarALaIzquierda(Nodo *x);
    int obtenerFactorDeBalanceo(Nodo *N);
    Nodo *insertarNodo(Nodo *Nodo, int clave);
    Nodo *hallarNodoMinimo(Nodo *nodo);
    Nodo *borrarNodo(Nodo *raiz, int clave);
    void imprimirArbol(Nodo *raiz, string indentado, bool ultimo);
};