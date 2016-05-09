#include "outputer.h"

void debugOutput(const QVector<int> &bypassSnake)
{
    std::cout << "DEBUG OUTPUT: " << std::endl;
    for (int i = 0; i < bypassSnake.size(); ++i)
        std::cout << bypassSnake[i] << " ";
    std::cout << std::endl;
}

bool Outputer::check(const int &currentX, const int &currentY, const int &size)
{
    return ((0 <= currentX && currentX < size) &&
            (0 <= currentY && currentY < size));
}

void Outputer::prepareItemsToAdd(const bool &toOutput)
{
    if (toOutput)
        std::cout << "Output of array bypass snake: " << std::endl;
    else
        this->bypassSnake.clear();
}

void Outputer::addItems(const bool &toOutput, const int &value)
{
    if (toOutput)
        std::cout << value << " ";
    else
        this->bypassSnake.push_back(value);
}

void Outputer::snakePrint(int &size, int **&array, const bool &toOutput)
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
    this->prepareItemsToAdd(toOutput);
    this->addItems(toOutput, array[currentX][currentY]);
    while (this->check(currentX, currentY, size))
    {
        for (int i = 0; i < step; ++i)
        {
            currentX += x[indexOfDimension];
            currentY += y[indexOfDimension];
            if (!this->check(currentX, currentY, size))
            {
                //std::cout << "begin debugOutput!" << std::endl;
                //debugOutput(this->bypassSnake);
                return;
            }
            this->addItems(toOutput, array[currentX][currentY]);
        }
        step += (indexOfDimension % 2);
        indexOfDimension = (indexOfDimension + 1) % numberOfDimensions;
    }
}

QVector<int> Outputer::recieveBypassSnake()
{
    return this->bypassSnake;
}
