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
        return firstOperand / secondOperand;
    default:
        return 0;
    }
}
