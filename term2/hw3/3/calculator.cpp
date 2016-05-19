#include "calculator.h"
#include "sortingfacility.h"

double haveSum(QVector<QString> const &expression)
{
    QVector<QString> newExpression = SortingFacility::infixToPostfix(expression);
    return SortingFacility::postfixToSum(newExpression).toDouble();
}

double Calculator::calculate(const QVector<QString> &expression)
{
    return haveSum(expression);
}
