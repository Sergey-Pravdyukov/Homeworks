#pragma once

#include "avltree.h"

template <typename T>
/*!
 * \brief This class for definition basis set methods
 */
class Set
{
public:
    Set();
    ~Set();

    /*!
     * \brief add value to Set
     * \param currentValue
     */
    bool add(const T &currentValue);
    /*!
     * \brief remove value from Set
     * \param currentValue
     * \return removed value
     */
    bool remove(const T &currentValue);
    /*!
     * \brief find value in Set
     * \param currentValue
     * \return
     */
    bool find(const T &currentValue);
    /*!
     * \brief intersection this Set with disjointSet
     * \param disjointSet
     *
     * result of intersection is in this Set
     */
    Set<T> intersection(Set<T> *disjointSet);
    /*!
     * \brief merge this Set with mergeSet
     * \param mergeSet
     *
     * result of merge is in this Set
     */
    Set<T> merge(Set<T> *mergeSet);

private:
    AVLTree<T> *tree;
};

//--------------------------------------------------------------------------

template <typename T>
Set<T>::Set()
{
    tree = new AVLTree();
}

template <typename T>
Set<T>::~Set()
{
    delete tree;
}

template <typename T>
bool Set<T>::find(const T &currentValue)
{
    return tree->find(currentValue);
}

template <typename T>
bool Set<T>::add(const T &currentValue)
{
    if (tree->find(currentValue))
        throw AddExistingElement();
    return tree->add(currentValue);
}

template <typename T>
bool Set<T>::remove(const T &currentValue)
{
    if (!tree->find(currentValue))
        throw RemoveNonexistentElement();
    return tree->remove(currentValue);
}

template <typename T>
Set<T> Set<T>::intersection(Set<T> *disjointSet)
{
    tree->intersection(disjointSet);
    return tree;
}

template <typename T>
Set<T> Set<T>::merge(Set<T> *mergeSet)
{
    tree->merge(mergeSet);
    return tree;
}

