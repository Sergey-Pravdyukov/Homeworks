#pragma once

#include "sort.h"

class HeapSort : public Sort
{
public:
    HeapSort(int currentSize);
    void sort(int *array);
private:
    void heapSort(int *array);
};
