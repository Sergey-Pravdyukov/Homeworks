#include <iostream>

#include "sort.h"

void Sort::debugOutput(const int *array)
{
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void Sort::copy(const int *arrayFrom, int *arrayTo)
{
    for (int i = 0; i < size; ++i)
    {
        arrayTo[i] = arrayFrom[i];
    }
}

Sort::~Sort()
{
    delete []array;
}

