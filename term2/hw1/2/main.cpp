#include <iostream>

#include "stack.h"
#include "arraystack.h"
#include "pointerstack.h"
#include "calculator.h"

using namespace std;


const int sizeOfExpression = 9;
//const char expression[sizeOfExpression] = {'3', '4', '+', '2', '-', '2', '-', '3', '*', '1', '-', '4', '/'}; // sizeOfExpression = 13;
//const char expression[sizeOfExpression] = {'3', '4', '5', '6', '7', '+', '+', '+', '+', '+'}; // sizeOfExpression = 10;
const char expression[sizeOfExpression] = {'3', '4', '5', '6', '7', '+', '+', '+', '+'}; // sizeOfExpression = 9;

int haveConvertFromCharToInt(char digit)
{
    return digit - char('0');
}

int main()
{
    Stack *pointerStack = new PointerStack();
    cout << "Pointer stack" << endl << "begin" << endl;
    bool isEmpty = false;
    for (int i = 0; i < sizeOfExpression; ++i)
    {
        if (isdigit(expression[i]))
        {
            pointerStack->push(haveConvertFromCharToInt(expression[i]));
        }
        else
        {
            int firstOperand = pointerStack->pop();
            int secondOperand = pointerStack->pop();
            if (firstOperand == pointerStack->notANumber || secondOperand == pointerStack->notANumber)
            {
                isEmpty = true;
                cout << "Stack is empty!" << endl;
                break;
            }
            Calculator *myCalculator = new Calculator();
            cout << secondOperand << " " << expression[i] << " " << firstOperand << " = " <<
                    myCalculator->calculate(expression[i], secondOperand, firstOperand) << endl;
            pointerStack->push(myCalculator->calculate(expression[i], secondOperand, firstOperand));
        }
    }
    if (!isEmpty)
    {
        cout << "Result is " << pointerStack->pop() << endl;
    }
    cout << "end" << endl << endl;

    Stack *arrayStack = new ArrayStack();
    cout << "Array stack" << endl << "begin" << endl;
    isEmpty = false;
    for (int i = 0; i < sizeOfExpression; ++i)
    {
        if (isdigit(expression[i]))
        {
            arrayStack->push(haveConvertFromCharToInt(expression[i]));
        }
        else
        {
            int firstOperand = arrayStack->pop();
            int secondOperand = arrayStack->pop();
            if (firstOperand == arrayStack->notANumber || secondOperand == arrayStack->notANumber)
            {
                isEmpty = true;
                cout << "Stack is empty!" << endl;
                break;
            }
            Calculator *myCalculator = new Calculator();
            cout << secondOperand << " " << expression[i] << " " << firstOperand << " = " <<
                    myCalculator->calculate(expression[i], secondOperand, firstOperand) << endl;
            arrayStack->push(myCalculator->calculate(expression[i], secondOperand, firstOperand));
        }
    }
    if (!isEmpty)
    {
        cout << "Result is " << arrayStack->pop() << endl;
    }
    cout << "end" << endl;
}