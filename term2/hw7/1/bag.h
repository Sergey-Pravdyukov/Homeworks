#pragma once

template <typename T>
/*!
 * \brief This abstract class for declare basis Bag methods
 */
class Bag
{
public:
    /*!
     * \brief add value to Bag
     * \param currentValue
     */
    virtual void add(const T &currentValue) = 0;
    /*!
     * \brief remove value from Bag
     * \param currentValue
     * \return removed value
     */
    virtual T remove(const T &currentValue) = 0;
    /*!
     * \brief find value in Bag
     * \param currentValue
     * \return number of found elements in Bag
     */
    virtual int find(const T &currentValue) const = 0;
    /*!
     * \brief intersection this Bag with disjointBag
     * \param disjointBag
     *
     * result of intersection is in this Bag
     */
    virtual void intersection(Bag<T> *disjointBag) = 0;
    /*!
     * \brief merge this Bag with mergeBag
     * \param mergeBag
     *
     * result of merge is in this Bag
     */
    virtual void merge(Bag<T> *mergeBag) = 0;
};

