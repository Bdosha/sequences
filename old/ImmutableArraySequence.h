// #ifndef IMMUTABLEARRAYSEQUENCE_H
// #define IMMUTABLEARRAYSEQUENCE_H
// #include "basic/ArraySequence.h"
//
// template<class T>
// class ImmutableArraySequence : public ArraySequence<T> {
// public:
//     ImmutableArraySequence() : ArraySequence<T>() {
//     }
//
//     ImmutableArraySequence(T *items, int count) : ArraySequence<T>(items, count) {
//     }
//
//     ImmutableArraySequence(DynamicArray<T> other) : ArraySequence<T>(other) {
//     }
//
// private:
//
//     Sequence<T> *clone();
//
//     Sequence<T> *instance();
//
// };
//
//
// #endif