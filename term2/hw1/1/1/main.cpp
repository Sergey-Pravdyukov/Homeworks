#include <iostream>
#include "list.h"
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
    pointerList->add(4);
    pointerList->debugOutput();
    pointerList->add(17);
    pointerList->debugOutput();
    pointerList->remove(4);
    pointerList->remove(17);
    pointerList->debugOutput();
    cout << "end" << endl << endl;
    delete pointerList;
    List *arrayList = new ArrayLinkedList();
    cout << "begin" << endl;
    arrayList->add(9);
    arrayList->remove(6);
    arrayList->debugOutput();
    arrayList->add(5);
    arrayList->remove(9);
    arrayList->add(4);
    arrayList->debugOutput();
    arrayList->add(17);
    arrayList->debugOutput();
    arrayList->remove(4);
    arrayList->remove(17);
    arrayList->debugOutput();
    cout << "end" << endl;
    delete arrayList;
    return 0;
}
