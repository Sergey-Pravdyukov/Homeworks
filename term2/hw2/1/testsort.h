#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "sort.h"

class TestSort : public QObject
{
    Q_OBJECT

public:
    explicit TestSort(Sort *testSort, QObject *parent = 0):
        QObject(parent),
        testSort(testSort)
    {}

private:
    const int maxSize = 100;

    Sort *testSort;
    int *array;

private slots:
    void init()
    {
        array = new int[maxSize];
    }

    void cleanup()
    {
        delete[] array;
    }

    void testSortElement()
    {
        const int size = 1;
        const int value = 26;
        array[0] = value;
        array = testSort->sort(array, size);
        QCOMPARE(array[0], value);
    }

    void testSortedArray()
    {
        const int size = 20;
        for (int i = 0; i < size; ++i)
            array[i] = i;
        array = testSort->sort(array, size);
        for (int i = 1; i < size; ++i)
            QVERIFY(array[i - 1] <= array[i]);
    }

    void testReverseSortedArray()
    {
        const int size = 20;
        for (int i = 0; i < size; ++i)
            array[i] = size - i;
        array = testSort->sort(array, size);
        for (int i = 1; i < size; ++i)
            QVERIFY(array[i - 1] <= array[i]);
    }

    void testPseudoRandomArray()
    {
        const int size = 20;
        const int modulo = 29;
        const int currentValueInit = 13;
        const int delta = 7;
        int currentValue = currentValueInit;
        for (int i = 0; i < size; ++i)
        {
            array[i] = currentValue;
            currentValue = (currentValue + delta) % modulo;
        }
        array = testSort->sort(array, size);
        for (int i = 1; i < size; ++i)
            QVERIFY(array[i - 1] <= array[i]);
    }

    void testRandomArray()
    {
        srand(time(NULL));
        const int firstPrimeNumber = 29;
        const int secondPrimeNumber = 47;
        const int size = rand() % firstPrimeNumber;
        for (int i = 0; i < size; ++i)
            array[i] = rand() % secondPrimeNumber;
        array = testSort->sort(array, size);
        for (int i = 1; i < size; ++i)
            QVERIFY(array[i - 1] <= array[i]);
    }
};
