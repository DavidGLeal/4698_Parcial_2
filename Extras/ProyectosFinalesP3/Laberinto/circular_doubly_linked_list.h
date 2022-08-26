#pragma once
#include "CircularNode.h"
#include <functional>
#include <optional>
#include <stdexcept>
#include <exception>

template <typename T>
class CircularDoublyLinkedList {
public:
    CircularDoublyLinkedList() = default;

    CircularNode<T>* at(int index);
    void push_back(const T &value);
    void push_front(const T &value);
    void push_at(int index, const T &value);
    void remove_at(int index);
    void remove(std::function<bool(T)> callback);
    void remove_all(std::function<bool(T)> callback);
    bool contains(const T& value);
    

    void for_each(std::function<void(CircularNode<T> *, int)> callback);
    void for_each(std::function<void(CircularNode<T>*)> callback);
    void for_each(std::function<void(T, int)> callback);
    void for_each(std::function<void(T)> callback);
    
    void until(std::function<bool(CircularNode<T>*)> callback);
    void until(std::function<bool(T)> callback);

    std::optional<T> find(std::function<bool(CircularNode<T> *, int)> callback);
    std::optional<T> find(std::function<bool(CircularNode<T>*)> callback);
    std::optional<T> find(std::function<bool(T, int)> callback);
    std::optional<T> find(std::function<bool(T)> callback);

