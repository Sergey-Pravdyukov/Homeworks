#pragma once

#include <QString>

class SortingFacility
{
public:
    SortingFacility(){}
    static QVector<QString> haveInfixToPostfix(const QVector<QString> &expression);
    static QString havePostfixToSum(QVector<QString> &postfixData);
};
