#include "token.h"

bool Token::isNumber(const QString &token)
{
    const int notADigit = -1;
    for (int i = 0; i < token.size(); ++i)
    {
        if (token[i].digitValue() == notADigit && token[i] != '.')
            return false;
    }
    return true;
}

int Token::operationPriority(const QString &token)
{
    const int sizeOfOperation = 1;
    if (token.size() != sizeOfOperation)
        return notAnOperation;
    const char character = token.toLatin1().at(sizeOfOperation - 1);
    switch (character)
    {
    case '*':
        return highPriorityOperation;
    case '/':
        return highPriorityOperation;
    case '+':
        return lowPriorityOperation;
    case '-':
        return lowPriorityOperation;
    default:
        return notAnOperation;
    }
}

bool Token::isBracket(const QString &token)
{
    const int sizeOfBracket = 1;
    if (token.size() != sizeOfBracket)
        return false;
    const QChar character = token[sizeOfBracket - 1];
    return (character == '(' || character == ')');
}
