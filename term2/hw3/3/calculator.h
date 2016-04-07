#pragma once

#include <QVector>
#include <QString>

class Calculator
{
public:
    Calculator(){}

    static double calculate(const QVector<QString> &expression);
};
