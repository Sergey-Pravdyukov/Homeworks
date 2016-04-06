#include "parser.h"

#include <QString>

bool isOperation(QChar character)
{
    switch (character.toLatin1())
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

bool isBracket(QChar character)
{
    return (character == '(' || character == ')');
}

QVector<QString> Parser::haveParse(QString const &displayText)
{
    QVector<QString> expression;
    QString number = "";
    for (int i = 0; i < displayText.size(); ++i)
    {
        if (isOperation(displayText[i]) || isBracket(displayText[i]))
        {
            if (!number.isEmpty())
            {
                expression.push_back(number);
                number = "";
            }
            expression.push_back(displayText[i]);
        }
        else if (isdigit(displayText[i].toLatin1()))
            number += displayText[i].toLatin1();
    }
    if (!number.isEmpty())
        expression.push_back(number);
    return expression;
}
