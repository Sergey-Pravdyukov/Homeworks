#pragma once

template <class T>
/*!
 * \brief This abstract class for random type compares
 */
class Comparator
{
public:
    /*!
     * \brief compare two random (equal) type elements
     * \param firstElement
     * \param secondElement
     * \return
     */
    virtual bool isFirstElementLessThanSecond(const T &firstElement, const T &secondElement) = 0;
};

