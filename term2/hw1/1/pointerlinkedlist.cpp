#include <iostream>

#include "pointerlinkedlist.h"

void PointerLinkedList::add(int value)
{
    ListElement *newElement = new ListElement(value);
    ++size;
    if (size == 1)
    {
        head = tail = newElement;
        return;
    }
    if (size == 2)
        head->next = newElement;
    tail->next = newElement;
    tail = tail->next;
}

int PointerLinkedList::remove(int value)
{
    ListElement *currentElement = head;
    if (currentElement->value == value)
    {
        int removedValue = value;
        ListElement *newHead = head->next;
        delete head;
        head = newHead;
        --size;
        return removedValue;
    }

    ListElement *previousElement = currentElement;
    currentElement = currentElement->next;
    for (int i = 1; i < size; ++i)
        if (currentElement->value == value)
        {
            int removedValue = value;
            previousElement->next = currentElement->next;
            delete currentElement;
            --size;
            return removedValue;
        }
    return notANumber;
}

void PointerLinkedList::debugOutput()
{
    if (head == nullptr)
    {
        std::cout << "Pointer linked list is empty" << std::endl;
        return;
    }
    std::cout << "Debug output: ";
    ListElement *currentElement = head;
    while (currentElement != nullptr)
    {
        std::cout << currentElement->value << " ";
        currentElement = currentElement->next;
    }
    std::cout << std::endl;
}

int PointerLinkedList::lenght()
{
    return size;
}

PointerLinkedList::~PointerLinkedList()
{
    while (head != nullptr)
    {
        ListElement *temp = head->next;
        delete head;
        head = temp;
    }
}
