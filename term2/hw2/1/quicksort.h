#pragma once

#include "sort.h"

class QuickSort : public Sort
{
public:
    QuickSort(int currentSize);
    void sort(int *array);
private:
    /*!
     * \brief quickSort of array
     * \param left bound of sorting subarray
     * \param right bound of sorting subarray
     */
    void quickSort(int *array, const int left, const int right);
};
