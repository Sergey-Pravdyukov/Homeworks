#include <iostream>

using namespace std;

long long haveIterationSolve(int n)
{
    long long result = 1;
    for (long long i = 2; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

long long haveRecursionSolve(long long n)
{
    if (n < 2)
    {
        return 1;
    }
    return haveRecursionSolve(n - 1) * n;
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "Введите число: ";
    int n = 0;
    cin >> n;
    cout << "Факториал числа " << n << " равен ";
    //cout << haveIterationSolve(n);
    cout << haveRecursionSolve(n);
    return 0;
}
