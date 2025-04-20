#include "Testing/Testing.h"
#include <iostream>
#include "Sequences/Sequence.h"
// #include "Types/Types.h"
#include "Types/Set.h"

int main() {
    // dynamic_array();
    mainTest();
    std::cout << "\n\n\nHello World!\n";
    Set<Set<int> > sets;
    //
    Set<int> set1;
    Set<int> set2;
    Set<int> set3;
    set1.add(2).add(4);
    set2.add(2).add(3).add(4);
    set3.add(2).add(3).add(4).add(5);
    sets.add(set1).add(set3).add(set2);
    // //
    MutableArraySequence<Set<Set<int> > > array;
    std::cout << array << std::endl;

    array.append(sets)->append(sets.remove(set2));
    //
    //
    //
    // std::cout << sets << std::endl;
    //
    std::cout << array << std::endl;
    //
    // // for (int i = -10e3; i < 10e3; i++) set1.add(i);
    // MutableArraySequence<int> arr;
    // for (int i = -10e4; i < 10e4; i++) arr.append(i);
    //
    // // std::cout << set1 << std::endl;
    //
    // std::cout << arr << std::endl;

    return 0;
}
