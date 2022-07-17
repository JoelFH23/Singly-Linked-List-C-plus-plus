#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include <iostream>
#include <Node.h>

using namespace std;

template <class DataType>
class SinglyLinkedList: private Node<DataType>{
private:
    Node<DataType>* head;
    int count;
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    Node<DataType>* getHead();
    Node<DataType>* getLastNode();
    Node<DataType>* getNode(int position);
    Node<DataType>* getPrevNode(Node<DataType>*);
    int getCount();
    int findIndex(int element);
    void insertAtSpecificPosition(int position, DataType data);
    void insertAtTheEnd(DataType data);
    void insertAtTheBeginning(DataType data);
    void removeSpecificNode(int position);
    void removeLastNode();
    void removeFirstNode();
    void printList();
};

template <class DataType>
void SinglyLinkedList<DataType>::removeFirstNode(){
    removeSpecificNode(0);
}
template <class DataType>
void SinglyLinkedList<DataType>::removeLastNode(){
    removeSpecificNode(count);
}
template <class DataType>
void SinglyLinkedList<DataType>::removeSpecificNode(int position){
    if( position < 0 || !count ) return;
    if( count == 1 ){//the list only have one item
        head = head->getNext();
        delete head;
    } else if ( position >= count){//Removing the last item
        Node<DataType>* currentNode = getNode(count);
        Node<DataType>* prevNode = getPrevNode(currentNode);
        prevNode->setNext(currentNode->getNext());
        delete currentNode;
    } else if( position == 0 ){// Removing the first item
        Node<DataType>* temp = head;
        head = temp->getNext();
        delete temp;
    } else{//Removing a specific item
        Node<DataType>* currentNode = getNode(position);
        Node<DataType>* prevNode = getPrevNode(currentNode);
        prevNode->setNext(currentNode->getNext());
        delete currentNode;
    }
    count--;
}
template <class DataType>
void SinglyLinkedList<DataType>::insertAtSpecificPosition(int position, DataType data){
    if( position < 0) return;
    Node<DataType>* newNode = new Node<DataType>(data);
    if( !count ){
        head = newNode;
    } else{
        if( position == 0 ){// when insert in the first position
            newNode->setNext(head);
            head = newNode;
        } else if( position >= count ){ // insert in last position
            getLastNode()->setNext(newNode);
        } else{
            Node<DataType>* currentNode = getNode(position);
            Node<DataType>* prevNode = getPrevNode(currentNode);
            newNode->setNext(currentNode);
            prevNode->setNext(newNode);
        }
    }
    count++;
}
template <class DataType>
void SinglyLinkedList<DataType>::insertAtTheEnd(DataType data){
    insertAtSpecificPosition(count, data);
}
template <class DataType>
void SinglyLinkedList<DataType>::insertAtTheBeginning(DataType data){
    insertAtSpecificPosition(0, data);
}
template <class DataType>
Node<DataType>* SinglyLinkedList<DataType>::getPrevNode(Node<DataType>* currentNode){
    Node<DataType>* aux = head;
    while( aux->getNext() != nullptr){
        if( aux->getNext() == currentNode) break;
        aux = aux->getNext();
    }
    return aux;
}
template <class DataType>
int SinglyLinkedList<DataType>::findIndex(int element){
    if( !count ) return -1;
    Node<DataType>* aux = head;
    int i = 0;
    while( aux->getNext() != nullptr ){
        if( *aux->getData() == element ) return i;
        aux = aux->getNext();
        i++;
    }
    return -1;
}
template <class DataType>
Node<DataType>* SinglyLinkedList<DataType>::getNode(int position){
    if( position < 0 || position > count) return nullptr;
    Node<DataType>* aux = head;
    int i = 0;
    while( aux->getNext() != nullptr){
        if( i == position ) break;
        aux = aux->getNext();
        i++;
    }
    return aux;
}
template <class DataType>
Node<DataType>* SinglyLinkedList<DataType>::getLastNode(){
    Node<DataType>* aux = head;
    while( aux->getNext() != nullptr ){
        aux = aux->getNext();
    }
    return aux;
}

template <class DataType>
void SinglyLinkedList<DataType>::printList(){
    if( !count ){
        cout<<"\tNo data found!"<<endl;
        return;
    }
    Node<DataType>* aux = head;
    while( aux ){
        cout<<*aux->getData()<<", ";
        if( aux->getNext() == nullptr) break;
        aux = aux->getNext();
    }
    cout<<endl;
}
template <class DataType>
Node<DataType>* SinglyLinkedList<DataType>::getHead(){
    return head;
}
template <class DataType>
int SinglyLinkedList<DataType>::getCount(){
    return count;
}
template <class DataType>
SinglyLinkedList<DataType>::SinglyLinkedList(){
    head = nullptr;
    count = 0;
}
template <class DataType>
SinglyLinkedList<DataType>::~SinglyLinkedList(){}

#endif // SINGLYLINKEDLIST_H
