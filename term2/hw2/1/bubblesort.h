#pragma once

#include "sort.h"

class BubbleSort : public Sort
{
public:
    BubbleSort(int currentSize);
    void sort(int *array);
private:
    /*!
     * \brief bubbleSort of array
     */
    void bubbleSort(int *array);
};
