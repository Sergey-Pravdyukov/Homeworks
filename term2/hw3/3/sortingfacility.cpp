#include "sortingfacility.h"
#include "stack.h"

#include <QString>

bool isOperation(char character)
{
    switch (character)
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

bool isBracket(char character)
{
    return (character == '(' || character == ')');
}

QString SortingFacility::havePostfixToSum(QString postfixData)
{
    Stack *stackForDigits = new Stack();
    for (int i = 0; i < postfixData.size(); ++i)
    {
        char character = QString(postfixData).at(i).toLatin1();
        if (isdigit(character))
            stackForDigits->push(character);
        if (isOperation(character))
        {
            int firstDigit = stackForDigits->pop().digitValue();
            int secondDigit = stackForDigits->pop().digitValue();
            int result = 0;
            switch (character)
            {
            case '+':
            {
                result = secondDigit + firstDigit;
                break;
            }
            case '-':
            {
                result = secondDigit - firstDigit;
                break;
            }
            case '*':
            {
                result = secondDigit * firstDigit;
                break;
            }
            case '/':
            {
                result = secondDigit / firstDigit;
                break;
            }
            }
            stackForDigits->push(QString::number(result).at(0));
        }
    }
    return (stackForDigits->top());
}

QString SortingFacility::haveInfixToPostfix(QString expression)
{
    Stack *stackForOperations = new Stack();
    QString *infixData = new QString();
    for (int i = 0; i < expression.size(); ++i)
    {
        char character = QString(expression).at(i).toLatin1();
        if (isdigit(character) || character == '0')
            infixData->push_back(character);
        if (isOperation(character))
            stackForOperations->push(character);
        if (isBracket(character))
        {
            if (character == '(')
                stackForOperations->push(character);
            else
                while (stackForOperations->size)
                {
                    QChar head = stackForOperations->top();
                    stackForOperations->pop();
                    if (head == '(')
                        break;
                    else
                        infixData->push_back(head);
                }
        }
    }
    while (stackForOperations->size)
        infixData->push_back(stackForOperations->pop());
    return *infixData;
}
