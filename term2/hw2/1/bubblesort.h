#pragma once

#include "sort.h"

class BubbleSort : public Sort
{
public:
    BubbleSort(int currentSize);
    void sort(int *array);
private:
    void bubbleSort(int *array);
};
