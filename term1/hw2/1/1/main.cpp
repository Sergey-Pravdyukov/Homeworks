#include <iostream>

using namespace std;

long long haveRecursionSolve(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    return haveRecursionSolve(n - 1) + haveRecursionSolve(n - 2);
}

long long haveIterationSolve(int n)
{
    long long result = 1;
    long long last = 1;
    for (int i = 3; i <= n; ++i)
    {
        long long current = result;
        result += last;
        last = current;
    }
    return result;
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "Введите число: ";
    int n = 0;
    cin >> n;
    //cout << haveRecursionSolve(n);
    cout << haveIterationSolve(n);
    cout << " - " << n << "-е число Фибоначчи";
    return 0;
}
