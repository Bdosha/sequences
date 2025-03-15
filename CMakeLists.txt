cmake_minimum_required(VERSION 3.29)
project(lab_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_2 main.cpp
        Sequences/Array/capsule/DynamicArray.h
        Sequences/Array/capsule/DynamicArray.cpp
        Sequences/LinkedList/capsule/LinkedList.cpp
        Sequences/LinkedList/capsule/LinkedList.h
        Sequences/LinkedList/capsule/Node.cpp
        Sequences/LinkedList/capsule/Node.h
        Sequences/Sequence.h
        Sequences/LinkedList/basic/ListSequence.cpp
        Sequences/LinkedList/basic/ListSequence.h
        Sequences/Array/basic/ArraySequence.cpp
        Sequences/Array/basic/ArraySequence.h
        Sequences/Array/basic/ArraySequence.cpp
        Sequences/Array/basic/ArraySequence.cpp
        Sequences/Sequences.h
        Sequences/Array/ArraySequences.h
        Sequences/Sequence.cpp
        #        Testing.cpp
)
