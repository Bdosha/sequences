#include "Sequence.h"

template<class T>
Sequence<T> *Sequence<T>::concat(Sequence &seq) {
    Sequence *result = instance();
    for(int i = 0; i < seq.getSize(); i++) {
        result->inAppend(seq.get(i));
    }
    return result;
}


template<class T>
Sequence<T> *concat(Sequence<T> *s1, Sequence<T> *s2) {
    Sequence<T> *result = s1->construct();
    for(int i = 0; i < s1->getSize(); i++) {
        result->inAppend(s1->get(i));
    }
    for(int i = 0; i < s2->getSize(); i++) {
        result->inAppend(s2->get(i));
    }
    return result;
}

template<class T>
Sequence<T> *map(T F(T), Sequence<T> *seq) {
    Sequence<T> *result = seq->construct();
    for (int i = 0; i < seq->getSize(); i++) {
        result = result->append(F(seq->get(i)));
    }
    return result;
}

template<class T>
Sequence<T> *where(bool F(T), Sequence<T> *seq) {
    Sequence<T> *result = seq->construct();
    for (int i = 0; i < seq->getSize(); i++) {
        if (F(seq->get(i))) result = result->append(seq->get(i));
    }
    return result;
}


template<class T>
T reduce(T F(T, T), Sequence<T> *seq, T start) {
    if (seq->getSize() == 0) return start;
    T result = F(seq->get(0), start);

    for (int i = 1; i < seq->getSize(); i++) {
        result = F(seq->get(i), result);
    }

    return result;
}
