#pragma once

#include <iostream>

template <typename T, int dimension>
/*!
 * \brief This class determines some methods for working with Vector
 */
class Vector
{
public:
    Vector();
    Vector(int *array);
    Vector(const Vector &currentVector);
    ~Vector();

    /*!
     * \brief sum of appropriate coordinates recorded as Vector
     * \param currentVector
     * \return
     */
    Vector<T, dimension> operator +(Vector &currentVector);
    /*!
     * \brief substraction of appropriate coordinates recorded as Vector
     * \param currentVector
     * \return
     */
    Vector<T, dimension> operator -(Vector &currentVector);
    /*!
     * \brief check Vector for equality
     * \param currentVector
     * \return
     */
    bool operator ==(Vector &currentVector);
    /*!
     * \brief scalar product of vectors
     * \param currentVector
     * \return
     */
    T operator *(Vector &currentVector);
    /*!
     * \brief check null vector
     * \return
     */
    bool isNull();
    void print();

    T *elements;
};

//----------------------------------------------------------------

template <typename T, int dimension>
Vector<T, dimension>::Vector() : elements(new T[dimension])
{
    for (int i = 0; i < dimension; ++i)
        elements[i] = 0;
}

template <typename T, int dimension>
Vector<T, dimension>::Vector(int *array)
{
    elements = new T[dimension];
    for (int i = 0; i < dimension; ++i)
        elements[i] = array[i];
}

template<typename T, int dimension>
Vector<T, dimension>::Vector(const Vector &currentVector)
{
    elements = new T[dimension];
    for (int i = 0; i < dimension; ++i)
        elements[i] = currentVector.elements[i];
}

template<typename T, int dimension>
Vector<T, dimension>::~Vector()
{
    delete[] elements;
}

template<typename T, int dimension>
T Vector<T, dimension>::operator *(Vector &currentVector)
{
    T result = 0;
    for (int i = 0; i < dimension; ++i)
        result += elements[i] * currentVector.elements[i];
    return result;
}

template<typename T, int dimension>
Vector<T, dimension> Vector<T, dimension>::operator +(Vector &currentVector)
{
    Vector<T, dimension> result;
    for (int i = 0; i < dimension; ++i)
        result.elements[i] = elements[i] + currentVector.elements[i];
    return result;
}

template <typename T, int dimension>
Vector<T, dimension> Vector<T, dimension>::operator -(Vector &currentVector)
{
    Vector<T, dimension> result;
    for (int i = 0; i < dimension; ++i)
        result.elements[i] = elements[i] - currentVector.elements[i];
    return result;
}

template <typename T, int dimension>
bool Vector<T, dimension>::operator ==(Vector &currentVector)
{
    bool result = true;
    for (int i = 0; i < dimension; ++i)
        if (elements[i] != currentVector.elements[i])
            result = false;
    return result;
}

template <typename T, int dimension>
bool Vector<T, dimension>::isNull()
{
    bool result = true;
    for (int i = 0; i < dimension; ++i)
        if (elements[i] != 0)
            result = false;
    return result;
}

template<typename T, int dimension>
void Vector<T, dimension>::print()
{
    for (int i = 0; i < dimension; ++i)
        std::cout << elements[i] << " ";
    std::cout << std::endl;
}


