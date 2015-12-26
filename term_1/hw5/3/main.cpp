#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    freopen("1.txt", "r", stdin);
    cout << "Все однострочные комментарии С++ (вида // комментарий): " << endl;
    char preCurrentChar = char(254);
    char currentChar = char(254);
    bool isEndOfOperation = false;
    bool isSingleLineComment = false;
    bool isMultilineComment = false;
    bool isOpenBrackets = false;
    bool isLetter = false;
    bool isString = false;
    while ((currentChar = getc(stdin)) != EOF)
    {
        if (preCurrentChar == char(254))
        {
            preCurrentChar = currentChar;
        }
        else
        {
            if (!isMultilineComment && isSingleLineComment && !isString)
            {
                cout << currentChar;
            }
            if ((('a' <= currentChar && currentChar <= 'z') || ('A' <= currentChar && currentChar <= 'Z'))
                && !isSingleLineComment)
            {
                isLetter = true;
            }
            if (currentChar == '"')
            {
                isString = true;
            }
            if (preCurrentChar == '/' && currentChar == '/' && !isMultilineComment && !isSingleLineComment)
            {
                isSingleLineComment = true;
            }
            if (preCurrentChar == '/' && currentChar == '*')
            {
                isMultilineComment = true;
            }
            else if (preCurrentChar == '*' && currentChar == '/')
            {
                isMultilineComment = false;
            }
            if (preCurrentChar == ' ' && currentChar == '(' && !isOpenBrackets)
            {
                isOpenBrackets = true;
            }
            else if (currentChar == ')' && isOpenBrackets)
            {
                isOpenBrackets = false;
            }
            if (currentChar == '\n')
            {
                isEndOfOperation = false;
                isOpenBrackets = false;
                isSingleLineComment = false;
                isLetter = false;
                isString = false;
                preCurrentChar = char(254);
            }
            preCurrentChar = currentChar;
        }
    }
    return 0;
}

