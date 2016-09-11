#include "calculator.h"

double Calculator::calculate(const double &firstOperand, const double &secondOperand, const QString &operation)
{
    char* currentOperation = operation.toLatin1().data();
    switch (currentOperation[0])
    {
    case '+':
        return firstOperand + secondOperand;
    case '-':
        return firstOperand - secondOperand;
    case '*':
        return firstOperand * secondOperand;
    case '/':
        return (secondOperand == 0.0) ? error : firstOperand / secondOperand;
    }
}

