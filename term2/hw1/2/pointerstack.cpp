#include "pointerstack.h"
#include <iostream>

PointerStack::PointerStack()
{
    head = tail = nullptr;
    size = 0;
}

void PointerStack::push(int value)
{
    StackElement *newElement = new StackElement(value);
    ++size;
    if (size == 1)
    {
        head = tail = newElement;
        return;
    }
    newElement->next = tail;
    tail = newElement;
}

int PointerStack::pop()
{
    if (size == 0)
    {
        return notADigit;
    }
    --size;
    int poppedElement = tail->value;
    tail = tail->next;
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

void PointerStack::top()
{
    if (size == 0)
    {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }
    std::cout << tail->value << std::endl;
}
