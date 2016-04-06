#include <QVector>
#include <QString>

#include "calculator.h"
#include "sortingfacility.h"

int haveSum(QVector<QString> const &expression)
{
    QVector<QString> newExpression = SortingFacility::haveInfixToPostfix(expression);
    return SortingFacility::havePostfixToSum(newExpression).toInt();
}

int Calculator::calculate(const QVector<QString> expression)
{
    return haveSum(expression);
}
