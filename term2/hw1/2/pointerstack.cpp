#include <iostream>

#include "pointerstack.h"

void PointerStack::push(int value)
{
    StackElement *newElement = new StackElement(value);
    ++size;
    (tail == nullptr) ? tail = newElement : newElement->next = tail, tail = newElement;
}

int PointerStack::pop()
{
    if (size == 0)
        return notANumber;
    --size;
    int poppedElement = tail->value;
    StackElement *temp = tail->next;
    delete tail;
    tail = temp;
    return poppedElement;
}

void PointerStack::debugOutput()
{
    std::cout << "Debug output: ";
    StackElement *currentElement = tail;
    while (currentElement != nullptr)
    {
        std::cout << currentElement->value << " ";
        currentElement = currentElement->next;
    }
    std::cout << std::endl;
}

PointerStack::~PointerStack()
{
    while (tail != nullptr)
    {
        StackElement *temp = tail->next;
        delete tail;
        tail = temp;
    }
}