    void clear();
    int size();
    bool empty();

private:
    CircularNode<T> *last();
    CircularNode<T> *head = nullptr;
    int _size = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
void CircularDoublyLinkedList<T>::push_back(const T &value) {
    if (head == nullptr) {
        head = new CircularNode<T>(value);
        head->set_next(head);
        head->set_previous(head);
        _size++;
        return;
    }

    CircularNode<T> *last_node = last();
    CircularNode<T> *node = new CircularNode<T>(value);

    last_node->set_next(node);
    node->set_previous(last_node);
    node->set_next(head);
    head->set_previous(node);
    _size++;
}

template <typename T>
void CircularDoublyLinkedList<T>::push_front(const T &value) {
    if (head == nullptr) {
        return push_back(value);
    }

    CircularNode<T> *node = new CircularNode<T>(value);
    CircularNode<T> *temp = head;

    head = node;
    head->set_next(temp);
    head->set_previous(temp->get_previous());
    temp->get_previous()->set_next(head);
    temp->set_previous(head);
    _size++;
}

template <typename T>
void CircularDoublyLinkedList<T>::push_at(int index, const T &value) {
    if (index < 0 || index > _size) {
        throw std::invalid_argument("index out of bounds");
    }

    if (index == 0 || _size == 0) {
        return push_front(value);
    } else if (index == _size) {
        return push_back(value);
    }

    CircularNode<T> *target = at(index);
    CircularNode<T> *previous = target->get_previous();
    CircularNode<T> *next = target->get_next();
    CircularNode<T> *nodo = new CircularNode<T>(value);

    previous->set_next(nodo);
    nodo->set_next(target);
    nodo->set_previous(previous);
    target->set_previous(nodo);
    _size++;
}

template <typename T>
void CircularDoublyLinkedList<T>::remove_at(int index) {
    if (index < 0 || index >= _size) {
        throw std::invalid_argument("index out of bounds");
    }
    
    if (index == 0) {
        CircularNode<T> *temp = head;
        head = head->get_next();
        head->set_previous(temp->get_previous());
        temp->get_previous()->set_next(head);
        delete temp;
    } else if (index == _size - 1) {
        CircularNode<T> *node = last();
        CircularNode<T> *previous = node->get_previous();
        previous->set_next(head);
        head->set_previous(previous);
        delete node;
    } else {
        CircularNode<T> *target = at(index);
        CircularNode<T> *previous = target->get_previous();
        CircularNode<T> *next = target->get_next();

        previous->set_next(next);
        next->set_previous(previous);
        delete target;
    }

    _size--;
}

template<typename T>
inline void CircularDoublyLinkedList<T>::remove(std::function<bool(T)> callback)
{
    CircularNode<T>* current = head;
    int index = 0;

    if (current == nullptr) {
        return;
    }

    while (true) {
        if (index > 0 && current == head) {
            break;
        }

        if (callback(current->get_data())) {
            remove_at(index);
            break;
        }

        current = current->get_next();
        index++;
    }
}

template<typename T>
inline void CircularDoublyLinkedList<T>::remove_all(std::function<bool(T)> callback)
{
    while (find(callback).has_value()) {
        remove(callback);
    }
}

template<typename T>
inline bool CircularDoublyLinkedList<T>::contains(const T& value)
{
    return find([value](int n) { return n == value; }).has_value();
}

template<typename T>
void CircularDoublyLinkedList<T>::for_each(std::function<void(CircularNode<T>*, int)> callback) {
    CircularNode<T> *current = head;
    int index = 0;

    if (current == nullptr) {
        return;
    }

    do {
        callback(current, index);
        current = current->get_next();
        index++;
    } while (current != head);
}

template<typename T>
void CircularDoublyLinkedList<T>::for_each(std::function<void(CircularNode<T>*)> callback) {
    for_each([&](CircularNode<T> *node, int index) {
        callback(node->get_data());
    });
}

template<typename T>
void CircularDoublyLinkedList<T>::for_each(std::function<void(T)> callback) {
    for_each([&](CircularNode<T> *node, int index) {
        callback(node->get_data());
    });
}

template<typename T>
void CircularDoublyLinkedList<T>::for_each(std::function<void(T, int)> callback) {
    for_each([&](CircularNode<T> *node, int index) {
        callback(node->get_data(), index);
    });
}

template<typename T>
void CircularDoublyLinkedList<T>::until(std::function<bool(CircularNode<T>*)> callback) {
    CircularNode<T> *current = head;
    int index = 0;

    if (current == nullptr) {
        return;
    }

    while (true) {
        if (index > 0 && current == head) {
            break;
        }

        if (!callback(current)) break;
        current = current->get_next();
        index++;
    }
}

template<typename T>
void CircularDoublyLinkedList<T>::until(std::function<bool(T)> callback) {
    until([&](CircularNode<T> *node) {
        return callback(node->get_data());
    });
}

template<typename T>
std::optional<T> CircularDoublyLinkedList<T>::find(std::function<bool(CircularNode<T> *, int)> callback) {
    CircularNode<T> *current = head;
    int index = 0;

    if (current == nullptr) {
        return std::nullopt;
    }

    while (true) {
        if (index > 0 && current == head) {
            break;
        }

        if (callback(current, index++)) {
            return current->get_data();
        }

        current = current->get_next();
    }

    return std::nullopt;
}

template<typename T>
std::optional<T> CircularDoublyLinkedList<T>::find(std::function<bool(CircularNode<T> *)> callback) {
    return find([&](CircularNode<T> *node, int index) -> bool {
        return callback(node->get_data());
    });
}

template<typename T>
std::optional<T> CircularDoublyLinkedList<T>::find(std::function<bool(T)> callback) {
    return find([&](CircularNode<T> *node, int index) -> bool {
        return callback(node->get_data());
    });
}

template<typename T>
std::optional<T> CircularDoublyLinkedList<T>::find(std::function<bool(T, int)> callback) {
    return find([&](CircularNode<T> *node, int index) -> bool {
        return callback(node->get_data(), index);
    });
}

template <typename T>
void CircularDoublyLinkedList<T>::clear() {
    while (!empty()) {
        remove_at(0);
    }
}

template <typename T>
int CircularDoublyLinkedList<T>::size() {
    return _size;
}

template <typename T>
bool CircularDoublyLinkedList<T>::empty() {
    return _size == 0;
}

template<typename T>
CircularNode<T> *CircularDoublyLinkedList<T>::last() {
    if (_size == 0) {
        return nullptr;
    }
    
    return at(_size - 1);
}

template<typename T>
CircularNode<T> *CircularDoublyLinkedList<T>::at(int index) {
    if (index < 0 || index >= _size) {
        throw std::invalid_argument("index out of bounds");
    }

    if (index == 0) {
        return head;
    }

    int current_index = 0;
    CircularNode<T> * current = head;

    while (true) {
        if (current_index > 0 && current == head) {
            break;
        }

        if (current_index == index) {
            return current;
        }

        current_index++;
        current = current->get_next();
    }

    return current;
}
