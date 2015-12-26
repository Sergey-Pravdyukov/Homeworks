#include <iostream>

using namespace std;

int haveSolveForPositiveDivider(int a, int b)
{
    int count = 0;
    if (a > 0)
    {
        while (a >= b)
        {
            a -= b;
            ++count;
        }
    }
    else
    {
        while (a < 0)
        {
            a += b;
            --count;
        }
    }
    return count;
}

int haveSolveForNegativeDivider(int a, int b) {
    int count = 0;
    if (a > 0)
    {
        while (a >= -b)
        {
            a += b;
            count--;
        }
    }
    else
    {
        while (a < 0)
        {
            a -= b;
            count++;
        }
    }
    return count;
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "Введите a и b: ";
    int a = 0;
    int b = 0;
    cin >> a >> b;
    if (b == 0)
    {
        cout << "Делить на ноль нельзя" << endl;
        return 0;
    }
    int count = 0;
    cout << "Неполное частное от деления a на b равно ";
    if (b > 0)
    {
        cout << haveSolveForPositiveDivider(a, b);
    }
    else
    {
        cout << haveSolveForNegativeDivider(a, b);
    }
    return 0;
}
