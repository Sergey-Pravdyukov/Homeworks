#include "arraylinkedlist.h"
#include <iostream>

ArrayLinkedList::ArrayLinkedList()
{
    size = 0;
}

void ArrayLinkedList::add(int value)
{
    if (size < maxSize)
    {
        array[size++] = value;
    }
    std::cout << value << " added" << std::endl;
}

void ArrayLinkedList::remove(int value)
{
    const int init = -1;
    int index = init;
    for (int i = 0; i < size; ++i)
    {
        if (array[i] == value)
        {
            index = i;
            break;
        }
    }
    if (index == init)
    {
        std::cout << value << " not founded" << std::endl;
        return;
    }
    for (int i = index + 1; i < size; ++i)
    {
        array[i - 1] = array[i];
    }
    --size;
    std::cout << value << " founded" << std::endl;
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
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

ArrayLinkedList::~ArrayLinkedList()
{
    delete []array;
}
