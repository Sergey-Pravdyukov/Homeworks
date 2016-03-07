#pragma once

/*!
 * \brief The Sort class to sort random array
 */

class Sort
{
public:
    virtual void sort(int *array) = 0;
protected:
    virtual ~Sort();
    void copy(int *arrayFrom, int *arrayTo);
    void debugOutput(int *array);

    const int maxSize = int(1e3);

    int *array = new int[maxSize];
    int size = 0;
};
