#include <iostream>
#include <QString>

#include "stack.h"
#include "arraystack.h"
#include "pointerstack.h"
#include "calculator.h"

using namespace std;

const int sizeOfExpression = 9;
//const QChar expression[sizeOfExpression] = {'3', '4', '+', '2', '-', '2', '-', '3', '*', '1', '-', '4', '/'}; // sizeOfExpression = 13;
//const QChar expression[sizeOfExpression] = {'3', '4', '5', '6', '7', '+', '+', '+', '+', '+'}; // sizeOfExpression = 10;
const QChar expression[sizeOfExpression] = {'3', '4', '5', '6', '7', '+', '+', '+', '+'}; // sizeOfExpression = 9;

const int notADigit = -1;

int main()
{
    const int pair = 2;
    bool isEmpty = false;
    Stack *pointerStack = new PointerStack();
    cout << "Pointer stack" << endl << "begin" << endl;
    for (int i = 0; i < sizeOfExpression; ++i)
    {
        const int token = expression[i].digitValue();
        if (token != notADigit)
            pointerStack->push(token);
        else
        {
            if (pointerStack->size < pair)
            {
                isEmpty = true;
                cout << "Stack is empty!" << endl;
                break;
            }
            const int firstOperand = pointerStack->pop();
            const int secondOperand = pointerStack->pop();
            Calculator *myCalculator = new Calculator();
            const int result = myCalculator->calculate(expression[i].toLatin1(), secondOperand, firstOperand);
            cout << secondOperand << " "
                 << expression[i].toLatin1() << " "
                 << firstOperand << " = "
                 << result << endl;
            pointerStack->push(result);
        }
    }
    if (!isEmpty)
        cout << "Result is " << pointerStack->pop() << endl;
    cout << "end" << endl << endl;

    Stack *arrayStack = new ArrayStack();
    cout << "Array stack" << endl << "begin" << endl;
    isEmpty = false;
    for (int i = 0; i < sizeOfExpression; ++i)
    {
        const int token = expression[i].digitValue();
        if (token != notADigit)
            arrayStack->push(token);
        else
        {
            if (arrayStack->size < pair)
            {
                isEmpty = true;
                cout << "Stack is empty!" << endl;
                break;
            }
            const int firstOperand = arrayStack->pop();
            const int secondOperand = arrayStack->pop();
            Calculator *myCalculator = new Calculator();
            const int result = myCalculator->calculate(expression[i].toLatin1(), secondOperand, firstOperand);
            cout << secondOperand << " "
                 << expression[i].toLatin1() << " "
                 << firstOperand << " = "
                 << result << endl;
            arrayStack->push(result);
        }
    }
    if (!isEmpty)
        cout << "Result is " << arrayStack->pop() << endl;
    cout << "end" << endl;
}
