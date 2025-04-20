#ifndef TESTING_H
#define TESTING_H
#include <iostream>

void testing(const char *string, bool check) {
    if (check)std::cout << string << " -> " << "OK" << std::endl;
    else std::cerr  << string << " -> " << "FAILED" << std::endl;
}

template<class T>
void print(T *seq) {
    for (int i = 0; i < seq->getSize(); i++) {
        std::cout << seq->get(i) << ' ';
    }
    std::cout << std::endl;
}


#include "capsule.cpp"
#include "sequences.cpp"
#include "types.cpp"

inline void mainTest() {
    test_capsules();
    mainSequencesTest();
    test_deque();
    test_set();
}



#endif
