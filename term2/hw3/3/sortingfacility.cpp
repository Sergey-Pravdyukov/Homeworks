#include "sortingfacility.h"
#include "stack.h"
#include "token.h"

QString SortingFacility::havePostfixToSum(QVector<QString> &postfixData)
{
    Stack *stackForNumbers = new Stack();
    for (int i = 0; i < postfixData.size(); ++i)
    {
        const QString token = postfixData[i];
        if (Token::isNumber(token))
            stackForNumbers->push(token);
        if (Token::isOperation(token))
        {
            const double firstNumber = stackForNumbers->pop().toDouble();
            const double secondNumber = stackForNumbers->pop().toDouble();
            double result = 0;
            switch (token.toLatin1().at(0))
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
        if (Token::isNumber(token))
            infixData.push_back(token);
        if (Token::isOperation(token))
        {
            if (!Token::isHighPriorityOperation(token))
                while(stackForOperations->size != 0 && Token::isHighPriorityOperation(stackForOperations->top()))
                    infixData.push_back(stackForOperations->pop());
            stackForOperations->push(token);
        }
        if (Token::isBracket(token))
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
