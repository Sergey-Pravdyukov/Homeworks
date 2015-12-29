#include <iostream>
#include "PostfixToSum.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "Введите постфиксную запись выражения: ";
    const int maxSize = int(1e4);
    char a[maxSize];
    cin >> a;
    int size = 0;
    while (a[size] != NULL)
    {
        ++size;
    }
    cout << "Значение выражения в постфиксной записи: " << havePostfixToSum(a, size);
    return 0;
}
