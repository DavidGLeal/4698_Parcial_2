#pragma once

template<typename T>
class CircularNode {
public:
    CircularNode(T data);
    CircularNode(T data, CircularNode<T>* next);
    CircularNode(T data, CircularNode<T>* next, CircularNode<T>* previous);

    void set_next(CircularNode<T>* next);
    CircularNode<T>* get_next();

    void set_previous(CircularNode<T>* next);
    CircularNode<T>* get_previous();

    void set_data(T data);
    T get_data();

private:
    T data;
    CircularNode<T>* next = nullptr;
    CircularNode<T>* previous = nullptr;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
CircularNode<T>::CircularNode(T data) {
    this->data = data;
    this->next = nullptr;
    this->previous = nullptr;
}

template<typename T>
CircularNode<T>::CircularNode(T data, CircularNode<T>* next) {
    this->data = data;
    this->next = next;
    this->previous = nullptr;
}

template<typename T>
CircularNode<T>::CircularNode(T data, CircularNode<T>* next, CircularNode<T>* previous) {
    this->data = data;
    this->next = next;
    this->previous = previous;
}

template<typename T>
void CircularNode<T>::set_data(T data) {
    this->data = data;
}

template<typename T>
T CircularNode<T>::get_data() {
    return data;
}

template<typename T>
void CircularNode<T>::set_next(CircularNode<T>* next) {
    this->next = next;
}

template<typename T>
CircularNode<T>* CircularNode<T>::get_next() {
    return next;
}

template<typename T>
void CircularNode<T>::set_previous(CircularNode<T>* previous) {
    this->previous = previous;
}

template<typename T>
CircularNode<T>* CircularNode<T>::get_previous() {
    return previous;
}
