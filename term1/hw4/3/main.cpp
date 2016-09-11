#include <iostream>
#include <cstring>

using namespace std;

void quicksort(char a[], int l, int r)
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
            char current = a[i];
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
    cout << "Введите число: ";
    const int maxSize = int(1e4);
    char a[maxSize];
    cin >> a;
    quicksort(a, 0, strlen(a) - 1);
    cout << "Наименьшее число, образованное перестановкой цифр данного числа: ";
    int index = 1;
    for (int i = 0; i < strlen(a); ++i)
    {
        if (a[i] != '0') {
            cout << a[i];
            index = i;
            break;
        }
    }
    for (int i = 0; i < strlen(a); ++i)
    {
        if (i != index) {
            cout << a[i];
        }
    }
    return 0;
}
