#include <iostream>

using namespace std;

void swap(int a[], int l, int r)
{
    int middleOfSegment = (r - l) / 2;
    for (int i = l; i < l + middleOfSegment; ++i)
    {
        int current = a[i];
        a[i] = a[r - (i - l) - 1];
        a[r - (i - l) - 1] = current;
    }
}

void isSlowSolve(int a[], int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        int current = a[0];
        for (int j = 0; j < n + m - 1; ++j)
        {
            a[j] = a[j + 1];
        }
        a[n + m - 1] = current;
    }
}

void isFastSolve(int a[], int n, int m)
{
    swap(a, 0, n);
    swap(a, n, n + m);
    swap(a, 0, n + m);
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n = 0;
    int m = 0;
    cout << "¬ведите размер первого подмассива: ";
    cin >> n;
    cout << "¬ведите размер второго подмассива: ";
    cin >> m;
    cout << "¬ведите элементы первого массива массива: ";
    int a[n + m];
    for (int i = 0; i < n + m; ++i)
    {
        cin >> a[i];
    }
    //isSlowSolve(a, n, m);
    isFastSolve(a, n, m);
    for (int i = 0; i < n + m; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
