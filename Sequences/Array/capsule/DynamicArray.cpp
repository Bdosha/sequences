#include "DynamicArray.h"
#include <iostream>


template<class T>
DynamicArray<T>::DynamicArray() {
    capacity = 1;
    size = 0;
    items = new T[capacity];
}

template<class T>
void DynamicArray<T>::init(unsigned int size) {
    if (size == 0) {
        DynamicArray();
        return;
    }
    capacity = static_cast<int>(pow(2, log2(size) + 1)); //TODO
    this->size = size;
    items = new T[size];
}


template<class T>
void DynamicArray<T>::copy(const T *array, unsigned int count) {
    for (int i = 0; i < count; i++) {
        items[i] = array[i];
    }
}

template<class T>
unsigned int DynamicArray<T>::getSize() const {
    return this->size;
}

template<class T>
DynamicArray<T>::DynamicArray(const int size) {
    init(size);
}

template<class T>
DynamicArray<T>::~DynamicArray() {
    delete[] items;
}

template<class T>
DynamicArray<T>::DynamicArray(const T *items, const int count) {
    init(count);
    copy(items, count);
}

template<class T>
DynamicArray<T>::DynamicArray(DynamicArray &other) {
    int size = other.getSize();

    init(size);
    for (int i = 0; i < size; i++) {
        items[i] = other[i];
    }
}

template<class T>
void DynamicArray<T>::print() {
    for (int i = 0; i < size; i++) {
        std::cout << items[i] << " ";
    }
    std::cout << std::endl;
}

template<class T>
bool DynamicArray<T>::check_index(const int index) const {
    return index < 0 || index >= size;
}

template<class T>
T &DynamicArray<T>::get(int index) const {
    if (check_index(index)) throw std::out_of_range("index out of range");

    return items[index];
}


template<class T>
T &DynamicArray<T>::operator[](const int index) const {
    return get(index);
}

// template<class T>
// T DynamicArray<T>::operator[](int& index) const {
//     return get(index);
// }


template<class T>
void DynamicArray<T>::set(int index, T value) {
    if (check_index(index)) throw std::out_of_range("index out of range");
    items[index] = value;
}


template<class T>
void DynamicArray<T>::resize(const unsigned int newSize) {
    T *newItems = new T[newSize];
    for (int i = 0; i < std::min(newSize, size); i++) {
        newItems[i] = items[i];
    }
    delete[] items;

    init(newSize);
    items = newItems;
}
