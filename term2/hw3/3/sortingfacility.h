#pragma once

#include <QString>
#include <QVector>

class SortingFacility
{
public:
    SortingFacility(){}

    static QVector<QString> haveInfixToPostfix(const QVector<QString> &expression);
    static QString havePostfixToSum(QVector<QString> &postfixData);
};
