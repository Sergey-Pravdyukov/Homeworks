#pragma once

#include <QString>

/*!
 * \brief This class calculates binary expression
 */
class Calculator
{
public:
    /*!
     * \brief calculate binary expression
     * \param firstOperand
     * \param secondOperand
     * \param operation
     * \return
     */
    static int calculate(const int &firstOperand, const int &secondOperand, const QString &operation);
};
