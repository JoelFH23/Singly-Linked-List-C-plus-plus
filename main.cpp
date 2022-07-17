//Create at 15/06/2022 by Joel Flores
#include <iostream>
#include <SinglyLinkedList.h>
#include <Queue.h>
#include <Stack.h>
#include <Person.h>

using namespace std;

int main(){
    SinglyLinkedList<Person> linkedList;
    Person person("Joel","Flores",25);
    Person person2("Tania","Gonzales",24);
    linkedList.insertAtTheBeginning(person);
    linkedList.insertAtTheBeginning(person2);
    cout<<"Printing Objects"<<endl;
    person.showPerson(linkedList);

    SinglyLinkedList<float> link;
    cout<<"\nPrinting Floats"<<endl;
    link.insertAtTheBeginning(15.55);
    link.insertAtTheBeginning(783.2);
    link.insertAtTheBeginning(87.1);
    link.printList();

    SinglyLinkedList<int> linkInt;
    cout<<"\nPrinting Integers"<<endl;
    linkInt.insertAtTheBeginning(55);
    linkInt.insertAtTheBeginning(784);
    linkInt.insertAtTheBeginning(29);
    linkInt.printList();


    SinglyLinkedList<char> linkChar;
    cout<<"\nPrinting Characters"<<endl;
    linkChar.insertAtTheBeginning('a');
    linkChar.insertAtTheBeginning('y');
    linkChar.insertAtTheBeginning('h');
    linkChar.printList();

    SinglyLinkedList<string> linkString;
    cout<<"\nPrinting strings"<<endl;
    linkString.insertAtTheBeginning("Hola");
    linkString.insertAtTheBeginning("Hello");
    linkString.insertAtTheBeginning("привет");
    linkString.printList();

    cout<<"\n\n\nAll OK!"<<endl;
    return 0;
}
