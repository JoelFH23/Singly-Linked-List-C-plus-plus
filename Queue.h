#ifndef QUEUE_H
#define QUEUE_H
#include <SinglyLinkedList.h>

template <class DataType>
class Queue: private SinglyLinkedList<DataType>{
public:
    Queue();
    ~Queue();
    void enqueue( DataType data );
    void dequeue();
    void showQueue();
};
template <class DataType>
void Queue<DataType>::enqueue( DataType data ){
    this->insertAtTheBeginning(data);
}
template <class DataType>
void Queue<DataType>::dequeue(){
    this->removeLastNode();
}
template <class DataType>
void Queue<DataType>::showQueue(){
    this->printList();
}
template <class DataType>
Queue<DataType>::~Queue(){}

template <class DataType>
Queue<DataType>::Queue(){}

#endif // QUEUE_H
