#include <iostream>
#include <QString>

#include "stack.h"
#include "arraystack.h"
#include "pointerstack.h"
#include "calculator.h"
#include "testpointerstack.h"
#include "testarraystack.h"
#include "testcalculator.h"

using namespace std;

const int sizeOfExpression = 9;
//const QChar expression[sizeOfExpression] = {'3', '4', '+', '2', '-', '2', '-', '3', '*', '1', '-', '4', '/'}; // sizeOfExpression = 13;
const QChar expression[sizeOfExpression] = {'3', '4', '5', '6', '7', '+', '+', '+', '+'}; // sizeOfExpression = 9;
//const QChar expression[sizeOfExpression] = {'3', '0', '/'}; // sizeOfExpression = 3;

void calculate(Stack *currentStack)
{
    const int notADigit = -1;
    const int notANumber = INT_MIN;
    int result = notANumber;
    cout << "begin" << endl;
    for (int i = 0; i < sizeOfExpression; ++i)
    {
        const int token = expression[i].digitValue();
        if (token == notADigit)
        {
            const int secondOperand = currentStack->pop();
            const int firstOperand = currentStack->pop();
            Calculator *myCalculator = new Calculator();
            result = myCalculator->calculate(expression[i].toLatin1(), firstOperand, secondOperand);
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
        else
            currentStack->push(token);
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
    TestPointerStack testPointerStack;
    QTest::qExec(&testPointerStack);
    cout << endl;

    Stack *arrayStack = new ArrayStack();
    cout << "Array stack: " << endl;
    calculate(arrayStack);
    TestArrayStack testArrayStack;
    QTest::qExec(&testArrayStack);

    cout << endl;
    TestCalculator testCalculator;
    QTest::qExec(&testCalculator);
}
