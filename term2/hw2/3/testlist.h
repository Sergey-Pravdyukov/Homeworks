#pragma once

#include <QObject>
#include <QtTest/QtTest>

#include "list.h"

class TestList : public QObject
{
    Q_OBJECT

public:
    explicit TestList(QObject *parent = 0):
        QObject(parent)
    {}

private:
    const static int maxSize = 1000;
    const static int sizeInit = 0;

    int size = sizeInit;
    List *currentList;
    int *array;
private slots:
    void init()
    {
        currentList = new List();
        array = nullptr;
    }

    void cleanup()
    {
        delete currentList;
        delete[] array;
    }

    void testSizeOfEmptyList()
    {
        const int correctListSize = 0;
        QCOMPARE(currentList->lenght(), correctListSize);
    }

    void testSizeOfNonEmptyList()
    {
        const int value = 26;
        currentList->add(value);
        const int correctListSize = 1;
        QCOMPARE(currentList->lenght(), correctListSize);
    }

    void testAddElement()
    {
        const int value = 26;
        currentList->add(value);
        array = currentList->fromListToArray();
        QCOMPARE(array[0], value);
    }

    void testAddElements()
    {
        int size = 13;
        for (int i = 0; i < size; ++i)
            currentList->add(size - i);
        array = currentList->fromListToArray();
        for (int i = 0; i < size; ++i)
            QCOMPARE(array[i], size - i);
    }
};
