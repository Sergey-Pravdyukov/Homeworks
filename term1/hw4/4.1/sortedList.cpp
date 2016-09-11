#include <iostream>
#include "sortedList.h"

using namespace std;

void add(List *currentList, int value)
{
    ListElement *newElement = new ListElement{value, nullptr};
    int sizeOfCurrentList = ++currentList->size;
    if (sizeOfCurrentList == 1)
    {
        currentList->head = currentList->tail = newElement;
        return;
    }
    if (sizeOfCurrentList == 2)
    {
        newElement->next = currentList->tail;
        currentList->tail = newElement;
        return;
    }
    ListElement *currentElement = currentList->tail;
    ListElement *lastElement = currentList->tail->next;
    for (int i = 1; i < sizeOfCurrentList; ++i)
    {
        int currentValue = currentElement->value;
        int lastValue = lastElement->value;
        if (lastValue > newElement->value && newElement->value >= currentValue)
        {
            newElement->next = lastElement;
            currentElement->next = newElement;
            break;
        }
        currentElement = lastElement;
        lastElement = currentElement->next;
    }
}

void remove(List *currentList, int value)
{
    ListElement *currentElement = currentList->tail;
    int sizeOfCurrentList = currentList->size;
    for (int i = 0; i < sizeOfCurrentList - 2; ++i)
    {
        if (currentElement->next->value == value)
        {
            ListElement *removedElement = new ListElement(*currentElement->next);
            ListElement *preLastElement = currentElement->next->next;
            currentElement->next = preLastElement;
            --currentList->size;
            delete removedElement;
        }
        currentElement = currentElement->next;
    }
}

void output(List *currentList)
{
    int sizeOfCurrentList = currentList->size;
    ListElement *currentElement = currentList->tail->next;
    for (int i = 1; i < sizeOfCurrentList - 1; ++i)
    {
        cout << currentElement->value << " ";
        currentElement = currentElement->next;
    }
}


