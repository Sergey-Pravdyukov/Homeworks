#include <iostream>
#include <cstring>
#include "sortedList.h"

using namespace std;

bool isAMoreThanB(Member a, Member b)
{
    for (int i = 0; i < strlen(b.sirname); ++i)
    {
        if (a.sirname[i] < b.sirname[i])
        {
            return 0;
        }
    }
    return (strlen(a.sirname) > strlen(b.sirname));
}

bool isAEqualB(Member a, Member b)
{
    if (strlen(a.sirname) != strlen(b.sirname))
    {
        return 0;
    }
    for (int i = 0; i < strlen(a.sirname); ++i)
    {
        if (a.sirname[i] != b.sirname[i])
        {
            return 0;
        }
    }
    return 1;
}

void add(List *currentList, Member value)
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
        Member currentValue = currentElement->value;
        Member lastValue = lastElement->value;
        if (isAMoreThanB(lastValue, newElement->value) && isAMoreThanB(newElement->value, currentValue))
        {
            newElement->next = lastElement;
            currentElement->next = newElement;
            break;
        }
        currentElement = lastElement;
        lastElement = currentElement->next;
    }
}

ListElement remove(List *currentList, Member value)
{
    ListElement *currentElement = currentList->tail;
    int sizeOfCurrentList = currentList->size;
    for (int i = 0; i < sizeOfCurrentList - 2; ++i)
    {
        if (isAEqualB(currentElement->next->value, value))
        //if (currentElement->next->value == value)
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
        //cout << currentElement->value << " ";
        for (int j = 0; j < strlen(currentElement->value.sirname); ++j)
        {
            cout << currentElement->value.sirname[j];
        }
        currentElement = currentElement->next;
    }
}


