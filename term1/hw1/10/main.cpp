#include <iostream>

using namespace std;

int haveStringSize(char string[])
{
    int result = 0;
    while (string[result] != NULL)
    {
        ++result;
    }
    return result;
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "������� ������: ";
    const int maxSize = (int)1e4;
    char string[maxSize];
    cin >> string;
    int stringSize = haveStringSize(string);
    cout << "������ " << string << " ";
    for (int i = 0; i < stringSize / 2; ++i)
    {
        if (string[i] != string[stringSize - i - 1])
        {
            cout << " �� ";
            break;
        }
    }
    cout << "�������� �����������.";
    return 0;
}
