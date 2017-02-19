#include <iostream>
#include <cstdlib>

using namespace std;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void siftDown(int *numbers, int root, int bottom) {
    int done = 0;
    int maxChild = 0;
    while ((root * 2 <= bottom) && (!done))
    {
        int left = root * 2;
        int right = root * 2 + 1;
        if (left == bottom)
        {
            maxChild = left;
        }
        else if (numbers[left] > numbers[right])
        {
            maxChild = left;
        }
        else
        {
            maxChild = right;
        }
        if (numbers[root] < numbers[maxChild])
        {
            swap(numbers[root], numbers[maxChild]);
            root = maxChild;
        }
        else
        {
            done = 1;
        }
    }
}
void heapSort(int *numbers, int array_size) {
    for (int i = (array_size / 2) - 1; i >= 0; i--) {
        siftDown(numbers, i, array_size);
    }
    for (int i = array_size-1; i >= 1; i--) {
        swap(numbers[0], numbers[i]);
        siftDown(numbers, 0, i-1);
    }
}
int main() {
    setlocale(LC_CTYPE, "rus");
    const int maxSize = (int)1e4;
    cout << "Введите размер массива: ";
    int n = 0;
    cin >> n;
    cout << "Введите элементы массива: ";
    int a[maxSize];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    heapSort(a, n);
    cout << "Массив отсортирован: ";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
