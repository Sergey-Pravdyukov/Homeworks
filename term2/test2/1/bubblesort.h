#pragma once

#include <QVector>
#include <algorithm>

#include "comparator.h"


template <class T>
/*!
 * \brief This class sorts the random list bubble sort
 */
class BubbleSort
{
public:
    /*!
     * \brief sort list bubble sort
     * \param list
     * \param compare element of list this comparator's rule
     */
    void sort(QVector<T> &list, Comparator<T> &comparator);

    /*!
     * \brief get size of current list
     * \return
     */
    int getSize();
private:
    const int sizeInit = 0;

    int size = sizeInit;
};

//-------------------------------------------------------------------------

template <class T>
int BubbleSort<T>::getSize()
{
    return size;
}

template <class T>
void BubbleSort<T>::sort(QVector<T> &list, Comparator<T> &comparator)
{
    size = list.size();
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (comparator.isFirstElementLessThanSecond(list[j + 1], list[j]))
                std::swap(list[j], list[j + 1]);
}
