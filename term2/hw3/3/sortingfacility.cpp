#include "sortingfacility.h"
#include "stack.h"

#include <QString>
#include <QVector>
#include <QChar>
#include <cstring>

bool isNumber(const QString &token)
{
    const int notADigit = -1;
    for (int i = 0; i < token.size(); ++i)
        if (token[i].digitValue() == notADigit)
            return false;
    return true;
}

bool isHighPriorityOperation(const QString &token)
{
    const int sizeOfOperation = 1;
    if (token.size() != sizeOfOperation)
        return false;
    const char character = token.toLatin1().at(sizeOfOperation - 1);
    switch (character)
    {
    case '*':
        return true;
    case '/':
        return true;
    default:
        return false;
    }
}

bool isOperation(const QString &token)
{
    const int sizeOfOperation = 1;
    if (token.size() != sizeOfOperation)
        return false;
    const char character = token.toLatin1().at(sizeOfOperation - 1);
    if (isHighPriorityOperation(token))
        return true;
    switch (character)
    {
    case '+':
        return true;
    case '-':
        return true;
    default:
        return false;
    }
}

bool isBracket(const QString &token)
{
    const int sizeOfBracket = 1;
    if (token.size() != sizeOfBracket)
        return false;
    const QChar character = token[sizeOfBracket - 1];
    return (character == '(' || character == ')');
}

QString SortingFacility::havePostfixToSum(QVector<QString> &postfixData)
{
    Stack *stackForNumbers = new Stack();
    for (int i = 0; i < postfixData.size(); ++i)
    {
        const QString token = postfixData[i];
        if (isNumber(token))
            stackForNumbers->push(token);
        if (isOperation(token))
        {
            const int firstNumber = stackForNumbers->pop().toInt();
            const int secondNumber = stackForNumbers->pop().toInt();
            int result = 0;
            switch (int(token.toLatin1().at(0)))
            {
            case '+':
            {
                result = secondNumber + firstNumber;
                break;
            }
            case '-':
            {
                result = secondNumber - firstNumber;
                break;
            }
            case '*':
            {
                result = secondNumber * firstNumber;
                break;
            }
            case '/':
            {
                result = secondNumber / firstNumber;
                break;
            }
            }
            stackForNumbers->push(QString::number(result));
        }
    }
    return (stackForNumbers->top());
}

QVector<QString> SortingFacility::haveInfixToPostfix(const QVector<QString> &expression)
{
    Stack *stackForOperations = new Stack();
    QVector<QString> infixData;
    for (int i = 0; i < expression.size(); ++i)
    {
        const QString token = expression[i];
        if (isNumber(token))
            infixData.push_back(token);
        if (isOperation(token))
        {
            if (!isHighPriorityOperation(token))
                while(stackForOperations->size != 0 && isHighPriorityOperation(stackForOperations->top()))
                    infixData.push_back(stackForOperations->pop());
            stackForOperations->push(token);
        }
        if (isBracket(token))
        {
            if (token == "(")
                stackForOperations->push(token);
            else
                while (stackForOperations->size)
                {
                    const QString head = stackForOperations->pop();
                    if (head == "(")
                        break;
                    infixData.push_back(head);
                }
        }
    }
    while (stackForOperations->size)
        infixData.push_back(stackForOperations->pop());
    return infixData;
}

