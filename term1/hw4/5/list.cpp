#include <iostream>
#include "list.h"

using namespace std;

void output(List *currentList)
{
    ListElement *currentElement = currentList->head;
    while (currentElement->next != nullptr)
    {
        cout << currentElement->value << " ";
        currentElement = currentElement->next;
    }
    cout << currentElement->value << endl;
}

void add(List *currentList, int value)
{
    ListElement *currentElement = new ListElement{value, nullptr};
    ++currentList->size;
    if (currentList->size == 1)
    {
        currentList->head = currentElement;
        currentList->tail = currentElement;
        return;
    }
    currentList->tail->next = currentElement;
    currentList->tail = currentElement;
}

int sizeOfList(List *currentList)
{
    return currentList->size;
}

void remove(List *currentList, int k)
{
    ListElement *preCurrentIndex = currentList->tail;
    while (sizeOfList(currentList)!= 1)
    {
        ListElement *currentIndex = (preCurrentIndex->next == nullptr) ? currentList->head : preCurrentIndex->next;
        for (int i = 0; i < k - 1; ++i)
        {
            currentIndex = (currentIndex->next == nullptr) ? currentList->head : currentIndex->next;
            preCurrentIndex = (preCurrentIndex->next == nullptr) ? currentList->head : preCurrentIndex->next;
        }
        if (currentIndex == currentList->head)
        {
            currentList->head = currentList->head->next;
        }
        else if (currentIndex == currentList->tail)
        {
            preCurrentIndex->next = nullptr;
            currentList->tail = preCurrentIndex;
        }
        else
        {
            preCurrentIndex->next = currentIndex->next;
        }
        --currentList->size;
    }
}

int topOfList(List *currentList)
{
    return currentList->head->value;
}
