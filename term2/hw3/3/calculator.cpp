#include <cctype>

#include "calculator.h"
#include "sortingfacility.h"

int haveSum(QString *expression)
{
    SortingFacility *sortingFacility = new SortingFacility();
    QString newExpression = sortingFacility->haveInfixToPostfix(*expression);
    return sortingFacility->havePostfixToSum(newExpression).toInt();
}

int Calculator::calc(QString *expression)
{
    return haveSum(expression);
}
