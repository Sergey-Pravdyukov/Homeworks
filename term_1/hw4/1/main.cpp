#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "¬ведите первую строку: ";
    const int alphabet = 26;
    const int maxSize = int(1e4);
    char firstString[maxSize];
    char secondString[maxSize];
    int delta[alphabet];
    cin >> firstString;
    cout << "¬ведите вторую строку: ";
    cin >> secondString;
    int i = 0;
    while (firstString[i] != NULL)
    {
        ++delta[firstString[i++] - 'a'];
    }
    i = 0;
    while (secondString[i] != NULL)
    {
        --delta[secondString[i++] - 'a'];
    }
    cout << "»з второй строки ";
    for (i = 0; i < alphabet; ++i)
    {
        if (delta[i])
        {
            cout << "нельз€ ";
            break;
        }
    }
    if (i == alphabet)
    {
        cout << "можно ";
    }
    cout << "получить первую перестановкой букв.";
    return 0;
}
