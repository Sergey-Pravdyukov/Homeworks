#include <algorithm>

#include "bubblesort.h"
#include "sort.h"

BubbleSort::BubbleSort(int currentSize)
{
    size = currentSize;
}

void BubbleSort::bubbleSort(int *array)
{
    for (int i = 1; i < size; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

void BubbleSort::sort(int *array)
{
    int *sortableArray = new int[maxSize];
    copy(array, sortableArray);
    bubbleSort(sortableArray);
    debugOutput(sortableArray);
}

