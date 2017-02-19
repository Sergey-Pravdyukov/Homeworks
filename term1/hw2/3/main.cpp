#include <iostream>
#include <ctime>
#include <cstdio>

using namespace std;

void haveDecompositionTerms(int a[], int step, int n, int currentSum, int lastTerm)
{
    if (currentSum == n && step != 1)
    {
        for (int i = 0; i < step - 1; ++i)
        {
            cout << a[i] << " + ";
        }
        cout << a[step - 1] << endl;
    }
    for (int currentTerm = 1; currentTerm <= lastTerm; ++currentTerm)
    {
        if (currentSum + currentTerm <= n)
        {
            a[step] = currentTerm;
            haveDecompositionTerms(a, step + 1, n, currentSum + currentTerm, currentTerm);
        }
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    const int maxSize = 50;
    int a[maxSize];
    cout << "Введите число: ";
    int n = 0;
    cin >> n;
    cout << "Все разложения числа " << n << " на слагаемые:" << endl;
    haveDecompositionTerms(a, 0, n, 0, n);
    return 0;
}
