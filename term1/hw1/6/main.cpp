#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    const int maxSize = (int)1e4;
    char firstString[maxSize];
    char substring[maxSize];
    cout << "Введите первую строку: ";
    cin >> firstString;
    cout << "Введите вторую строку: ";
    cin >> substring;
    int answer = 0;
    for (int i = 0; i < strlen(firstString) - strlen(substring) + 1; ++i)
    {
        bool findSubstring = 1;
        for (int j = 0; j < strlen(substring); ++j)
        {
            if (firstString[i + j] != substring[j])
            {
                findSubstring = 0;
            }
        }
        answer += (int)findSubstring;
    }
    cout << "Количество вхождений второй строки в первую как подстроки равно " << answer;
    return 0;
}
