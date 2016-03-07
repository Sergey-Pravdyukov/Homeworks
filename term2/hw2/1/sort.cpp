#include <iostream>

#include "sort.h"

/*!
 * \brief Output sorted array
 * \param array sorted array
 */

void Sort::debugOutput(int *array)
{
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

/*!
 * \brief copying inputting array to sortable array
 * \param arrayFrom inputting array
 * \param arrayTo sortable array
 */

void Sort::copy(int *arrayFrom, int *arrayTo)
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

