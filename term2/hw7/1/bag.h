#pragma once

#include "avltree.h"

template <typename T>
/*!
 * \brief This abstract class for definition basis Bag methods
 */
class Bag
{
public:
    Bag();
    ~Bag();

    /*!
     * \brief add value to Bag
     * \param currentValue
     */
    void add(const T &currentValue);
    /*!
     * \brief remove value from Bag
     * \param currentValue
     * \return removed value
     */
    int remove(const T &currentValue);
    /*!
     * \brief find value in Bag
     * \param currentValue
     * \return number of found elements in Bag
     */
    int find(const T &currentValue) const;
    /*!
     * \brief intersection this Bag with disjointBag
     * \param disjointBag
     *
     * result of intersection is in this Bag
     */
    void intersection(Bag<T> *disjointBag);
    /*!
     * \brief merge this Bag with mergeBag
     * \param mergeBag
     *
     * result of merge is in this Bag
     */
    void merge(Bag<T> *mergeBag);

private:
    AVLTree<T> *tree;
};


template <typename T>
Bag<T>::Bag()
{
    tree = new AVLTree();
}

template <typename T>
Bag<T>::~Bag()
{
    delete tree;
}

template <typename T>
bool Bag<T>::find(const T &currentValue)
{
    return tree->find(currentValue);
}

template <typename T>
bool Bag<T>::add(const T &currentValue)
{
    return tree->add(currentValue);
}

template <typename T>
int Bag<T>::remove(const T &currentValue)
{
    if (!tree->find(currentValue))
        throw RemoveNonexistentElement();
    return tree->remove(currentValue);
}

template <typename T>
Bag<T> Bag<T>::intersection(Bag<T> *disjointBag)
{
    tree->intersection(disjointBag);
    return tree;
}

template <typename T>
Bag<T> Bag<T>::merge(Bag<T> *mergeBag)
{
    tree->merge(mergeBag);
    return tree;
}


