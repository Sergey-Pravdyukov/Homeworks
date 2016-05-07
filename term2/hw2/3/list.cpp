#include <iostream>

#include "list.h"

void List::add(int value)
{
    ListElement *newElement = new ListElement(value);
    ++sizeOfList;
    if (sizeOfList == 1)
    {
        headOfList = tailOfList = newElement;
        return;
    }
    if (sizeOfList == 2)
    {
        headOfList->nextElement = newElement;
    }
    tailOfList->nextElement = newElement;
    tailOfList = tailOfList->nextElement;
}

void List::debugOutput()
{
    if (headOfList == nullptr)
    {
        std::cout << std::endl << "List is empty" << std::endl;
        return;
    }
    std::cout << std::endl << "Size of list: " << sizeOfList << std::endl << std::endl;
    ListElement *currentElement = headOfList;
    while (currentElement != nullptr)
    {
        std::cout << currentElement->value << " ";
        currentElement = currentElement->nextElement;
    }
    std::cout << std::endl;
}
