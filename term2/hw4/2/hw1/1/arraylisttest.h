#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include <cstdlib>
#include <iostream>

#include "list.h"
#include "arraylinkedlist.h"

class ArrayListTest : public QObject
{
    Q_OBJECT

public:
    explicit ArrayListTest(QObject *parent = 0):
        QObject(parent)
    {}

private:
    ArrayLinkedList *list;

    const int modulo = 26;
    const int size = 15;
    const int randomConstant = 23;
    const int valueInit = 0;
    int currentValue = valueInit;
    int counter = valueInit;

private slots:
    void init()
    {
        list = new ArrayLinkedList();
    }

    void clean()
    {
        delete list;
    }

    void testEmptyList()
    {
        QCOMPARE(list->lenght(), 0);
    }

    void testSizeOfList()
    {
        for (int i = 0; i < size; ++i)
        {
            currentValue = (currentValue * randomConstant + i) % modulo;
            list->add(currentValue);
        }
        QCOMPARE(list->lenght(), size);
    }

    void testAddElement()
    {
        list->add(7238);
        QCOMPARE(list->array[0], 7238);
    }

    void testAddElements()
    {
        currentValue = valueInit;
        for (int i = 0; i < size; ++i)
        {
            currentValue = (currentValue * randomConstant + i) % modulo;
            list->add(currentValue);
        }
        currentValue = valueInit;
        counter = valueInit;
        for (int i = 0; i < size; ++i)
        {
            currentValue = (currentValue * randomConstant + i) % modulo;
            ++counter;
            QCOMPARE(list->array[i], currentValue);
        }
        QCOMPARE(list->lenght(), counter);
    }

    void testRemoveElement()
    {
        const int value = 26;
        list->add(value);
        QCOMPARE(list->remove(value), value);
    }

    void testRemoveElements()
    {
        currentValue = valueInit;
        for (int i = 0; i < size; ++i)
        {
            currentValue = (currentValue * randomConstant + i) % modulo;
            list->add(currentValue);
        }
        currentValue = valueInit;
        for (int i = 0; i < size; ++i)
        {
            currentValue = (currentValue * randomConstant + i) % modulo;
            int removedValue = list->remove(currentValue);
            QCOMPARE(removedValue, currentValue);
        }
    }
};
