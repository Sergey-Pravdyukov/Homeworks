#include <iostream>

#include "bubblesort.h"
#include "quicksort.h"
#include "heapsort.h"

using namespace std;

const int maxSize = int(1e3);

int main()
{
    cout << "Input size of array: ";
    int size = 0;
    cin >> size;
    cout << "Input array of " << size << " elements" << endl;
    int *array = new int[maxSize];
    for (int i = 0; i < size; ++i)
    {
        cin >> array[i];
    }

    Sort *bubbleSort = new BubbleSort(size);
    bubbleSort->sort(array);

    Sort *quickSort = new QuickSort(size);
    quickSort->sort(array);

    Sort *heapSort = new HeapSort(size);
    heapSort->sort(array);

    delete []array;
    return 0;
}
