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

