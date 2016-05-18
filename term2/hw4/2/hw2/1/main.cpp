#include <iostream>

#include "bubblesort.h"
#include "quicksort.h"
#include "heapsort.h"
#include "testsort.h"

using namespace std;

int *copyArray(int *array, const int size)
{
    int *newArray = new int[size];
    for (int i = 0; i < size; ++i)
        newArray[i] = array[i];
    return newArray;
}

int main()
{
    cout << "Input size of array: ";
    const int maxSize = int(1e3);
    const int sizeInit = 0;
    int size = sizeInit;
    cin >> size;
    cout << "Input array of " << size << " elements" << endl;
    int *array = new int[maxSize];
    for (int i = 0; i < size; ++i)
        cin >> array[i];

    Sort *bubbleSort = new BubbleSort();
    int *sortableArray = copyArray(array, size);
    int *sortedArray = bubbleSort->sort(sortableArray, size);
    bubbleSort->debugOutput(sortedArray, size);
    TestSort *testSort = new TestSort(bubbleSort);
    QTest::qExec(testSort);
    cout << endl;

    Sort *quickSort = new QuickSort();
    sortableArray = copyArray(array, size);
    sortedArray = quickSort->sort(sortableArray, size);
    quickSort->debugOutput(sortedArray, size);
    testSort = new TestSort(quickSort);
    QTest::qExec(testSort);
    cout << endl;

    Sort *heapSort = new HeapSort();
    sortableArray = copyArray(array, size);
    sortedArray = heapSort->sort(sortableArray, size);
    heapSort->debugOutput(sortedArray, size);
    testSort = new TestSort(heapSort);
    QTest::qExec(testSort);
    cout << endl;

    delete []array;
    return 0;
}
