#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include <iostream>

#include "stack.h"
#include "pointerstack.h"

class TestPointerStack : public QObject
{
    Q_OBJECT

public:
    explicit TestPointerStack(QObject *parent = 0):
        QObject(parent)
    {}

private:
    PointerStack *currentStack;

    const int size = 15;

private slots:
    void init()
    {
        currentStack = new PointerStack();
    }

    void cleanup()
    {
        delete currentStack;
    }

    void testEmptyStack()
    {
        QCOMPARE(currentStack->lenght(), 0);
    }

    void testNonEmptyStack()
    {
        const int pushedValue = 26;
        currentStack->push(pushedValue);
        QCOMPARE(currentStack->lenght(), 1);
    }

    void testPushStackElement()
    {
        const int pushedValue = 2893;
        currentStack->push(pushedValue);
        QCOMPARE(currentStack->top(), pushedValue);
    }

    void testPopStackElement()
    {
        const int pushedValue = 26;
        currentStack->push(pushedValue);
        const int poppedValue = currentStack->pop();
        QCOMPARE(pushedValue, poppedValue);
    }

    void testPushAndPopStackElements()
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
