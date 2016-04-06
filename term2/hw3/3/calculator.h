#pragma once

#include <QString>

class Calculator
{
public:
    Calculator(){}

    static int calculate(const QVector<QString> expression);

};
