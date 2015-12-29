#include <iostream>

using namespace std;

void qsort(int a[], int l, int r)
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
        qsort(a, l, j);
    }
    if (i < r)
    {
        qsort(a, i, r);
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "Введите размер массива: ";
    int n = 0;
    cin >> n;
    cout << "Введите элементы массива: ";
    const int maxSize = 1e4;
    int a[maxSize];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    qsort(a, 0, n - 1);
    for (int i = n - 1; i >= 1; --i)
    {
        if (a[i] == a[i - 1])
        {
            cout << "Максимальный элемент массива, встречающийся более одного раза: " << a[i] << ".";
            return 0;
        }
    }
    cout << "В данном массиве нет элементов, встречающихся более одного раза.";
    return 0;
}
