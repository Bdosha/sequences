#ifndef NODE_H
#define NODE_H

template<class T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node();
    Node(T data);
};


#endif //NODE_H
