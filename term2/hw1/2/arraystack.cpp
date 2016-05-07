#include <iostream>

#include "arraystack.h"

void ArrayStack::push(int value)
{
    currentStack[size++] = value;
}

int ArrayStack::pop()
{
    return (size == 0) ? notANumber : currentStack[--size];
}

void ArrayStack::top()
{
    (size == 0) ? std::cout << "Stack is empty!" << std::endl
                : std::cout << currentStack[size - 1] << std::endl;
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
