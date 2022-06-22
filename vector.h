#pragma once
#include <iostream>
#include <string>

using std::cout; using std::cin;
using std::endl; using std::string;

template<typename T>
class Vector {
public:
    Vector() {
        arr = new T[default_capacity];
        cap = default_capacity;
        elems = 0;
    };

    void push_back(const T &data);
    void pop_back();

    [[nodiscard]] bool empty() const;
    [[nodiscard]] size_t size() const;
    [[nodiscard]] size_t capacity() const;
    T &operator[](size_t pos);

    ~Vector();
private:
    T *arr = nullptr;
    size_t cap;
    size_t elems;
    string name;
    double num;
    const int default_capacity = 20;
};

