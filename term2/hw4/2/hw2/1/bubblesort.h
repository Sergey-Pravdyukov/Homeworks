#pragma once

#include "sort.h"

class BubbleSort : public Sort
{
public:
    int* sort(int *array, const int &size);
private:
    /*!
     * \brief bubbleSort of array
     */
    void bubbleSort(int *array, const int &size);
};
