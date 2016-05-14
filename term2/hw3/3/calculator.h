#pragma once

#include <QVector>
#include <QString>

/*!
 * \brief This class calculates value of arithmetic expression
 */
class Calculator
{
public:
    /*!
     * \brief calculate value of arithmetic expression
     * \param expression
     * \return
     */
    static double calculate(const QVector<QString> &expression);
};
