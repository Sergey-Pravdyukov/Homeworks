#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include <cstdlib>
#include <ctime>

#include "uniquelist.h"

class TestUniqueList : public QObject
{
    Q_OBJECT

public:
    explicit TestUniqueList(QObject *parent = 0):
        QObject(parent)
    {}

private:
    UniqueList *list;

    const int maxNumber = 26;
    int size = 15;
    const int valueInit = 0;
    const int counterInit = 0;
    int currentValue = valueInit;
    int counter = counterInit;

private slots:
    void init()
    {
        list = new UniqueList();
    }

    void clean()
    {
        delete list;
    }

    void testEmptyList()
    {
        QCOMPARE(list->getLenght(), 0);
    }

    void testAddElement()
    {
        list->add(7238);
        QCOMPARE(list->elements[0], 7238);
    }

    void testAddElements()
    {
        srand(time(NULL));
        int elements[size];
        currentValue = valueInit;
        const int elementsNumber = size;
        for (int i = 0; i < elementsNumber; ++i)
        {
            currentValue = rand() % maxNumber;
            if (list->find(currentValue) != list->notFoundIndex)
            {
                QVERIFY_EXCEPTION_THROWN(list->add(currentValue), UniqueList::ElementAlreadyExistsException);
                --size;
                continue;
            }
            elements[counter++] = currentValue;
            list->add(currentValue);
        }
        currentValue = valueInit;
        counter = counterInit;
        for (int i = 0; i < size; ++i)
            QCOMPARE(list->elements[i], elements[i]);
    }

    void testSizeOfList()
    {
        srand(time(NULL));
        const int numberOfElements = size;
        for (int i = 0; i < numberOfElements; ++i)
        {
            currentValue = rand() % maxNumber;
            if (list->find(currentValue) != list->notFoundIndex)
            {
                QVERIFY_EXCEPTION_THROWN(list->add(currentValue), UniqueList::ElementAlreadyExistsException);
                --size;
                continue;
            }
            list->add(currentValue);
        }
        QCOMPARE(list->getLenght(), size);
    }

    void testRemoveElement()
    {
        const int value = 26;
        list->add(value);
        QCOMPARE(list->remove(value), value);
    }

    void testRemoveElements()
    {
        srand(time(NULL));
        int elements[size];
        currentValue = valueInit;
        const int elementsNumber = size;
        for (int i = 0; i < elementsNumber; ++i)
        {
            currentValue = rand() % maxNumber;
            if (list->find(currentValue) != list->notFoundIndex)
            {
                QVERIFY_EXCEPTION_THROWN(list->add(currentValue), UniqueList::ElementAlreadyExistsException);
                --size;
                continue;
            }
            elements[counter++] = currentValue;
            list->add(currentValue);
        }
        const int notAddedElementsNumber = rand() % size;
        for (int i = size; i < size + notAddedElementsNumber; ++i)
        {
            currentValue = rand() % maxNumber;
            elements[i] = currentValue;
        }
        size += notAddedElementsNumber;
        std::random_shuffle(elements, elements + size);
        for (int i = 0; i < size; ++i)
        {
            if (list->find(elements[i]) == list->notFoundIndex)
            {
                QVERIFY_EXCEPTION_THROWN(list->remove(elements[i]), ArrayLinkedList::RemoveNonexistedElementException);
                continue;
            }
            int removedValue = list->remove(elements[i]);
            QCOMPARE(removedValue, elements[i]);
        }
    }

};
