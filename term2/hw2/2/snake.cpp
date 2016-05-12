#include "snake.h"

void debugOutput(const QVector<int> &elementsOfArray)
{
    std::cout << "DEBUG OUTPUT: " << std::endl;
    for (int i = 0; i < elementsOfArray.size(); ++i)
        std::cout << elementsOfArray[i] << " ";
    std::cout << std::endl;
}

bool Snake::check(const int &currentX, const int &currentY, const int &size)
{
    return ((0 <= currentX && currentX < size) &&
            (0 <= currentY && currentY < size));
}

QVector<int> Snake::bypassSnake(int &size, int **array)
{
    const int numberOfDimensions = 4;
    const int stepInit = 1;
    const int indexOfDimensionInit = 0;
    int currentX = size / 2;
    int currentY = size / 2;
    int step = stepInit;
    int indexOfDimension = indexOfDimensionInit;
    int x[numberOfDimensions] = {1, 0, -1, 0};
    int y[numberOfDimensions] = {0, 1, 0, -1};
    QVector<int> elementsOfArray;
    elementsOfArray.clear();
    elementsOfArray.push_back(array[currentX][currentY]);
    while (check(currentX, currentY, size))
    {
        for (int i = 0; i < step; ++i)
        {
            currentX += x[indexOfDimension];
            currentY += y[indexOfDimension];
            if (!check(currentX, currentY, size))
                break;
            elementsOfArray.push_back(array[currentX][currentY]);
        }
        step += (indexOfDimension % 2);
        indexOfDimension = (indexOfDimension + 1) % numberOfDimensions;
    }
    return elementsOfArray;
}
