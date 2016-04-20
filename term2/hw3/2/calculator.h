#pragma once

#include <climits>

class Calculator
{
public:
    Calculator(){}
    slots static int calc(char operation, int firstOperand, int secondOperand);
private:
    const char notAOperation = '?';

    char operation = notAOperation;
    int firstOperand = INT_MAX;
    int secondOperand = INT_MAX;
};
