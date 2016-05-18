#pragma once

#include <iostream>
#include <algorithm>

/*!
 * \brief The Sort class to sort random array
 */
class Sort
{
public:
    Sort(){}

    virtual ~Sort(){}

    /*!
     * \brief sort array by this sorting algorithm
     * \param array that sorting
     */
    virtual int* sort(int *currentArray, const int &size) = 0;

    /*!
     * \brief debugOutput of array from left to right
     * \param array that is output
     */
    void debugOutput(int *array, const int &size);
protected:
    const int maxSize = int(1e3);

    int *array = new int[maxSize];
    int size = 0;
};
