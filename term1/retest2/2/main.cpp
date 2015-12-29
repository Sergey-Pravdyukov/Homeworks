#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    freopen("input.txt", "r", stdin);
    char currentChar = '?';
    bool isEmptyString = 1;
    int numberOfNonemptyStrings = 0;
    while((currentChar = getc(stdin)) != EOF)
    {
        if (currentChar == '\n')
        {
            numberOfNonemptyStrings += (1 - isEmptyString);
            isEmptyString = 1;
        }
        else
        {
            if (currentChar == ' ' || currentChar == '\t')
            {
                continue;
            }
            isEmptyString = 0;
        }
    }
    cout << "Количество непутсых строк во входном файле: " << numberOfNonemptyStrings << endl;
    return 0;
}
