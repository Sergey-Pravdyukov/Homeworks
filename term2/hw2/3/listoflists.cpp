#include <iostream>

#include "listoflists.h"
#include "list.h"

void ListOfLists::add(List addedList)
{
    List *newList = new List();
    List::ListElement *addedElement = addedList.headOfList;
    while (addedElement != nullptr)
    {
        newList->add(addedElement->value);
        addedElement = addedElement->nextElement;
    }
    ++sizeOfListOfLists;
    if (sizeOfListOfLists == 1)
    {
        headOfListOfLists = tailOfListOfLists = newList;
        return;
    }
    if (sizeOfListOfLists == 2)
    {
        if (headOfListOfLists->sizeOfList <= newList->sizeOfList)
        {
            headOfListOfLists->nextList = tailOfListOfLists->nextList = newList;
            tailOfListOfLists = tailOfListOfLists->nextList;
        }
        else
        {
            headOfListOfLists = newList;
            headOfListOfLists->nextList = tailOfListOfLists;
        }
        return;
    }
    List *currentList = headOfListOfLists;
    List *precurrentList = nullptr;
    while (currentList != nullptr)
    {
        if (newList->sizeOfList <= currentList->sizeOfList)
        {
            newList->nextList = currentList;
            (precurrentList == nullptr) ? headOfListOfLists = newList
                                        : precurrentList->nextList = newList;
            return;
        }
        else
        {
            precurrentList = currentList;
            currentList = currentList->nextList;
        }
    }
    tailOfListOfLists->nextList = newList;
    tailOfListOfLists = tailOfListOfLists->nextList;
}

void ListOfLists::debugOutput()
{
    if (sizeOfListOfLists == 0)
    {
        std::cout << std::endl << "List of lists is empty" << std::endl;
        return;
    }
    List *currentList = headOfListOfLists;
    while (currentList != nullptr)
    {
        currentList->debugOutput();
        currentList = currentList->nextList;
    }
}

ListOfLists::~ListOfLists()
{
    while (headOfListOfLists != nullptr)
    {
        List *tempList = headOfListOfLists->nextList;
        while (tempList->headOfList != nullptr)
        {
            List::ListElement *tempElement = tempList->headOfList->nextElement;
            delete tempList->headOfList;
            tempList->headOfList = tempElement;
        }
        delete headOfListOfLists;
        headOfListOfLists = tempList;
    }
}
