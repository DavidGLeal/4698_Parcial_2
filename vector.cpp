#include "vector.h"

template<typename T>
Vector<T>::~Vector() {
    delete [] arr;
}

template<typename T>
void Vector<T>::push_back(const T &data) {
    if (elems < cap) {
        *(arr + elems) = data;
        elems++;
    } else {
        auto tmp_arr = new T[cap * 2];
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

template<typename T>
T &Vector<T>::operator[](size_t pos) {
    if (pos >= 0 &&  pos <= elems)
        return *(this->arr + pos);
    throw std::out_of_range("Out of bounds element access");
}

template<typename T>
size_t Vector<T>::size() const {
    return elems;
}

template<typename T>
size_t Vector<T>::capacity() const {
    return cap;
}

template<typename T>
void Vector<T>::pop_back() {
    if (empty())
        return;
    elems--;
}

template<typename T>
bool Vector<T>::empty() const {
    return elems == 0;
}

