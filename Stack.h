#ifndef STACK_H
#define STACK_H
#include <SinglyLinkedList.h>

template <class DataType>
class Stack: private SinglyLinkedList<DataType> {
public:
    Stack();
    ~Stack();
    void push(DataType data);
    void pop();
    void showStack();
};

template <class DataType>
void Stack<DataType>::push( DataType data ){
    this->insertAtTheBeginning( data );
}
template <class DataType>
void Stack<DataType>::pop(){
    this->removeFirstNode();
}
template <class DataType>
void Stack<DataType>::showStack(){
    if( !this->getCount() ){
        cout<<"No Data Found!"<<endl;
        return;
    }
    for( int i=0; i<this->getCount(); i++){
        cout<<"\t"<<*this->getNode(i)->getData()<<endl;
    }
    cout<<endl;
}

template <class DataType>
Stack<DataType>::~Stack(){};

template <class DataType>
Stack<DataType>::Stack(){};

#endif // STACK_H
