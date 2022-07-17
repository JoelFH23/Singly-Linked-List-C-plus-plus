#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template <class DataType>
class Node{
private:
    DataType data;
    Node<DataType>* next;
public:
    Node();
    Node(DataType data);
    ~Node();
    Node<DataType>* getNext();
    DataType* getData();
    void setNext(Node<DataType> *next);
};

template <class DataType>
void Node<DataType>::setNext(Node<DataType>* next){
    this->next = next;
}

template <class DataType>
DataType* Node<DataType>::getData(){
    return &data;
}

template <class DataType>
Node<DataType>* Node<DataType>::getNext(){
    return next;
}

template <class DataType>
Node<DataType>::Node(){
    next = nullptr;
}

template <class DataType>
Node<DataType>::Node(DataType data){
    this->data = data;
    next = nullptr;
}
template <class DataType>
Node<DataType>::~Node(){}


#endif // NODE_H
