#include "list.h"

void List::add(const int &value)
{
    ListElement *newElement = new ListElement(value);
    ++sizeOfList;
    if (sizeOfList == 1)
    {
        headOfList = tailOfList = newElement;
        return;
    }
    if (sizeOfList == 2)
        headOfList->nextElement = newElement;
    tailOfList->nextElement = newElement;
    tailOfList = tailOfList->nextElement;
}

void List::debugOutput() const
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

void List::nextListInit(List *newList)
{
    this->nextList = newList;
}

List *List::next()
{
    return this->nextList;
}

int List::lenght() const
{
    return sizeOfList;
}

List::~List()
{
    while (headOfList != nullptr)
    {
        ListElement *nextListElement = headOfList->nextElement;
        delete headOfList;
        headOfList = nextListElement;
    }
}
