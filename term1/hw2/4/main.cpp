#include <iostream>

using namespace std;

struct Pair
{
    int numerator;
    int denominator;
    double value;
};

int haveGCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return haveGCD(b, a % b);
}

void swap(Pair &a, Pair &b)
{
    Pair c = a;
    a = b;
    b = c;
}

void qsort(Pair a[], int l, int r)
{
    const double epsilon = 1e-12;
    int i = l;
    int j = r;
    double middle = a[(i + j) / 2].value;
    while (i < j)
    {
        while (middle - a[i].value > epsilon)
        {
            i++;
        }
        while (a[j].value - middle > epsilon)
        {
            j--;
        }
        if (i <= j)
        {
            swap(a[i], a[j]);
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
    cout << "Введите число :";
    int n = 0;
    cin >> n;
    const int maxSize = (int)1e4;
    Pair a[maxSize];
    int size = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            if (haveGCD(i, j) == 1)
            {
                a[size].numerator = j;
                a[size].denominator = i;
                a[size++].value = (double)j / double(i);
            }
        }
    }
    qsort(a, 0, size - 1);
    cout << "все простые несократимые дроби, заключенные между 0 и 1, знаменатели которых не превышают " << n << ":" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << a[i].numerator << "/" << a[i].denominator << endl;
    }
    return 0;
}
