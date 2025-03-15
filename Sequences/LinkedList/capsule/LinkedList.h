#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

template<class T>
class LinkedList {
public:
    LinkedList();

    LinkedList(T *items, int count);

    LinkedList(LinkedList<T> &list);

    ~LinkedList();

    T& getFirst();

    T& getLast();

    T& get(int index);

    T& operator[](int index);


    void getSubList(int startIndex, int endIndex);

    unsigned int getLength() const;

    void append(T item);

    void prepend(T item);

    void insertAt(T item, int index);

    void print();

    LinkedList *concat(LinkedList *list);
    void set(int index, T value);


private:
    Node<T> *head;
    Node<T> *tail;
    unsigned int size{};

    Node<T> *getP(int index);

    bool check_index(int index) const;

    void init();

    void remove();
};


#endif
