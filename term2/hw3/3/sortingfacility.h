#pragma once

#include <QString>

class SortingFacility
{
public:
    SortingFacility(){}
    QString haveInfixToPostfix(QString expression);
    QString havePostfixToSum(QString postfixData);
};
