#pragma once

#include <QString>
#include <QVector>

#include "stack.h"
#include "token.h"

/*!
 * \brief This class implements Dijkstra's sorting facility algorithm
 */
class SortingFacility
{
public:
    /*!
     * \brief haveInfixToPostfix converts infix form expression to postfix form expression
     * \param expression
     * \return postfix form expression
     */
    static QVector<QString> infixToPostfix(const QVector<QString> &expression);
    /*!
     * \brief postfixToSum calculates postfix form expression
     * \param postfixData
     * \return value of postfix form expression recorded in string type
     */
    static QString postfixToSum(QVector<QString> &postfixData);
};
