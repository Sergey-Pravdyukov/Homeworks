#pragma once

template <typename T>
/*!
 * \brief This abstract class for declare basis set methods
 */
class Set
{
public:
    /*!
     * \brief add value to Set
     * \param currentValue
     */
    virtual void add(const T &currentValue) = 0;
    /*!
     * \brief remove value from Set
     * \param currentValue
     * \return removed value
     */
    virtual T remove(const T &currentValue) = 0;
    /*!
     * \brief find value in Set
     * \param currentValue
     * \return number of found elements in Set
     */
    virtual int find(const T &currentValue) const = 0;
    /*!
     * \brief intersection this Set with disjointSet
     * \param disjointSet
     *
     * result of intersection is in this Set
     */
    virtual void intersection(Set<T> *disjointSet) = 0;
    /*!
     * \brief merge this Set with mergeSet
     * \param mergeSet
     *
     * result of merge is in this Set
     */
    virtual void merge(Set<T> *mergeSet) = 0;
};

