#pragma once
#include <iostream>
#include <string>

using std::cout; 
using std::cin;
using std::endl; 
using std::string;

class Vector {

    //size_t es un tipo definido entero long long sin signo
    private:
        int *arrayInterno = new int[10];
        size_t capacidad{10};
        size_t elementos{0};
        string name{0};
        double num{0};

    public:
        Vector(){};
        ~Vector();

        void push_back(const int &data);
        void pop_back();
        bool empty();
        size_t size();
        size_t capacity();
        // int& operator[](size_t pos);
        int *get(int);

        void imprimir();
};

