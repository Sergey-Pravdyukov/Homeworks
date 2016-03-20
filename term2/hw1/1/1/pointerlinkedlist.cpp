#include "pointerlinkedlist.h"
#include <iostream>

PointerLinkedList::PointerLinkedList()
{
    head = tail = nullptr;
    size = 0;
}

void PointerLinkedList::add(int value)
{
    ListElement *newElement = new ListElement(value);
    ++size;
    if (size == 1)
    {
        head = tail = newElement;
        std::cout << value << " added" << std::endl;
        return;
    }
    if (size == 2)
    {
        head->next = newElement;
    }
    tail->next = newElement;
    tail = tail->next;
    std::cout << value << " added" << std::endl;
}

void PointerLinkedList::remove(int value)
{
    ListElement *currentElement = head;
    if (currentElement->value == value)
    {
        ListElement *newElement = new ListElement(head->value);
        newElement->next = head->next;
        delete head;
        head = newElement->next;
        std::cout << value << " founded" << std::endl;
        delete newElement;
        return;
    }
    ListElement *previousElement = currentElement;
    currentElement = currentElement->next;
    for (int i = 1; i < size; ++i)
    {
        if (currentElement->value == value)
        {
            previousElement->next = currentElement->next;
            std::cout << value << " founded" << std::endl;
            return;
        }
    }
    std::cout << value << " not founded" << std::endl;
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
