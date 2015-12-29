#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int x)
{
    if (x == 2)
    {
        return 1;
    }
    for (int i = 2; i <= trunc(sqrt(x)); ++i)
    {
        if (!(x % i))
        {
            return 0;
        }
    }
    return 1;
}

void isSlowSolve(int n)
{
    int primeNumbers = 0;
    int result[n];
    for (int i = 2; i <= n; ++i)
    {
        if (isPrime(i))
        {
            result[primeNumbers++] = i;
        }
    }
    for (int i = 0; i < primeNumbers; ++i)
    {
        cout << result[i] << " ";
    }
}

void isEratosthenesAlgo(int n)
{
    bool prime[n];
    int result[n];
    int primeNumbers = 0;
    for (int i = 0; i <= n; ++i)
    {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for (long long i = 2; i <= n; ++i)
    {
        if (prime[i])
        {
            result[primeNumbers++] = i;
            for (long long j = i * i; j <= n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    for (int i = 0; i < primeNumbers; ++i)
    {
        cout << result[i] << " ";
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "Введите число: ";
    int n = 0;
    cin >> n;
    cout << "Простые числа в диапазоне от 1 до " << n << ": ";
    //isSlowSolve(n);
    isEratosthenesAlgo(n);
    return 0;
}
