#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "������� ������ ������: ";
    const int alphabet = 26;
    const int maxSize = int(1e4);
    char firstString[maxSize];
    char secondString[maxSize];
    int delta[alphabet];
    cin >> firstString;
    cout << "������� ������ ������: ";
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
    cout << "�� ������ ������ ";
    for (i = 0; i < alphabet; ++i)
    {
        if (delta[i])
        {
            cout << "������ ";
            break;
        }
    }
    if (i == alphabet)
    {
        cout << "����� ";
    }
    cout << "�������� ������ ������������� ����.";
    return 0;
}
