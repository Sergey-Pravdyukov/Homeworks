#pragma once

/*!
 * \brief The Sort class to sort random array
 */
class Sort
{
public:
    /*!
     * \brief sort array by this sorting algorithm
     * \param array that sorting
     */
    virtual void sort(int *array) = 0;
    virtual ~Sort();

protected:
    /*!
     * \brief copy array from one array to another
     * \param arrayFrom which the copying
     * \param arrayTo which is copied
     */
    void copy(const int *arrayFrom, int *arrayTo);
    /*!
     * \brief debugOutput of array from left to right
     * \param array that is output
     */
    void debugOutput(const int *array);

    const int maxSize = int(1e3);

    int *array = new int[maxSize];
    int size = 0;
};
