#include <iostream>

#include "arraystack.h"

void ArrayStack::updateMaxSizeOfStack()
{
    maxSize *= 2;
    int *tempStack = new int[maxSize];
    for (int i = 0; i < size; ++i)
        tempStack[i] = currentStack[i];
    delete currentStack;
    currentStack = tempStack;
}

void ArrayStack::push(int value)
{
    if (size + 1 > maxSize)
        updateMaxSizeOfStack();
    currentStack[size++] = value;
}

int ArrayStack::pop()
{
    return (size == 0) ? notANumber : currentStack[--size];
}

void ArrayStack::debugOutput()
{
    for (int i = 0; i < size; ++i)
        std::cout << currentStack[i] << " ";
    std::cout << std::endl;
}

int ArrayStack::lenght()
{
    return size;
}

int ArrayStack::top()
{
    return currentStack[0];
}

ArrayStack::~ArrayStack()
{
    delete []currentStack;
}
