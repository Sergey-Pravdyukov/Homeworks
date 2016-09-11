#pragma once

#include <QObject>
#include <QtTest/QtTest>

#include "stack.h"

class TestStack : public QObject
{
    Q_OBJECT

public:
    explicit TestStack(QObject *parent = 0):
        QObject(parent)
    {}

private:
    Stack *currentStack;

    const int size = 15;

private slots:
    void init()
    {
        currentStack = new Stack();
    }

    void cleanup()
    {
        delete currentStack;
    }

    void testEmptyStack()
    {
        QCOMPARE(currentStack->haveSize(), 0);
    }

    void testNonEmptyStack()
    {
        const QString token = "26";
        currentStack->push(token);
        QCOMPARE(currentStack->haveSize(), 1);
    }

    void testPushStackElement()
    {
        const QString pushedValue = "2893";
        currentStack->push(pushedValue);
        QCOMPARE(currentStack->top(), pushedValue);
    }

    void testPopStackElement()
    {
        const QString pushedValue = "26";
        currentStack->push(pushedValue);
        const QString poppedValue = currentStack->pop();
        QCOMPARE(pushedValue, poppedValue);
    }

    void testPushAndPopStackElements()
    {
        for (int i = 0; i < size; ++i)
            currentStack->push(QString::number(size - i));
        for (int i = 1; i <= size; ++i)
        {
            const QString poppedValue = currentStack->pop();
            QCOMPARE(poppedValue, QString::number(i));
        }
        QCOMPARE(currentStack->haveSize(), 0);
    }

    void testTop()
    {
        for (int i = 0; i < size; ++i)
            currentStack->push(QString::number(i));
        const QString correctTopElement = QString::number(size - 1);
        const QString topElement = currentStack->top();
        QCOMPARE(topElement, correctTopElement);
    }
};
