#include "calculator.h"
#include "sortingfacility.h"

double haveSum(QVector<QString> const &expression)
{
    QVector<QString> newExpression = SortingFacility::haveInfixToPostfix(expression);
    return SortingFacility::havePostfixToSum(newExpression).toDouble();
}

double Calculator::calculate(const QVector<QString> &expression)
{
    return haveSum(expression);
}
