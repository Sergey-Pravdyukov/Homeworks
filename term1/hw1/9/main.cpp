#include <iostream>

using namespace std;

long long haveSlowSolve(long long a, int n)
{
    long long result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= a;
    }
    return result;
}

long long haveBinaryPower(long long a, int n)
{
    long long result = 1;
    while (n)
    {
        if (n % 2)
        {
            result *= a;
            --n;
        }
        else
        {
            a *= a;
            n /= 2;
        }
    }
    return result;
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "¬ведите основание степени: ";
    long long a = 0;
    cin >> a;
    cout << "¬ведите показатель степени: ";
    int n = 0;
    cin >> n;
    cout << a << " в степени " << n << " равно ";
    //cout << haveSlowSolve(a, n);
    cout << haveBinaryPower(a, n);
    return 0;
}
