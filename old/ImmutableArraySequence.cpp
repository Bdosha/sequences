// //#include "basic/ArraySequence.cpp"
// #include "ArraySequences.h"
//
//
// template<class T>
// Sequence<T> *ImmutableArraySequence<T>::clone() {
//     DynamicArray<T> arr = *this->list;
//
//     T *n = new T[arr.getSize()];
//     for (int i = 0; i < arr.getSize(); i++) {
//         n[i] = arr[i];
//     }
//     auto *seq = new ImmutableArraySequence(n, arr.getSize());
//
//     return seq;
//     //return nullptr;
// }
//
// template<class T>
// Sequence<T> *ImmutableArraySequence<T>::instance() {
//     return this->clone();
// }
