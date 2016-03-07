#pragma once

#include "sort.h"

class QuickSort : public Sort
{
public:
    QuickSort(int currentSize);
    void sort(int *array);
private:
    void quickSort(int *array, int left, int right);
};
