#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

void quicksort(int a[], int l, int r)
{
    int i = l;
    int j = r;
    int middle = a[(i + j) / 2];
    while (i < j)
    {
        while (a[i] < middle)
        {
            i++;
        }
        while (a[j] > middle)
        {
            j--;
        }
        if (i <= j)
        {
            int current = a[i];
            a[i] = a[j];
            a[j] = current;
            i++;
            j--;
        }
    }
    if (l < j)
    {
        quicksort(a, l, j);
    }
    if (i < r)
    {
        quicksort(a, i, r);
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n = 0;
    cout << "¬ведите размер массива: ";
    cin >> n;
    int a[n];
    cout << "¬ведите элементы массива: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    return 0;
}
