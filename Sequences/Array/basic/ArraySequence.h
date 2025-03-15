#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H
#include "../capsule/DynamicArray.cpp"
#include "../../Sequence.h"


template<class T>
class ArraySequence : public Sequence<T> {
public:
    explicit ArraySequence(DynamicArray<T> &other);

    explicit ArraySequence(Sequence<T> &other);

    ArraySequence();

    ArraySequence(T *items, int count);

    T& getFirst() override;

    T& getLast() override;

    T& get(int index) override;
    T& operator[](int index);
    // T& operator[](int);


    int getSize() override;

    Sequence<T> *append(T item) override;

    Sequence<T> *prepend(T item) override;

    Sequence<T> *insertAt(T item, int index) override;

    void print() override;

    Sequence<T> *getSubsequence(int startIndex, int endIndex) override;

    Sequence<T> *set(int index, T value) override;

private:
    DynamicArray<T> *list;

    Sequence<T> *inAppend(T item) override;

    Sequence<T> *inSet(int index, T item) override;

    Sequence<T> *inPrepend(T item) override;

    Sequence<T> *inInsertAt(T item, int index) override;

    Sequence<T> *inGetSubsequence(int startIndex, int endIndex) override;


    Sequence<T> *clone() override =0;

    Sequence<T> *instance() override =0;
};


#endif
