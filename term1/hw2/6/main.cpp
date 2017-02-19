#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void output(int a[])
{
    const int size = 4;
    for (int i = 0; i < size; ++i)
    {
        cout << a[i];
    }
    cout << endl;
}

bool equal(int a[], int current[])
{
    const int size = 4;
    for (int i = 0; i < size; ++i)
    {
        if (a[i] != current[i])
        {
            return 0;
        }
    }
    return 1;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int isCows(int a[], int current[])
{
    const int digits = 10;
    const int size = 4;
    int digitsA[digits];
    int digitsCurrent[digits];
    for (int i = 0; i < digits; ++i)
    {
        digitsA[i] = digitsCurrent[i] = 0;
    }
    for (int i = 0; i < size; ++i)
    {
        if (a[i] != current[i])
        {
            ++digitsA[a[i]];
            ++digitsCurrent[current[i]];
        }
    }
    int result = 0;
    for (int i = 0; i < digits; ++i)
    {
        if (digitsA[i] && digitsCurrent[i])
        {
            result += min(digitsA[i], digitsCurrent[i]);
        }
    }
    return result;
}

int isBulls(int a[], int current[])
{
    const int size = 4;
    int result = 0;
    for (int i = 0; i < size; ++i)
    {
        result += (a[i] == current[i]);
    }
    return result;
}

void reverse(int current[])
{
    const int size = 4;
    int help[size];
    for (int i = 0; i < size; ++i)
    {
        help[i] = current[size - i - 1];
    }
    for (int i = 0; i < size; ++i)
    {
        current[i] = help[i];
    }
}

void haveSeparate(int currentNumber, int current[])
{
    const int digits = 10;
    int i = 0;
    while (currentNumber != 0)
    {
        current[i++] = currentNumber % digits;
        currentNumber /= digits;
    }
    reverse(current);
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    srand(time(NULL));
    const int size = 4;
    int a[size];
    int current[size];
    a[0] = rand() % 9 + 1;
    for (int i = 1; i < size; ++i)
    {
        a[i] = rand() % 10;
    }
    //output(a);
    for (int i = 0; i < size; ++i)
    {
        current[i] = 0;
    }
    int currentNumber = 0;
    int stepCounter = 0;
    while (!equal(a, current))
    {
        ++stepCounter;
        cout << "Введите число: ";
        cin >> currentNumber;
        haveSeparate(currentNumber, current);
        cout << "Количество коров: ";
        cout << isCows(a, current) << endl;
        cout << "Количество быков: ";
        cout << isBulls(a, current) << endl;
    }
    cout << "Поздравляю!!! Вы угадали число за " << stepCounter << " ходов!!!";
    return 0;
}
