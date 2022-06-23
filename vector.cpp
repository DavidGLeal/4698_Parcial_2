
#include "vector.h"

Vector<int>::~Vector() {
    delete [] arr;
}

void Vector<int>::push_back(const int &data) {
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

int &Vector<int>::operator[](size_t pos) {
    if (pos >= 0 &&  pos <= elems)
        return *(this->arr + pos);
    throw std::out_of_range("Out of bounds element access");
}

size_t Vector<int>::size() const {
    return elems;
}

size_t Vector<int>::capacity() const {
    return cap;
}

void Vector<int>::pop_back() {
    if (empty())
        return;
    elems--;
}

bool Vector<int>::empty() const {
    return elems == 0;
}

int *Vector<int>::get(int pos) {
    if (pos >= 0 && pos < elems)
        return arr + pos;
}


