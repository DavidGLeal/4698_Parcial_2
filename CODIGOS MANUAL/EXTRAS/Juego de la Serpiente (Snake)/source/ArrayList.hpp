/**
 * @file ArrayList.hpp
 * @brief Data structure that use a dinamic array
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include <cstddef>
#include <initializer_list>

template <typename T>
class ArrayList {
    private:
        T* m_array{};
        std::size_t m_size{};
        std::size_t m_capacity{};
        const std::size_t m_increment{10};

        /**
         * @brief Verify if m_array is full
         * 
         * @return true 
         * @return false 
         */
        bool isFull();

        /**
         * @brief Increment the size of m_array
         * 
         */
        void resize();

        /**
         * @brief Copy all elements of a list
         * 
         * @param list 
         */
        void copy(const ArrayList<T>& list);

    public:
        /**
         * @brief Construct a new Array List object
         * 
         * @param list 
         */
        explicit ArrayList(std::initializer_list<T> list);

        /**
         * @brief Construct a new Array List object
         * 
         * @param list 
         */
        ArrayList(const ArrayList<T>& list);

        /**
         * @brief Construct a new Array List object
         * 
         * @param initialCapacity 
         * @param increment 
         */
        explicit ArrayList(std::size_t initialCapacity = 10, std::size_t increment = 10);

        /**
         * @brief Returns a pointer with the initial position of array elements
         * 
         * @return T* const 
         */
        T* const begin();

        /**
         * @brief Returns a pointer with the next position of last position in the array elements
         * 
         * @return T* const 
         */
        T* const end();

        /**
         * @brief Returns a pointer with the initial position of array elements
         * 
         * @return T* const 
         */
        const T* const begin() const;

        /**
         * @brief Returns a pointer with the next position of last position in the array elements
         * 
         * @return T* const 
         */
        const T* const end() const;

        /**
         * @brief Verify if ArrayList have elements
         * 
         * @return true 
         * @return false 
         */
        bool isEmpty() const;

        /**
         * @brief Return the number of elements
         * 
         * @return std::size_t 
         */
        std::size_t size() const;

        /**
         * @brief Delete all elements of the array
         * 
         */
        void clear();

        /**
         * @brief Insert a new element at the first position of array
         * 
         * @param element 
         */
        void addFirst(const T& element);

        /**
         * @brief Insert a new element at the last position of array
         * 
         * @param element 
         */
        void addLast(const T& element);

        /**
         * @brief Insert a new element in the specified position of array
         * 
         * @param index Value between zero and size
         * @param element 
         * @return true 
         * @return false 
         */
        bool add(std::size_t index, const T& element);

        /**
         * @brief Return an element in a specified position of array
         * 
         * @param index 
         * @return const T& 
         */
        const T& get(std::size_t index) const;

        /**
         * @brief Return an element in a specified position of array
         * 
         * @param index 
         * @return const T& 
         */
        T& operator[](std::size_t index);

        /**
         * @brief Return an element in a specified position of array
         * 
         * @param index 
         * @return const T& 
         */
        const T& operator[](std::size_t index) const;

        /**
         * @brief Delete the element in the specified position of array
         * 
         * @param index Value between zero and size
         * @return T Element erased
         */
        T remove(std::size_t index);

        /**
         * @brief Replace an element in the specified position of array
         * 
         * @param index Value between zero and size
         * @param element 
         * @return T Element replaced
         */
        T set(std::size_t index, const T& element);

        /**
         * @brief Operator override for copy array of list
         * 
         * @param list 
         */
        void operator=(const ArrayList<T>& list);
        ~ArrayList();
};

template <typename T>
bool ArrayList<T>::isFull(){
    return m_size >= m_capacity;
}

template <typename T>
void ArrayList<T>::resize() {
    m_capacity = m_size + m_increment;
    T* newArray = new T[m_capacity]{};

    for (std::size_t i{}; i < m_size; ++i)
        newArray[i] = m_array[i];

    delete[] m_array;
    m_array = newArray;
    newArray = nullptr;
}

