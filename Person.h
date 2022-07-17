#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <SinglyLinkedList.h>

using namespace std;

class Person {
protected:
    string name;
    string last_name;
    int age;
public:
    Person();
    ~Person();
    Person(string name, string last_name, int age);
    string getName();
    string getLastName();
    int getAge();
    void showPerson(SinglyLinkedList<Person> &person);
};

void Person::showPerson(SinglyLinkedList<Person> &person){
    if( !person.getCount() ){
        cout<<"No Data Found!"<<endl;
        return;
    }
    for( int i=0; i<person.getCount(); i++){
        cout<<"Name: "<<person.getNode(i)->getData()->name<<endl;
        cout<<"Last Name: "<<person.getNode(i)->getData()->last_name<<endl;
        cout<<"Age: "<<person.getNode(i)->getData()->age<<endl<<endl;
    }
}

int Person::getAge(){
    return age;
}
string Person::getLastName(){
    return last_name;
}
string Person::getName(){
    return name;
}
Person::Person(string name, string last_name, int age){
    this->name = name;
    this->age = age;
    this->last_name = last_name;
}
Person::Person(){
    name = "";
    last_name = "";
    age = 0;
}

Person::~Person(){}

#endif // PERSON_H
