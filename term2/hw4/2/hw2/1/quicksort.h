#pragma once

#include "sort.h"

class QuickSort : public Sort
{
public:
    int *sort(int *currentArray, const int &size);
private:
    /*!
     * \brief quickSort of array
     * \param left bound of sorting subarray
     * \param right bound of sorting subarray
     */
    void quickSort(int *array, const int &left, const int &right);
};
