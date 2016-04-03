#include <cctype>

#include "calculator.h"
#include "stack.h"

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

QString havePostfixToSum(QString infixData)
{
    Stack *stackForDigits = new Stack();
    for (int i = 0; i < infixData.size(); ++i)
    {
        char character = QString(infixData).at(i).toLatin1();
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

QString haveInfixToPostfix(QString expression)
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

int haveSum(QString *expression)
{
    QString newExpression = haveInfixToPostfix(*expression);
    return havePostfixToSum(newExpression).toInt();
}

int Calculator::calc(QString *expression)
{
    return haveSum(expression);
}
