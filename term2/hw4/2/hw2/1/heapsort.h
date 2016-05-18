#pragma once

#include "sort.h"

class HeapSort : public Sort
{
public:
    int *sort(int *array, const int &size);
private:
    /*!
     * \brief heapSort of array
     */
    void heapSort(int *array, const int &size);
};
