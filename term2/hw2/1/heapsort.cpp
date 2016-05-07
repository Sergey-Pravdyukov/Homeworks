#include <algorithm>

#include "heapsort.h"
#include "sort.h"

HeapSort::HeapSort(int currentSize)
{
    size = currentSize;
}

void siftDown(int *array, int root, const int bottom) {
    int done = 0;
    int maxChild = 0;
    while ((root * 2 <= bottom) && (!done))
    {
        const int left = root * 2;
        const int right = root * 2 + 1;
        if (left == bottom)
        {
            maxChild = left;
        }
        else if (array[left] > array[right])
        {
            maxChild = left;
        }
        else
        {
            maxChild = right;
        }
        if (array[root] < array[maxChild])
        {
            std::swap(array[root], array[maxChild]);
            root = maxChild;
        }
        else
        {
            done = 1;
        }
    }
}

void HeapSort::heapSort(int *array) {
    for (int i = (size / 2) - 1; i >= 0; i--)
        siftDown(array, i, size);
    for (int i = size - 1; i >= 1; i--)
    {
        std::swap(array[0], array[i]);
        siftDown(array, 0, i - 1);
    }
}

void HeapSort::sort(int *array)
{
    int *sortableArray = new int[maxSize];
    copy(array, sortableArray);
    heapSort(sortableArray);
    debugOutput(sortableArray);
}

