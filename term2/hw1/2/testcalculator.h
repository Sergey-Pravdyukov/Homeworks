#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "calculator.h"

class TestCalculator : public QObject
{
    Q_OBJECT

public:
    explicit TestCalculator(QObject *parent = 0):
        QObject(parent)
    {}
private:
    Calculator *calculator;

private slots:
    void init()
    {
        calculator = new Calculator();
    }

    void cleanup()
    {
        delete calculator;
    }

    void testSum()
    {
        const char operation = '+';
        const int firstOperand = 26;
        const int secondOperand = 271;
        QCOMPARE(calculator->calculate(operation, firstOperand, secondOperand), 297);
    }

    void testDifference()
    {
        const char operation = '-';
        const int firstOperand = 26;
        const int secondOperand = 271;
        QCOMPARE(calculator->calculate(operation, firstOperand, secondOperand), -245);
    }

    void testMultiplication()
    {
        const char operation = '*';
        const int firstOperand = 26;
        const int secondOperand = 271;
        QCOMPARE(calculator->calculate(operation, firstOperand, secondOperand), 7046);
    }

    void testIntegerDivision()
    {
        const int operation = '/';
        const int firstOperand = 271;
        const int secondOperand = 26;
        QCOMPARE(calculator->calculate(operation, firstOperand, secondOperand), 10);
    }

    void testDivisionByNull()
    {
        const int operation = '/';
        const int firstOperand = 26;
        const int secondOperand = 0;
        const int result = Calculator::notANumber;
        QCOMPARE(calculator->calculate(operation, firstOperand, secondOperand), result);
    }

    void testWithIncorrectOperation()
    {
        const int operation = Calculator::notAnOperation;
        const int firstOperand = 26;
        const int secondOperand = 271;
        const int result = Calculator::notANumber;
        QCOMPARE(calculator->calculate(operation, firstOperand, secondOperand), result);
    }
};
