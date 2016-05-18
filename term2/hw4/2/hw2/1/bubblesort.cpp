#include "bubblesort.h"

void BubbleSort::bubbleSort(int *array, const int &size)
{
    for (int i = 1; i < size; ++i)
        for (int j = i - 1; j >= 0; --j)
            if (array[j] > array[j + 1])
                std::swap(array[j], array[j + 1]);
}

int* BubbleSort::sort(int *array, const int &size)
{
    bubbleSort(array, size);
    return array;
}
