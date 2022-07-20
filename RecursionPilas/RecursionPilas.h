//Universidad de las Fuerzas Armadas ESPE
// Enunciado: Método adicional encontrar el numero menor de una cola.
//Autores:Camila Morales, Anthony Sinchiguano.
//Fecha de creación: 16/07/2022
//Fecha de modificación: 16/07/2022
//Github: https://github.com/DavidGLeal/4698_Parcial_2/tree/Codigos_proyecto
#pragma once
#include "RecursionPilas.cpp"
#include <iostream>

using namespace std;

class RecursionPials{
    private:
        int pila;
        int key;
    public:
        void ordenadoInsertar(int, int);
        void clasificarPila(int);
        void imprimirPila(int);
};