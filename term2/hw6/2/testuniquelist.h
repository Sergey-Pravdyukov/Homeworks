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
    const int maxSize = 17;

    void addElements(int elements[], int &listSize)
    {
        int addedElementsCounter = 0;
        for (int i = 0; i < listSize; ++i)
        {
            const int value = rand() % maxNumber + 1;
            if (list->find(value) != list->notFoundIndex)
            {
                QVERIFY_EXCEPTION_THROWN(list->add(value), UniqueList::ElementAlreadyExistsException);
                continue;
            }
            elements[addedElementsCounter++] = value;
            list->add(value);
        }
        listSize = addedElementsCounter;
    }

    void removeElements(int elements[], const int &listSize)
    {
        for (int i = 0; i < listSize; ++i)
        {
            if (list->find(elements[i]) == list->notFoundIndex)
            {
                QVERIFY_EXCEPTION_THROWN(list->remove(elements[i]), ArrayLinkedList::RemoveNonexistedElementException);
                continue;
            }
            QCOMPARE(list->remove(elements[i]), elements[i]);
        }
    }

private slots:
    void init()
    {
        list = new UniqueList();
    }

    void cleanup()
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
        int *listElements = list->toArray();
        QCOMPARE(listElements[0], 7238);
    }

    void testAddElements()
    {
        srand(time(NULL));
        int size = rand() % maxSize + 1;
        int elements[maxSize];
        addElements(elements, size);
        int *listElements = list->toArray();
        for (int i = 0; i < size; ++i)
            QCOMPARE(listElements[i], elements[i]);
    }

    void testSizeOfList()
    {
        srand(time(NULL));
        int size = rand() % maxSize + 1;
        int elements[maxSize];
        addElements(elements, size);
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
        int size = rand() % maxSize;
        int elements[2 * maxSize];
        addElements(elements, size);
        const int notAddedElementsNumber = rand() % maxSize + 1;
        for (int i = size; i < size + notAddedElementsNumber; ++i)
        {
            const int value = rand() % maxNumber;
            elements[i] = value;
        }
        size += notAddedElementsNumber;
        std::random_shuffle(elements, elements + size);
        removeElements(elements, size);
    }

};
