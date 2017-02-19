#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include <cstdlib>
#include <iostream>

#include "list.h"
#include "pointerlinkedlist.h"

class PointerListTest : public QObject
{
    Q_OBJECT

public:
    explicit PointerListTest(QObject *parent = 0):
        QObject(parent)
    {}

private:
    PointerLinkedList *list;

    const int modulo = 26;
    const int size = 15;
    const int randomConstant = 23;
    const int valueInit = 0;
    int currentValue = valueInit;
    int counter = valueInit;

private slots:
    void init()
    {
        list = new PointerLinkedList();
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
        QCOMPARE(list->head->value, 7238);
    }

    void testAddElements()
    {
        currentValue = valueInit;
        for (int i = 0; i < size; ++i)
        {
            currentValue = (currentValue * randomConstant + i) % modulo;
            list->add(currentValue);
        }
        PointerLinkedList::ListElement *currentElement = list->head;
        currentValue = valueInit;
        counter = valueInit;
        while (currentElement != nullptr)
        {
            currentValue = (currentValue * randomConstant + counter) % modulo;
            ++counter;
            QCOMPARE(currentElement->value, currentValue);
            currentElement = currentElement->next;
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

        for (int i = 0; i < size; ++i)
        {
            currentValue = (currentValue * randomConstant + i) % modulo;
            list->add(currentValue);
        }
        currentValue = valueInit;
        while (!list->lenght())
        {
            currentValue = (currentValue * randomConstant + counter) % modulo;
            ++counter;
            PointerLinkedList::ListElement *removedElement = new PointerLinkedList::ListElement(list->remove(currentValue));
            QCOMPARE(removedElement->value, currentValue);
            delete removedElement;
        }
    }
};
