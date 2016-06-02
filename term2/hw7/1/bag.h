#pragma once

#include "avltree.h"

template <typename T>
/*!
 * \brief This class for definition basis bag methods
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
    bool remove(const T &currentValue);
    /*!
     * \brief find value in Bag
     * \param currentValue
     * \return
     */
    bool find(const T &currentValue);
    /*!
     * \brief intersection this Bag with disjointBag
     * \param disjointBag
     *
     * result of intersection is in this Bag
     */
    Bag<T> intersection(Bag<T> *disjointBag);
    /*!
     * \brief merge this Bag with mergeBag
     * \param mergeBag
     *
     * result of merge is in this Bag
     */
    Bag<T> merge(Bag<T> *mergeBag);
    /*!
     * \brief recording all elements in QVector
     * \return
     */
    QVector<T> recording();

private:
    AVLTree<T> *tree;
};

//--------------------------------------------------------------------------

template <typename T>
Bag<T>::Bag()
{
    tree = new AVLTree<T>();
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
void Bag<T>::add(const T &currentValue)
{
    tree->add(currentValue);
}

template <typename T>
bool Bag<T>::remove(const T &currentValue)
{
    return tree->remove(currentValue);
}

template <typename T>
Bag<T> Bag<T>::intersection(Bag<T> *disjointBag)
{
    tree->intersection(disjointBag->tree);
    return *disjointBag;
}

template <typename T>
Bag<T> Bag<T>::merge(Bag<T> *mergeBag)
{
    tree->merge(mergeBag->tree);
    return *mergeBag;
}

template <typename T>
QVector<T> Bag<T>::recording()
{
    return tree->recordingTree();
}
