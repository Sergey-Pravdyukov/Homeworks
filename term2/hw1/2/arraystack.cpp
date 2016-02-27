#include "arraystack.h"
#include <iostream>

ArrayStack::ArrayStack()
{
    size = 0;
}

void ArrayStack::push(int value)
{
    currentStack[size++] = value;
}

int ArrayStack::pop()
{
    if (size == 0)
    {
        return notADigit;
    }
    int poppedElement = currentStack[--size];
    return poppedElement;
}

void ArrayStack::top()
{
    if (size == 0)
    {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }
    std::cout << currentStack[size - 1] << std::endl;
}

void ArrayStack::debugOutput()
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << currentStack[i] << " ";
    }
    std::cout << std::endl;
}

ArrayStack::~ArrayStack()
{
    delete []currentStack;
}
