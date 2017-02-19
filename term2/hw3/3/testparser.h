#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <QString>

#include "parser.h"

class TestParser : public QObject
{
    Q_OBJECT

public:
    explicit TestParser(QObject *parent = 0):
        QObject(parent)
    {}

private:
    QString displayText;

private slots:
    void init()
    {
        displayText = "";
    }

    void testEmptyExpression()
    {
        const int correctSize = 0;
        QVector<QString> expression = Parser::haveParseDisplayTextToExpressions(displayText);
        const int size = expression.size();
        QCOMPARE(size, correctSize);
    }

    void testSizeNonEmptyExpression()
    {
        const int correctSize = 3;
        displayText = "3+7";
        QVector<QString> expression = Parser::haveParseDisplayTextToExpressions(displayText);
        const int size = expression.size();
        QCOMPARE(size, correctSize);
    }

    void testToken()
    {
        QString token = "26";
        QVector<QString> correctExpression;
        correctExpression.push_back(token);
        QVector<QString> expression = Parser::haveParseDisplayTextToExpressions(token);
        QCOMPARE(expression, correctExpression);
    }

    void testExpression()
    {
        displayText = "-(3+4)*(-4)+18";
        const int correctSizeOfExpression = 15;
        QString tokens[correctSizeOfExpression] = {"0", "-", "(", "3", "+", "4", ")", "*", "(", "0", "-", "4", ")", "+", "18"};
        QVector<QString> expression = Parser::haveParseDisplayTextToExpressions(displayText);
        for (int i = 0; i < correctSizeOfExpression; ++i)
            QCOMPARE(expression[i], tokens[i]);
    }
};
