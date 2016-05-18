#include "parser.h"
#include "token.h"

QVector<QString> Parser::haveParseDisplayTextToExpressions(QString const &displayText)
{
    QVector<QString> expression;
    QString number = "";
    for (int i = 0; i < displayText.size(); ++i)
    {
        if ((displayText[i] == '-') && ((i == 0) || (displayText[i - 1] == '(')))
            expression.push_back("0");
        if ((Token::operationPriority(displayText[i]) != notAnOperation) || (Token::isBracket(displayText[i])))
        {
            if (!number.isEmpty())
            {
                expression.push_back(number);
                number = "";
            }
            expression.push_back(displayText[i]);
        }
        else if (isdigit(displayText[i].toLatin1()) || displayText[i].toLatin1() == '.')
            number += displayText[i].toLatin1();
    }
    if (!number.isEmpty())
        expression.push_back(number);
    return expression;
}