template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& list) {
    if (m_array != nullptr)
        delete[] m_array;

    m_array = new T[list.m_size]{};
    m_size = list.m_size;
    m_capacity = list.m_capacity;

    for (std::size_t i{}; i < m_size; ++i)
        m_array[i] = list.m_array[i];
}

template <typename T>
ArrayList<T>::ArrayList(std::initializer_list<T> list) : ArrayList(list.size() + 10, 10) {
    m_size = list.size();
    m_array = new T[m_size]{};

    std::size_t i{};
    for (T element : list) {
        m_array[i] = element;
        ++i;
    }
        
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& list) {
    copy(list);
}

template <typename T>
ArrayList<T>::ArrayList(std::size_t initialCapacity, std::size_t increment) : m_capacity{initialCapacity}, m_increment{increment} {
    m_array = new T[m_capacity]{};
}

template <typename T>
T* const ArrayList<T>::begin() {
    return m_array;
}

template <typename T>
T* const ArrayList<T>::end() {
    return &m_array[m_size];
}

template <typename T>
const T* const ArrayList<T>::begin() const {
    return m_array;
}

template <typename T>
const T* const ArrayList<T>::end() const {
    return &m_array[m_size];
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
    return m_size <= 0 || m_array == nullptr;
}

template <typename T>
std::size_t ArrayList<T>::size() const {
    return m_size;
}

template <typename T>
void ArrayList<T>::clear() {
    delete[] m_array;
    m_capacity = 10;
    m_array = new T[m_capacity]{};

    m_size = 0;
}

template <typename T>
void ArrayList<T>::addFirst(const T& element) {
    if (isEmpty()) {
        m_array[m_size] = element;

    } else {
        for (std::size_t i{m_size}; i > 0; --i)
            m_array[i] = m_array[i - 1];

        m_array[0] = element;
    }

    ++m_size;

    if (isFull())
        resize();
}

template <typename T>
void ArrayList<T>::addLast(const T& element) {
    m_array[m_size] = element;

    ++m_size;

    if (isFull())
        resize();
}

template <typename T>
bool ArrayList<T>::add(std::size_t index, const T& element) {
    if (index < 0 || index >= m_size)
        return false;

    if (index == 0) {
        addFirst(element);
        return true;
    }

    if (index == m_size - 1) {
        addLast(element);
        return true;
    }

    for (std::size_t i{m_size}; i > index; --i) {
        m_array[i] = m_array[i - 1];
    }

    m_array[index] = element;

    ++m_size;

    if (isFull())
        resize();

    return true;
}

template <typename T> 
const T& ArrayList<T>::get(std::size_t index) const {
    if (index < 0 || index >= m_size)
        throw "IndexOutOfBoundsException.";

    return m_array[index];
}

template <typename T>
T& ArrayList<T>::operator[](std::size_t index) {
    if (index < 0 || index >= m_size)
        throw "IndexOutOfBoundsException.";

    return m_array[index];
}

template <typename T>
const T& ArrayList<T>::operator[](std::size_t index) const {
    return get(index);
}

template <typename T>
T ArrayList<T>::remove(std::size_t index) {
    if (index < 0 || index >= m_size)
        throw "IndexOutOfBoundsException.";

    T elementErased { get(index) };

    T *newArray = new T[m_capacity]{};

    std::size_t j{};
    for (std::size_t i{}; i < m_size; ++i) {
        if (i != index) {
            newArray[j] = m_array[i];
            ++j;
        }
    }

    delete[] m_array;
    m_array = newArray;
    newArray = nullptr;

    --m_size;

    return elementErased;
}

template <typename T>
T ArrayList<T>::set(std::size_t index, const T& element) {
    if (index < 0 || index >= m_size)
        throw "IndexOutOfBoundsException.";

    T elementErased { get(index) };

    m_array[index] = element;

    return elementErased;
}

template <typename T>
void ArrayList<T>::operator=(const ArrayList<T>& list) {
    if (this != &list)
        copy(list);
}

template <typename T>
ArrayList<T>::~ArrayList() {
    if (m_array != nullptr) {
        delete[] m_array;
        m_array = nullptr;
    }
}

#endif