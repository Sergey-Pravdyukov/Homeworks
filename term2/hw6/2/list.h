#pragma once

#include <climits>

/*!
 * \brief This abstract class declare basis methods for working with List
 */
class List
{
public:

    virtual ~List(){}
    /*!
     * \brief add value ti List
     * \param value
     */
    virtual void add(const int &value) = 0;
    /*!
     * \brief remove value from List
     * \param value
     * \return removed value
     */
    virtual int remove(const int &value) = 0;
    /*!
     * \brief find value's index in List
     * \param value
     * \return index if value found otherwise -1
     */
    virtual int find(const int &value) = 0;
    /*!
     * \brief print list from leftmost to rightmost elements
     */
    virtual void debugOutput() = 0;
    /*!
     * \brief get lenght of List
     * \return
     */
    virtual int getLenght() = 0;
protected:

    const int notANumber = INT_MIN;

    int size = sizeInit;
private:

    const int sizeInit = 0;
};
