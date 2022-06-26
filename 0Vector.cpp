#pragma once
#include "vector.h"

Vector::~Vector() {
    delete [] arr;
}

void Vector::push_back(const int &data) {
    if (elems < cap) {
        *(arr + elems) = data;
        elems++;
    } else {
        auto tmp_arr = new int[cap * 2];
        cap *= 2;
        for (int i = 0; i < elems; i++) {
            tmp_arr[i] = arr[i];
        }
        delete [] arr;
        arr = tmp_arr;

        *(arr + elems) = data;
        elems++;
    }
}

int &Vector::operator[](size_t pos) {
    if (pos >= 0 &&  pos <= elems)
        return *(this->arr + pos);
    throw std::out_of_range("Out of bounds element access");
}

size_t Vector::size() const {
    return elems;
}

size_t Vector::capacity() const {
    return cap;
}

void Vector::pop_back() {
    if (empty())
        return;
    elems--;
}

bool Vector::empty() const {
    return elems == 0;
}

int *Vector::get(int pos) {
    if (pos >= 0 && pos < elems)
        return arr + pos;
}


