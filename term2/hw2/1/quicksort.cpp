#include <algorithm>

#include "quicksort.h"
#include "sort.h"

QuickSort::QuickSort(int currentSize)
{
    size = currentSize;
}

void QuickSort::quickSort(int *array, int left, int right)
{
    int i = left;
    int j = right;
    int middle = array[(i + j) / 2];
    while (i < j)
    {
        while (array[i] < middle)
        {
            i++;
        }
        while (array[j] > middle)
        {
            j--;
        }
        if (i <= j)
        {
            std::swap(array[i], array[j]);
            i++;
            j--;
        }
    }
    if (left < j)
    {
        quickSort(array, left, j);
    }
    if (i < right)
    {
        quickSort(array, i, right);
    }
}

void QuickSort::sort(int *array)
{
    int *sortableArray = new int[maxSize];
    int left = 0;
    int right = size - 1;
    copy(array, sortableArray);
    quickSort(sortableArray, left, right);
    debugOutput(sortableArray);
}

