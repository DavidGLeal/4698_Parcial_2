//Universidad de las Fuerzas Armadas ESPE
// Enunciado: Ordenamiento quicksort 
//Autores:Camila Morales, Anthony Sinchiguano.
//Fecha de creación: 16/07/2022
//Fecha de modificación: 16/07/2022
//Github: https://github.com/DavidGLeal/4698_Parcial_2/tree/Codigos_proyecto

#pragma once
#include <iostream>
#include <string>

using std::cout; using std::cin;
using std::endl; using std::string;

class Vector {

public:
    Vector() {
        arr = new int[10];
        cap = 10;
        elems = 0;
    };

    void push_back(const int& data);
    void pop_back();

    bool empty() const;
    size_t size() const;
    size_t capacity() const;
    int& operator[](size_t pos);

    ~Vector();
    int* get(int);

private:
    int* arr = NULL;
    size_t cap;
    size_t elems;
    string name;
    double num;
};

