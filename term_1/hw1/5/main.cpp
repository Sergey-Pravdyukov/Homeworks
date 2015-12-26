#include <iostream>

using namespace std;

bool haveSolveForOneTypeOfBrackets(char string[])
{
    int currentSize = 0;
    int i = 0;
    while (string[i] != NULL)
    {
        if (string[i] == '(')
        {
            ++currentSize;
        }
        else
        {
            if (currentSize == 0)
            {
                return 0;
            }
            else
            {
                --currentSize;
            }
        }
        ++i;
    }
    return (currentSize == 0);
}

bool haveSolveForThreeTypesOfBrackets(char string[])
{
    const int maxSize = (int)1e4;
    int stack[maxSize];
    const int typesOfBrackets = 3;
    char openBrackets[typesOfBrackets]= {'(', '[', '{'};
    char closeBrackets[typesOfBrackets] = {')', ']', '}'};
    int sizeOfStack = 0;
    int i = 0;
    while (string[i] != NULL)
    {
        for (int j = 0; j < typesOfBrackets; ++j)
        {
            if (string[i] == openBrackets[j])
            {
                stack[sizeOfStack++] = j;
            }
            if (string[i] == closeBrackets[j])
            {
                if (sizeOfStack == 0 || stack[--sizeOfStack] != j)
                {
                    return 0;
                }
            }
        }
        ++i;
    }
    return (sizeOfStack == 0);
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "¬ведите скобочную последовательность: ";
    const int maxSize = (int)1e4;
    char string[maxSize];
    cin >> string;
    cout << "ƒанна€ скобочна€ последовательность €вл€етс€ ";
    /*if (!haveSolveForOneTypeOfBrackets(string))
    {
        cout << "не";
    }*/
    if (!haveSolveForThreeTypesOfBrackets(string))
    {
        cout << "не";
    }
    cout << "правильной.";
    return 0;
}
