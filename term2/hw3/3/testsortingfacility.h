#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include <iostream>

#include "sortingfacility.h"
#include "parser.h"

class TestSortingFacility : public QObject
{
    Q_OBJECT

public:
    explicit TestSortingFacility(QObject *parent = 0):
        QObject(parent)
    {}

private:
    QVector<QString> infixFormExpression;
    QVector<QString> postfixFormExpression;

private slots:
    void init()
    {
        infixFormExpression.clear();
        postfixFormExpression.clear();
    }

    void testTokenFromInfixToPostfix()
    {
        const QString token = "26";
        infixFormExpression.push_back(token);
        postfixFormExpression = SortingFacility::infixToPostfix(infixFormExpression);
        QCOMPARE(postfixFormExpression[0], token);
    }

    void testExpressionFromInfixToPostfix()
    {
        const QString expression = "-(3+4)*(-4)+18";
        const int correctNumberOfTokens = 12;
        const QString tokens[correctNumberOfTokens] = {"0", "3", "(", "4", "+", "-", "0", "4", "-", "*", "18", "+"};
        infixFormExpression = Parser::haveParseDisplayTextToExpressions(expression);
        postfixFormExpression = SortingFacility::infixToPostfix(infixFormExpression);
        for (int i = 0; i < correctNumberOfTokens; ++i)
            QCOMPARE(postfixFormExpression[i], tokens[i]);
    }

    void testTokenPostfixToSum()
    {
        const QString token = "26";
        infixFormExpression.push_back(token);
        postfixFormExpression = SortingFacility::infixToPostfix(infixFormExpression);
        const QString result = SortingFacility::postfixToSum(postfixFormExpression);
        QCOMPARE(result, token);
    }

    void testExpressionPostfixToSum()
    {
        const QString expression = "-(3+4)*(-4)+18";
        const QString correctValueOfExpression = "46";
        infixFormExpression = Parser::haveParseDisplayTextToExpressions(expression);
        postfixFormExpression = SortingFacility::infixToPostfix(infixFormExpression);
        const QString result = SortingFacility::postfixToSum(postfixFormExpression);
        QCOMPARE(result, correctValueOfExpression);
    }
};
