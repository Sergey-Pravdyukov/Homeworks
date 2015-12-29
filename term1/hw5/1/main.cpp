#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    freopen("input.txt", "r", stdin);
    cout << "Результат: ";
    const int sizeOfAlphabet = 26;
    char currentChar;
    int alphabet[sizeOfAlphabet];
    for (int i = 0; i < sizeOfAlphabet; ++i)
    {
        alphabet[i] = 0;
    }
    while ((currentChar = getc(stdin)) != EOF)
    {
        if (currentChar == ' ' || currentChar == '\n')
        {
            (currentChar == ' ') ? cout << " " : cout << endl;
            for (int i = 0; i < sizeOfAlphabet; ++i)
            {
                alphabet[i] = 0;
            }
        }
        else
        {
            if (alphabet[int(currentChar - 'a')] == 0)
            {
                cout << currentChar;
            }
            alphabet[int(currentChar - 'a')] = 1;
        }
    }
    return 0;
}
