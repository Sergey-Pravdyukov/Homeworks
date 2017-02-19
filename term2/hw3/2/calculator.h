#pragma once

#include <QString>
#include <climits>

const int error = INT_MAX;

/*!
 * \brief This class calculates binary expression
 */
class Calculator
{
public:
    /*!
     * \brief calculates binary expression
     * \param firstOperand
     * \param secondOperand
     * \param operation
     * \return
     */
    static double calculate(const double &firstOperand, const double &secondOperand, const QString &operation);
};
