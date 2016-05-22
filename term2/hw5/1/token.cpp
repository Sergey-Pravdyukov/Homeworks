#include "token.h"

bool Token::isOperation(const QString &token)
{
    const int characterSize = 1;
    if (token.size() > characterSize)
        return false;
    char character = token.toLatin1().at(characterSize - 1);
    switch(character)
    {
    case '+':
        return true;
    case '-':
        return true;
    case '*':
        return true;
    case '/':
        return true;
    }
    return false;
}

bool Token::isBracket(const QChar &token)
{
    return (token == '(' || token == ')');
}

bool Token::isSpace(const QChar &token)
{
    return (token == ' ');
}

bool Token::isDigit(const QChar &token)
{
    return ((!isOperation(token)) && (!isBracket(token)) && (!isSpace(token)));
}
