#include "arraylinkedlist.h"

void ArrayLinkedList::updateMaxSize(int &maxSize)
{
    int *newElements = new int[maxSize * 2];
    for (int i = 0; i < size; ++i)
        newElements[i] = elements[i];
    elements = newElements;
    maxSize *= 2;
}

void ArrayLinkedList::add(const int &value)
{
    if (size == maxSize)
        updateMaxSize(maxSize);
    elements[size++] = value;
}

int ArrayLinkedList::remove(const int &value) throw(RemoveNonexistedElementException)
{
    const int index = find(value);
    if (index == notFoundIndex)
        throw RemoveNonexistedElementException();
    int removedValue = elements[index];
    for (int i = index + 1; i < size; ++i)
        elements[i - 1] = elements[i];
    --size;
    return removedValue;
}

int ArrayLinkedList::find(const int &value)
{
    for (int i = 0; i < size; ++i)
        if (elements[i] == value)
            return i;
    return notFoundIndex;
}

void ArrayLinkedList::debugOutput()
{
    std::cout << "Debug output: ";
    for (int i = 0; i < size; ++i)
        std::cout << elements[i] << " ";
    std::cout << std::endl;
}

int ArrayLinkedList::getLenght()
{
    return size;
}

ArrayLinkedList::~ArrayLinkedList()
{
    delete []elements;
}
