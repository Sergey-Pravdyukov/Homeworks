#pragma once

#include <QtTest/QtTest>
#include <QtCore/QObject>
#include <iostream>

#include "sharedpointer.h"

class TestSharedPointer : public QObject
{
    Q_OBJECT

public:
    explicit TestSharedPointer(QObject *parent = 0):
        QObject(parent)
    {}

private:
    const int correctValue = 26;

private slots:
    void testPointerCreate()
    {
        SharedPointer<int> pointer(new int(correctValue));
    }

    void testPointerCount()
    {
        const int correctCount = 1;
        SharedPointer<int> pointer(new int(correctValue));
        QCOMPARE(pointer.getCount(), correctCount);
    }

    void testObject()
    {
        SharedPointer<int> pointer(new int(correctValue));
        QCOMPARE(*pointer, correctValue);
    }

    void testNoneexistentPointerAssignment()
    {
        SharedPointer<int> pointer(new int(correctValue));
        SharedPointer<int> newPointer(new int(correctValue * correctValue));
        newPointer = pointer;
        const int correctCount = 2;
        QCOMPARE(*newPointer, *pointer);
        QCOMPARE((newPointer.getCount() == correctCount), (pointer.getCount() == correctCount));
    }

    void testPointerCopy()
    {
        SharedPointer<int> pointer(new int(correctValue));
        SharedPointer<int> newPointer(pointer);
        const int correctCount = 2;
        QCOMPARE(*newPointer, *pointer);
        QCOMPARE((newPointer.getCount() == correctCount), (pointer.getCount() == correctCount));
    }

    void testPointerDelete()
    {
        SharedPointer<int> pointer(new int(correctValue));
        SharedPointer<int> *newPointer = new SharedPointer<int>(pointer);
        delete newPointer;
        const int correctCount = 1;
        QCOMPARE(pointer.getCount(), correctCount);
    }

    void testExistentPointerAssignment()
    {
        SharedPointer<int> pointer(new int(correctValue));
        SharedPointer<int> tempPointer(new int(correctValue * correctValue));
        SharedPointer<int> newPointer = tempPointer;
        newPointer = pointer;
        const int correctTempPointerCount = 1;
        const int correctPointerCount = 2;
        QCOMPARE(tempPointer.getCount(), correctTempPointerCount);
        QCOMPARE(pointer.getCount(), correctPointerCount);
    }

};
