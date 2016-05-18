#include "quicksort.h"

void QuickSort::quickSort(int *array, const int &left, const int &right)
{
    int i = left;
    int j = right;
    const int middle = array[(i + j) / 2];
    while (i < j)
    {
        while (array[i] < middle)
            i++;
        while (array[j] > middle)
            j--;
        if (i <= j)
        {
            std::swap(array[i], array[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(array, left, j);
    if (i < right)
        quickSort(array, i, right);
}

int *QuickSort::sort(int *currentArray, const int &size)
{
    const int left = 0;
    const int right = size - 1;
    quickSort(currentArray, left, right);
    return currentArray;
}

