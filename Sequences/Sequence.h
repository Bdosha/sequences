#ifndef SEQUENCE_H
#define SEQUENCE_H


template<class T>
class Sequence {
public:
    virtual ~Sequence() = default;

    virtual T &getFirst() = 0;

    virtual T &getLast() =0;

    virtual T &get(int index) =0;

    virtual Sequence *set(int index, T value) =0;

    virtual Sequence *inSet(int index, T item) =0;

    virtual int getSize() =0;

    virtual Sequence *append(T item) = 0;

    virtual Sequence *prepend(T item) =0;

    virtual Sequence *insertAt(T item, int index) =0;

    virtual Sequence *getSubsequence(int startIndex, int endIndex) =0;

    virtual void print() =0;

    virtual Sequence *inGetSubsequence(int startIndex, int endIndex) =0;

    virtual Sequence *inAppend(T item) =0;

    virtual Sequence *inPrepend(T item) =0;

    virtual Sequence *inInsertAt(T item, int index) =0;

    virtual Sequence *construct() =0;

    Sequence *concat(Sequence &);

    // virtual void operator=

private:
    virtual Sequence *clone() =0;

    virtual Sequence *instance() =0;
};

template<class T>
Sequence<T> *concat(Sequence<T> *s1, Sequence<T> *s2);

template<class T>
Sequence<T> *map(T F(T), Sequence<T> *seq);

template<class T>
Sequence<T> *where(bool F(T), Sequence<T> *seq);

template<class T>
T reduce(T F(T, T), Sequence<T> *seq, T start);

#endif
