#include <iostream>

#include "outputer.h"

enum {init, fileOutput, consoleOutput};

Outputer::Outputer(int **currentArray, int currentSize)
{
    array = currentArray;
    size = currentSize;
}

/*!
 * \brief check checking that did not happen outputs for array bounds
 * \param currentX coordinate of matrix string
 * \param currentY coordinate of matrix collumn
 * \param size size of matrix
 * \return true, if we are in matrix, else false
 */

bool check(int currentX, int currentY, int size)
{
    return (0 <= currentX && currentX < size
            && 0 <= currentY && currentY < size);
}

void output(int &step, int &index, int &currentX, int &currentY,
            int **array, int x[], int y[], int size)
{
    for (int i = 0; i < step; ++i)
    {
        currentX += x[index];
        currentY += y[index];
        if (check(currentX, currentY, size))
        {
            std::cout << array[currentX][currentY] << " ";
        }
        else
        {
            return;
        }
    }
    step += (index % 2);
    index = (index + 1) % 4;
}

/*!
 * \brief Outputer::snake matrix spiraling(snake) output
 */

void Outputer::snake()
{
    /// center of matrix

    int currentX = size / 2;
    int currentY = size / 2;
    int step = 1;
    int indexOfDimension = 0;
    const int numberOfDimensions = 4;

    /// all possible 2D

    int x[numberOfDimensions] = {1, 0, -1, 0};
    int y[numberOfDimensions] = {0, 1, 0, -1};
    std::cout << "Output of array bypass snake: " << std::endl;
    std::cout << array[currentX][currentY]<< " ";
    while (check(currentX, currentY, size))
    {
        output(step, indexOfDimension, currentX, currentY, array, x, y, size);
    }
}
