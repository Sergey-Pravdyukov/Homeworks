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
private:
    /*!
     * \brief notAnOperation for initialization default of operation
     */
    const char notAnOperation = '?';
    /*!
     * \brief notANumber for initilization integer values
     */
    const int notANumber = INT_MIN;

    char operation = notAnOperation;
    int firstOperand = notANumber;
    int secondOperand = notANumber;
};
