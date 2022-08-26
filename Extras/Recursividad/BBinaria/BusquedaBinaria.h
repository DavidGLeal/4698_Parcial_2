#pragma once
#include <iostream>
#define MAX 50

class BusquedaBinaria{
public:
    //lee el array de numeros
    void leerArray(int n,int x[]);
    //Lista el array ingresado
    void Listado(int n,int x[]);
    //Metodo de ordenacion
    void Burbuja(int n,int x[]);
    //Metodo de busqueda de binaria
    int bBinaria(int n,int x[],int t);
};