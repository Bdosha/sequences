#include "LinkedList.h"
#include "Node.cpp"
#include <iostream>


template<class T>
void LinkedList<T>::init() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<class T>
void LinkedList<T>::remove() {
    if (head == nullptr) return;
    Node<T> *current = head;
    while (current->next != nullptr) {
        current = current->next;

        delete current->prev;
    }
    delete current;
}

template<class T>
bool LinkedList<T>::check_index(const int index) const {
    return index < 0 || index >= size;
}

template<class T>

LinkedList<T>::LinkedList() {
    init();
}

template<class T>
LinkedList<T>::~LinkedList() {
    remove();
}


template<class T>
LinkedList<T>::LinkedList(T *items, int count) {
    init();
    for (int i = 0; i < count; i++) {
        append(items[i]);
    }
}

template<class T>
LinkedList<T>::LinkedList(LinkedList &list) {
    init();
    for (int i = 0; i < list.getLength(); i++) {
        append(list[i]);
    }
}

template<class T>
T &LinkedList<T>::getFirst() {
    if (check_index(0)) throw std::out_of_range("index out of range");

    return head->data;
}

template<class T>
T &LinkedList<T>::getLast() {
    if (check_index(0)) throw std::out_of_range("index out of range");

    return tail->data;
}

template<class T>
Node<T> *LinkedList<T>::getP(int index) {
    if (check_index(index)) throw std::out_of_range("index out of range");

    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

template<class T>
T &LinkedList<T>::get(const int index) {
    return getP(index)->data;
}

template<class T>
T &LinkedList<T>::operator[](const int index) {
    return get(index);
}


template<class T>
void LinkedList<T>::append(T item) {
    auto *newNode = new Node<T>(item);
    size++;

    if (size == 1) {
        head = newNode;
        tail = newNode;
        return;
    }


    newNode->prev = tail;

    tail->next = newNode;
    tail = newNode;
}

template<class T>
void LinkedList<T>::prepend(T item) {
    auto *newNode = new Node<T>(item);
    size++;

    if (size == 1) {
        head = newNode;
        tail = newNode;
        return;
    }


    newNode->next = head;

    head->prev = newNode;
    head = newNode;
}


template<class T>
void LinkedList<T>::getSubList(int startIndex, int endIndex) {
    if (check_index(startIndex) || check_index(endIndex) || startIndex > endIndex)
        throw std::out_of_range(
            "index out of range");

    Node<T> *current = getP(startIndex);
    T *newData = new T[endIndex - startIndex + 1];
    for (int i = startIndex; i < endIndex; i++) {
        newData[i - startIndex] = current->data;
        current = current->next;
    }

    remove();
    init();

    for (int i = 0; i < endIndex - startIndex; i++) {
        append(newData[i]);
    }
    delete []newData;
}

template<class T>
unsigned int LinkedList<T>::getLength() const {
    return size;
}


template<class T>
void LinkedList<T>::print() {
    if (size == 0) return;

    Node<T> *current = head;
    for (int i = 0; i < size; i++) {
        std::cout << current->data << " ";
        current = current->next;
    }


    std::cout << std::endl;
}

template<class T>
void LinkedList<T>::insertAt(T item, int index) {
    if (check_index(index)) {
        throw std::out_of_range("index out of range");
    }
    Node<T> *Next = getP(index);
    Node<T> *Prev = Next->prev;
    auto *newNode = new Node<T>(item);
    Next->prev = newNode;
    newNode->next = Next;
    Prev->next = newNode;
    newNode->prev = Prev;
    size++;
}

template<class T>
LinkedList<T> *LinkedList<T>::concat(LinkedList<T> *list) {
    auto *newList = new LinkedList<T>();
    Node<T> *current = head;
    for (int i = 0; i < getLength(); i++) {
        newList->append(current->data);
        current = current->next;
    }
    current = list->head;
    for (int i = 0; i < list->getLength(); i++) {
        newList->append(current->data);
        current = current->next;
    }
    return newList;
}

template<class T>
void LinkedList<T>::set(int index, T value) {
    getP(index)->data = value;
}
