#include "parser.h"

QVector<QString> Parser::parseExpressionToTokens(QString const &expression)
{
    QVector<QString> tokens;
    QString number = "";
    for (int i = 0; i < expression.size(); ++i)
    {
        if (!Token::isDigit(expression[i]))
        {
            if (!number.isEmpty())
            {
                tokens.push_back(number);
                number = "";
            }
            if (Token::isOperation(expression[i]))
                tokens.push_back(expression[i]);
        }
        else
            number += expression[i].toLatin1();
    }
    if (!number.isEmpty())
        tokens.push_back(number);
    return tokens;
}
