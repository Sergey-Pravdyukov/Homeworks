#include "sort.h"

void Sort::debugOutput(int *array, const int &size)
{
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}
