#pragma once

#include "sort.h"

class HeapSort : public Sort
{
public:
    HeapSort(int currentSize);
    void sort(int *array);
private:
    /*!
     * \brief heapSort of array
     */
    void heapSort(int *array);
};
