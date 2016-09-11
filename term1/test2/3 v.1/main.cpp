#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    freopen("f.txt", "r", stdin);
    freopen("g.txt", "w", stdout);
    int a = 0;
    int b = 0;
    cin >> a >> b;
    int n = 0;
    cin >> n;
    int x = 0;
    int sizeLess = 0;
    int sizeIn = 0;
    int sizeMore = 0;
    const int maxSize = 1e4;
    int lessThanA[maxSize];
    int inAToB[maxSize];
    int moreThanB[maxSize];
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (x < a)
        {
            lessThanA[sizeLess++] = x;
        }
        if (a <= x && x <= b)
        {
            inAToB[sizeIn++] = x;
        }
        if (b < x)
        {
            moreThanB[sizeMore++] = x;
        }
    }

    cout << "ƒействующие границы a и b: " << a << " " << b << endl;
    cout << "ƒействующий размер массива: " << n << endl;
    cout << "Ёлементы меньшиие " << a << ": ";
    for (int i = 0; i < sizeLess; ++i)
    {
        cout << lessThanA[i] << " ";
    }
    cout << endl << "Ёлементы лежащие в отрезке [" << a << ", " << b << "]: ";
    for (int i = 0; i < sizeIn; ++i)
    {
        cout << inAToB[i] << " ";
    }
    cout << endl << "Ёлементы большие " << b << ": ";
    for (int i = 0; i < sizeMore; ++i)
    {
        cout << moreThanB[i] << " ";
    }
    return 0;
}
