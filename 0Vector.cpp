#pragma once
#include "0Vector.h"

/**
 * El destructor de la clase Vector.
 */
Vector::~Vector(){
    delete [] arrayInterno;
}

/**
 * Si la matriz está llena, duplique el tamaño de la matriz y copie la matriz anterior en la nueva
 * 
 * @param data Los datos que se agregarán al vector.
 */
void Vector::push_back(const int &data) {

    if (elementos < capacidad) {
        arrayInterno[elementos] = data;
        elementos++;
    } else {
        auto tmp_arr = new int[capacidad * 2];
        capacidad *= 2;
        for (int i = 0; i < elementos; i++) {
            tmp_arr[i] = arrayInterno[i];
        }
        delete [] arrayInterno;
        arrayInterno = tmp_arr;

        arrayInterno[elementos] = data;
        elementos++;
    }
}

/**
 * Si la posición es válida, devuelva el elemento en esa posición. De lo contrario, lanzar una
 * excepción
 * 
 * @return Una referencia al elemento en la posición dada.
 */
int& Vector::operator[](int pos) {
    if (pos >= 0 &&  pos < elementos)
        return arrayInterno[pos];
    throw std::out_of_range("Elemento fuera de rango");
}

int Vector::size(){
    return elementos;
}

int Vector::capacity(){
    return capacidad;
}

void Vector::pop_back() {
    if (empty())
        return;
    elementos--;
}

bool Vector::empty(){
    return elementos == 0;
}

int *Vector::get(int pos) {
    if (pos >= 0 && pos < elementos)
        return arrayInterno + pos;
    return 0;
}

int Vector::getElementos(){
    return this->elementos;
}

int *Vector::getArrayInterno(){
    return this->arrayInterno;
}
