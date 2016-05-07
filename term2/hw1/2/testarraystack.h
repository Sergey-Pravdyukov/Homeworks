#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "arraystack.h"

class TestArrayStack : public QObject
{
    Q_OBJECT

public:
    explicit TestArrayStack(QObject *parent = 0):
        QObject(parent)
    {}
private:
    ArrayStack *currentStack;

    const int size = 15;
private slots:
    void init()
    {
        currentStack = new ArrayStack();
    }

    void clean()
    {
        delete currentStack;
    }

    void testEmptyArrayStack()
    {
        QCOMPARE(currentStack->lenght(), 0);
    }

    void testNonEmptyArrayStack()
    {
        const int pushedValue = 26;
        currentStack->push(pushedValue);
        QCOMPARE(currentStack->lenght(), 1);
    }

    void testPushElement()
    {
        const int pushedValue = 26;
        currentStack->push(pushedValue);
        QCOMPARE(currentStack->top(), pushedValue);
    }

    void testPopElement()
    {
        const int pushedValue = 26;
        currentStack->push(pushedValue);
        const int poppedValue = currentStack->pop();
        QCOMPARE(pushedValue, poppedValue);
    }

    void testPushAndPopElements()
    {
        for (int i = 0; i < size; ++i)
            currentStack->push(size - i);
        for (int i = 1; i <= size; ++i)
        {
            const int poppedValue = currentStack->pop();
            QCOMPARE(poppedValue, i);
        }
        QCOMPARE(currentStack->lenght(), 0);
    }
};
