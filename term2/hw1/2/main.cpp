#include <iostream>
#include <QString>

#include "stack.h"
#include "arraystack.h"
#include "pointerstack.h"
#include "calculator.h"

using namespace std;

const int sizeOfExpression = 3;
//const QChar expression[sizeOfExpression] = {'3', '4', '+', '2', '-', '2', '-', '3', '*', '1', '-', '4', '/'}; // sizeOfExpression = 13;
//const QChar expression[sizeOfExpression] = {'3', '4', '5', '6', '7', '+', '+', '+', '+'}; // sizeOfExpression = 9;
const QChar expression[sizeOfExpression] = {'3', '0', '/'}; // sizeOfExpression = 3;



void calculate(Stack *currentStack)
{
    const int notADigit = -1;
    const int notANumber = INT_MIN;
    int result = notANumber;
    cout << "begin" << endl;
    for (int i = 0; i < sizeOfExpression; ++i)
    {
        const int token = expression[i].digitValue();
        if (token != notADigit)
            currentStack->push(token);
        else
        {
            const int firstOperand = currentStack->pop();
            const int secondOperand = currentStack->pop();
            Calculator *myCalculator = new Calculator();
            result = myCalculator->calculate(expression[i].toLatin1(), secondOperand, firstOperand);
            if (result == notANumber)
            {
                cout << "Error!" << endl;
                break;
            }
            cout << secondOperand << " "
                 << expression[i].toLatin1() << " "
                 << firstOperand << " = "
                 << result << endl;
            currentStack->push(result);
        }
    }
    if (result != notANumber)
        cout << "Result is " << currentStack->pop() << endl;
    cout << "end" << endl << endl;
}

int main()
{
    Stack *pointerStack = new PointerStack();
    cout << "Pointer stack: " << endl;
    calculate(pointerStack);

    Stack *arrayStack = new ArrayStack();
    cout << "Array stack: " << endl;
    calculate(arrayStack);
}
