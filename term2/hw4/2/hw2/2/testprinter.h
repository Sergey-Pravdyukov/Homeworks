#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <QVector>
#include <iostream>

#include "snake.h"

class TestPrinter : public QObject
{
    Q_OBJECT

public:
    explicit TestPrinter(QObject *parent = 0):
        QObject(parent)
    {}
private:
    const int size = 9;
    Snake *test = new Snake();
    int **array;
    QVector<int> recordSnakeCrawling;
    QVector<int> correctSnakeCrawling;
private slots:
    void init()
    {
        array = new int*[size];
        for (int i = 0; i < size; ++i)
            array[i] = new int[size];
        correctSnakeCrawling.clear();
        recordSnakeCrawling.clear();
    }

    void cleanup()
    {
        for (int i = 0; i < size; ++i)
            delete[] array[i];
        delete[] array;
    }

    void testArrayWithSize1()
    {
        int size = 1;
        const int value = 4;
        correctSnakeCrawling.push_back(value);
        array[0][0] = {value};
        recordSnakeCrawling = test->bypassSnake(size, array);
        QCOMPARE(recordSnakeCrawling, correctSnakeCrawling);
    }

    void testArrayWithSize3()
    {
        int size = 3;
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                array[i][j] = (j + 1) + i * size;
        const int arrayWithCorrectSnakeCrawling[size * size] = {5, 8, 9, 6, 3, 2, 1, 4, 7};
        for (int i = 0; i < size * size; ++i)
            correctSnakeCrawling.push_back(arrayWithCorrectSnakeCrawling[i]);
        recordSnakeCrawling = test->bypassSnake(size, array);
        QCOMPARE(recordSnakeCrawling, correctSnakeCrawling);
    }
};
