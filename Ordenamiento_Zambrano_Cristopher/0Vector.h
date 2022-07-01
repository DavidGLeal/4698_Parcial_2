#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Vector {

    //int es un tipo definido entero long long sin signo
private:
    int* arrayInterno = new int[10];
    int capacidad{ 10 };
    int elementos{ 0 };

public:
    Vector() {};
    ~Vector();

    void push_back(const int& data);
    void pop_back();
    void vaciar();
    bool empty();
    int size();
    int capacity();
    int& operator[](int pos);
    int* get(int);
    int getElementos();
    int* getArrayInterno();

};
