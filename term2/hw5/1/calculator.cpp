#include "calculator.h"

int Calculator::calculate(const int &firstOperand, const int &secondOperand, const QString &operation)
{
    char binaryOperation = operation.toLatin1().at(0);
    switch(binaryOperation)
    {
    case '+':
        return firstOperand + secondOperand;
    case '-':
        return firstOperand - secondOperand;
    case '*':
        return firstOperand * secondOperand;
    case '/':
        return firstOperand / secondOperand;
    }
}
