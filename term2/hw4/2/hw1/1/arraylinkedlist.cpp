#include "arraylinkedlist.h"
#include <iostream>

void ArrayLinkedList::add(int value)
{
    if (size < maxSize)
        array[size++] = value;
}

int ArrayLinkedList::remove(int value)
{
    int index = notANumber;
    for (int i = 0; i < size; ++i)
        if (array[i] == value)
        {
            index = i;
            break;
        }
    if (index == notANumber)
        return notANumber;
    int removedValue = value;
    for (int i = index + 1; i < size; ++i)
        array[i - 1] = array[i];
    --size;
    return removedValue;
}

void ArrayLinkedList::debugOutput()
{
    if (size == 0)
    {
        std::cout << "Array linked list is empty" << std::endl;
        return;
    }
    std::cout << "Debug output: ";
    for (int i = 0; i < size; ++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int ArrayLinkedList::lenght()
{
    return size;
}

ArrayLinkedList::~ArrayLinkedList()
{
    delete []array;
}
