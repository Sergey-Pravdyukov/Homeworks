#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <cstdlib>
#include <ctime>

#include "vector.h"

class TestVector : public QObject
{
    Q_OBJECT
public:
    explicit TestVector(QObject *parent = 0) : QObject(parent) {}

private:
    const int maxSize = 22;
    const int maxNumber = 26;

    void createArray(int elements[])
    {
        srand(time(NULL));
        for (int i = 0; i < 10; ++i)
            elements[i] = rand() % maxNumber;
    }

private slots:
    void testNullVector()
    {
        Vector<int, 5> nullVector;
        QVERIFY(nullVector.isNull());

        int elements[5] = {0, 4, 1, 3, 2};
        Vector<int, 5> notNullVector(elements);
        QVERIFY(!notNullVector.isNull());
    }

    void testCopyVector()
    {
        int elements[10];
        createArray(elements);
        Vector<int, 10> firstVector(elements);
        Vector<int, 10> secondVector(firstVector);
        QVERIFY(firstVector == secondVector);
    }

    void testSum()
    {
        int firstVectorElements[10];
        createArray(firstVectorElements);
        Vector<int, 10> firstVector(firstVectorElements);
        int secondVectorElements[10];
        createArray(secondVectorElements);
        Vector<int, 10> secondVector(secondVectorElements);
        Vector<int, 10> sumVector(firstVector + secondVector);
        for (int i = 0; i < 10; ++i)
            QCOMPARE(sumVector.elements[i], (firstVector + secondVector).elements[i]);
    }

    void testSubstraction()
    {
        int elements[10];
        createArray(elements);
        Vector<int, 10> firstVector(elements);
        Vector<int, 10> secondVector(elements);
        Vector<int, 10> substractionVector(firstVector - secondVector);
        for (int i = 0; i < 10; ++i)
            QCOMPARE(0, substractionVector.elements[i]);
    }

    void testScalarProduct()
    {
        int firstVectorElements[4] = {-1, 0, 2, 3};
        Vector<int, 4> firstVector(firstVectorElements);
        int secondVectorElements[4] = {-4, 7, -8, 6};
        Vector<int, 4> secondVector(secondVectorElements);
        int result = 0;
        for (int i = 0; i < 4; ++i)
            result += firstVectorElements[i] * secondVectorElements[i];
        QCOMPARE(result, firstVector * secondVector);
    }

};

