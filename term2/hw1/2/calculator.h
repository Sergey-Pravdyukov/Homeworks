#pragma once

#include <climits>

class Calculator
{
public:
    Calculator(){}
    int calculate(char operation, int firstOperand, int secondOperand);
private:
    const char notAOperation = '?';

    char operation = notAOperation;
    int firstOperand = INT_MAX;
    int secondOperand = INT_MAX;
};
