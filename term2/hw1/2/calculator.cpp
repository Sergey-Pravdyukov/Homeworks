#include "calculator.h"

int Calculator::calculate(char operation, int firstOperand, int secondOperand)
{
    switch (operation)
    {
    case '+':
    {
        return firstOperand + secondOperand;
    }
    case '-':
    {
        return firstOperand - secondOperand;
    }
    case '*':
    {
        return firstOperand * secondOperand;
    }
    case '/':
    {
        if (secondOperand != 0)
            return firstOperand / secondOperand;
        return notANumber;
    }
    default:
        return notANumber;
    }
}
