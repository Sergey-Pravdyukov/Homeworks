#include <iostream>

#include "pointerlinkedlist.h"
#include "arraylinkedlist.h"
#include "pointerlisttest.h"
#include "arraylisttest.h"

#include <QtTest/QtTest>

using namespace std;

void operations(List *currentList)
{
    cout << "begin" << endl;
    currentList->add(9);
    currentList->remove(6);
    currentList->debugOutput();
    currentList->add(5);
    currentList->remove(9);
    cout << "Current lenght of list: " << currentList->lenght() << endl;
    currentList->add(4);
    currentList->debugOutput();
    currentList->add(17);
    cout << "Current lenght of list: " << currentList->lenght() << endl;
    currentList->debugOutput();
    currentList->remove(4);
    currentList->remove(17);
    cout << "Current lenght of list: " << currentList->lenght() << endl;
    currentList->debugOutput();
    cout << "end" << endl << endl;
}

int main()
{
    List *pointerList = new PointerLinkedList();
    cout << "Pointer linked list: " << endl;
    operations(pointerList);
    PointerListTest testPointerList;
    QTest::qExec(&testPointerList);

    List *arrayList = new ArrayLinkedList();
    cout << "Array linked list: " << endl;
    operations(arrayList);
    ArrayListTest testArrayList;
    QTest::qExec(&testArrayList);
    return 0;
}
