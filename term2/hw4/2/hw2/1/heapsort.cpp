#include "heapsort.h"

void shiftDown(int *array, int i, int j)
{
    const int maxChildInit = 0;
    const bool doneInit = false;
    bool done = doneInit;
    int maxChild = maxChildInit;
    while ((i * 2 + 1 < j) && (!done))
    {
        if (i * 2 + 1 == j - 1)
            maxChild = i * 2 + 1;
        else if (array[i * 2 + 1] > array[i * 2 + 2])
            maxChild = i * 2 + 1;
        else
            maxChild = i * 2 + 2;

        if (array[i] < array[maxChild])
        {
            std::swap(array[i], array[maxChild]);
            i = maxChild;
        }
        else
            done = true;
    }
}

void HeapSort::heapSort(int *array, const int &size)
{
    const int begin = 0;
    for (int index = size / 2 - 1; index >= 0; index--)
        shiftDown(array, index, size);
    for (int index = size - 1; index >= 1; index--)
    {
        std::swap(array[begin], array[index]);
        shiftDown(array, begin, index);
    }
}

int *HeapSort::sort(int *array, const int &size)
{
    heapSort(array, size);
    return array;
}
