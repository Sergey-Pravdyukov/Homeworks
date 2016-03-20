#include <iostream>

#include "pointerlinkedlist.h"
#include "arraylinkedlist.h"

using namespace std;

int main()
{
    List *pointerList = new PointerLinkedList();
    cout << "begin" << endl;
    pointerList->add(9);
    pointerList->remove(6);
    pointerList->debugOutput();
    pointerList->add(5);
    pointerList->remove(9);
    cout << "Current lenght of list: " << pointerList->lenght() << endl;
    pointerList->add(4);
    pointerList->debugOutput();
    pointerList->add(17);
    cout << "Current lenght of list: " << pointerList->lenght() << endl;
    pointerList->debugOutput();
    pointerList->remove(4);
    pointerList->remove(17);
    cout << "Current lenght of list: " << pointerList->lenght() << endl;
    pointerList->debugOutput();
    cout << "end" << endl << endl;
    List *arrayList = new ArrayLinkedList();
    cout << "begin" << endl;
    arrayList->add(9);
    arrayList->remove(6);
    arrayList->debugOutput();
    arrayList->add(5);
    arrayList->remove(9);
    cout << "Current lenght of list: " << arrayList->lenght() << endl;
    arrayList->add(4);
    arrayList->debugOutput();
    arrayList->add(17);
    cout << "Current lenght of list: " << arrayList->lenght() << endl;
    arrayList->debugOutput();
    arrayList->remove(4);
    arrayList->remove(17);
    cout << "Current lenght of list: " << arrayList->lenght() << endl;
    arrayList->debugOutput();
    cout << "end" << endl;
    return 0;
}
