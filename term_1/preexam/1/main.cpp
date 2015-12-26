#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "Введите строку в двоичной системе счисления: ";
    const int maxSize = 64;
    char binary[maxSize];
    cin >> binary;
    long long power = 1;
    long long currentValue = 0;
    char result[maxSize];
    char reversedString[maxSize];
    int sizeOfString = 0;
    for (int i = strlen(binary) - 1; i >= 0; --i)
    {
        currentValue += power * (binary[i] == '1');
        power *= 2;
    }
    while (currentValue != 0)
    {
        reversedString[sizeOfString++] = char(currentValue % 10 + '0');
        currentValue /= 10;
    }
    for (int i = sizeOfString - 1; i >= 0; --i)
    {
        result[sizeOfString - 1 - i] = reversedString[i];
    }

    cout << "Число в десятичной системе счисления: ";
    if (sizeOfString == 0)
    {
        cout << "0";
        return 0;
    }
    for (int i = 0; i < sizeOfString; ++i)
    {
        cout << result[i];
    }
    return 0;
}
