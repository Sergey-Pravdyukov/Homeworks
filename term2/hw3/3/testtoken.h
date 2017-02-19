#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "token.h"

class TestToken : public QObject
{
    Q_OBJECT

public:
    explicit TestToken(QObject *parent = 0):
        QObject(parent)
    {}

private:
    bool result;
    bool correctResult;
    QString token;

private slots:
    void init()
    {
        const bool resultInit = false;
        const bool correctResultInit = false;

        result = resultInit;
        correctResult = correctResultInit;
        token = "/0";
    }

    void testIsNumber()
    {
        correctResult = true;
        token = "26";
        result = Token::isNumber(token);
        QCOMPARE(result, correctResult);
    }

    void testIsNotNumber()
    {
        correctResult = false;
        QString token = "=";
        result = Token::isNumber(token);
        QCOMPARE(result, correctResult);
    }

    void testIsBracket()
    {
        correctResult = true;
        token = "(";
        result = Token::isBracket(token);
        QCOMPARE(result, correctResult);
        token = ")";
        result = Token::isBracket(token);
    }

    void testIsNotBracket()
    {
        correctResult = false;
        token = "26";
        result = Token::isBracket(token);
        QCOMPARE(result, correctResult);
        token = "*";
        result = Token::isBracket(token);
        QCOMPARE(result, correctResult);
    }

    void testOperationPriority()
    {
        const int kindsOfTokens = 7;
        QString tokens[kindsOfTokens] = {"+", "-", "*", "/", "=", "(", "26"};
        int correctResults[kindsOfTokens] =
        {
            lowPriorityOperation,
            lowPriorityOperation,
            highPriorityOperation,
            highPriorityOperation,
            notAnOperation,
            notAnOperation,
            notAnOperation
        };
        for (int i = 0; i < kindsOfTokens; ++i)
        {
            int result = Token::operationPriority(tokens[i]);
            QCOMPARE(result, correctResults[i]);
        }
    }

};
