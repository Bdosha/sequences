#ifndef LISTSEQUENCE_H
#define LISTSEQUENCE_H
#include "../capsule/LinkedList.cpp"
#include "../../Sequence.h"

template<class T>
class ListSequence : public Sequence<T> {
public:
    explicit ListSequence(LinkedList<T>);

    explicit ListSequence(Sequence<T>&);

    ListSequence();

    ListSequence(T *, int);

    ~ListSequence() override;

    T& getFirst() override;

    T& getLast() override;

    T& get(int) override;
    T& operator[](int index) const;


    int getSize() override;

    Sequence<T> *append(T) override;

    Sequence<T> *prepend(T) override;

    Sequence<T> *insertAt(T, int) override;

    void print() override;


    Sequence<T> *getSubsequence(int, int) override;

    Sequence<T> *inGetSubsequence(int, int) override;

    Sequence<T> *construct() override {
        return new ListSequence();
    }
    Sequence<T> *set(int index, T value) override;

private:
    Sequence<T> *inSet(int index, T item) override;

    LinkedList<T> *list;

    void init();

    Sequence<T> *clone() override;

    ListSequence *instance() override;

    Sequence<T> *inAppend(T) override;

    Sequence<T> *inPrepend(T) override;

    Sequence<T> *inInsertAt(T, int) override;
};


#endif
