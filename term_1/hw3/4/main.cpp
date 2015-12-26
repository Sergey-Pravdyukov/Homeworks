#include <iostream>
#include "infixToPostfix.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "Введите инфиксную запись выражения: ";
    const int maxSize = (int)1e4;
    int size = 0;
    char a[maxSize];
    cin >> a;
    while (a[size] != NULL)
    {
        ++size;
    }
    cout << "Значение арифметического выражения: " << haveInfixToPostfix(a, size);
    return 0;
}
