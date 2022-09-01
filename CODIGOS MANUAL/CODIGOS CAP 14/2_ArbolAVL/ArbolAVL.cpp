#pragma once
#include "ArbolAVL.h"
// Calcular Altura
int Nodo::calcularAltura(Nodo *N)
{
    if (N == NULL)
        return 0;
    return N->altura;
}

int Nodo::max(int a, int b)
{
    return (a > b) ? a : b;
}

// Creación de un Nuevo Nodo
Nodo *Nodo::crearNuevoNodo(int clave)
{
    Nodo *nodo = new Nodo;
    nodo->clave = clave;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    nodo->altura = 1;
    return (nodo);
}

// Rotar a la derecha
Nodo *Nodo::rotarALaDerecha(Nodo *y)
{
    Nodo *x = y->izquierdo;
    Nodo *T2 = x->derecho;
    x->derecho = y;
    y->izquierdo = T2;
    y->altura = max(calcularAltura(y->izquierdo),
                    calcularAltura(y->derecho)) +
                1;
    x->altura = max(calcularAltura(x->izquierdo),
                    calcularAltura(x->derecho)) +
                1;
    return x;
}

// Rotar a la Izquierda
Nodo *Nodo::rotarALaIzquierda(Nodo *x)
{
    Nodo *y = x->derecho;
    Nodo *T2 = y->izquierdo;
    y->izquierdo = x;
    x->derecho = T2;
    x->altura = max(calcularAltura(x->izquierdo),
                    calcularAltura(x->derecho)) +
                1;
    y->altura = max(calcularAltura(y->izquierdo),
                    calcularAltura(y->derecho)) +
                1;
    return y;
}

// Obtener el factor de balanceo
int Nodo::obtenerFactorDeBalanceo(Nodo *N)
{
    if (N == NULL)
        return 0;
    return calcularAltura(N->izquierdo) -
           calcularAltura(N->derecho);
}

// Insertar Nodo
Nodo *Nodo::insertarNodo(Nodo *Nodo, int clave)
{
    // Encuentra la posición correcta e inserta el Nodo
    if (Nodo == NULL)
        return (crearNuevoNodo(clave));
    if (clave < Nodo->clave)
        Nodo->izquierdo = insertarNodo(Nodo->izquierdo, clave);
    else if (clave > Nodo->clave)
        Nodo->derecho = insertarNodo(Nodo->derecho, clave);
    else
        return Nodo;

    // Actualiza el factor de balanceo, y balancea el árbol
    Nodo->altura = 1 + max(calcularAltura(Nodo->izquierdo),
                           calcularAltura(Nodo->derecho));
    int factorBalanceo = obtenerFactorDeBalanceo(Nodo);
    if (factorBalanceo > 1)
    {
        if (clave < Nodo->izquierdo->clave)
        {
            return rotarALaDerecha(Nodo);
        }
        else if (clave > Nodo->izquierdo->clave)
        {
            Nodo->izquierdo = rotarALaIzquierda(Nodo->izquierdo);
            return rotarALaDerecha(Nodo);
        }
    }
    if (factorBalanceo < -1)
    {
        if (clave > Nodo->derecho->clave)
        {
            return rotarALaIzquierda(Nodo);
        }
        else if (clave < Nodo->derecho->clave)
        {
            Nodo->derecho = rotarALaDerecha(Nodo->derecho);
            return rotarALaIzquierda(Nodo);
        }
    }
    return Nodo;
}

// Hallar el nodo con el mínimo valor
Nodo *Nodo::hallarNodoMinimo(Nodo *nodo)
{
    Nodo *actual = nodo;
    while (actual->izquierdo != NULL)
        actual = actual->izquierdo;
    return actual;
}

// Borrar Nodo
Nodo *Nodo::borrarNodo(Nodo *raiz, int clave)
{
    // Encontrar y borrar el nodo
    if (raiz == NULL)
        return raiz;
    if (clave < raiz->clave)
        raiz->izquierdo = borrarNodo(raiz->izquierdo, clave);
    else if (clave > raiz->clave)
        raiz->derecho = borrarNodo(raiz->derecho, clave);
    else
    {
        if ((raiz->izquierdo == NULL) ||
            (raiz->derecho == NULL))
        {
            Nodo *temp = raiz->izquierdo ? raiz->izquierdo : raiz->derecho;
            if (temp == NULL)
            {
                temp = raiz;
                raiz = NULL;
            }
            else
                *raiz = *temp;
            free(temp);
        }
        else
        {
            Nodo *temp = hallarNodoMinimo(raiz->derecho);
            raiz->clave = temp->clave;
            raiz->derecho = borrarNodo(raiz->derecho,
                                       temp->clave);
        }
    }

    if (raiz == NULL)
        return raiz;

    // Actualizar y balancear
    raiz->altura = 1 + max(calcularAltura(raiz->izquierdo),
                           calcularAltura(raiz->derecho));
    int factorBalanceo = obtenerFactorDeBalanceo(raiz);
    if (factorBalanceo > 1)
    {
        if (obtenerFactorDeBalanceo(raiz->izquierdo) >= 0)
        {
            return rotarALaDerecha(raiz);
        }
        else
        {
            raiz->izquierdo = rotarALaIzquierda(raiz->izquierdo);
            return rotarALaDerecha(raiz);
        }
    }
    if (factorBalanceo < -1)
    {
        if (obtenerFactorDeBalanceo(raiz->derecho) <= 0)
        {
            return rotarALaIzquierda(raiz);
        }
        else
        {
            raiz->derecho = rotarALaDerecha(raiz->derecho);
            return rotarALaIzquierda(raiz);
        }
    }
    return raiz;
}

// ImprimeElArbol
void Nodo::imprimirArbol(Nodo *raiz, string indentado, bool ultimo)
{
    if (raiz != NULL)
    {
        cout << indentado;
        if (ultimo)
        {
            cout << "Der----";
            indentado += "   ";
        }
        else
        {
            cout << "Izq----";
            indentado += "|  ";
        }
        cout << raiz->clave << endl;
        imprimirArbol(raiz->izquierdo, indentado, false);
        imprimirArbol(raiz->derecho, indentado, true);
    }
}