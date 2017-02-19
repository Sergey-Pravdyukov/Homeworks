#pragma once

#include <climits>

/*!
 * \brief This class calculates binary expressions
 */
class Calculator
{
public:
    /*!
     * \brief calculate binary expression
     * \param operation
     * \param firstOperand
     * \param secondOperand
     * \return value of expression
     */
    int calculate(char operation, int firstOperand, int secondOperand);

    /*!
     * \brief notAnOperation for initialization default of operation
     */
    static const char notAnOperation = '?';
    /*!
     * \brief notANumber for initilization integer values
     */
    static const int notANumber = INT_MIN;
private:
    char operation = notAnOperation;
    int firstOperand = notANumber;
    int secondOperand = notANumber;
};
