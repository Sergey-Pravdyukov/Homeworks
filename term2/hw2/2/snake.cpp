#include "snake.h"

Snake::Snake(const bool &currentToOutput)
{
    toOutput = currentToOutput;
}

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

void Snake::prepareItemsToAdd()
{
    if (toOutput)
    {
        Output *output = new Output();
        QString stringForOutput = "Output of array bypass snake: ";
        output->out(stringForOutput);
        delete output;
    }
    else
        this->elementsOfArray.clear();
}

void Snake::addItems(const int &value)
{
    if (toOutput)
    {
        Output *output = new Output();
        QString stringForOutput = QString::number(value);
        output->out(stringForOutput);
        delete output;
    }
    else
        this->elementsOfArray.push_back(value);
}

void Snake::bypassSnake(int &size, int **array)
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
    this->prepareItemsToAdd();
    this->addItems(array[currentX][currentY]);
    while (this->check(currentX, currentY, size))
    {
        for (int i = 0; i < step; ++i)
        {
            currentX += x[indexOfDimension];
            currentY += y[indexOfDimension];
            if (!this->check(currentX, currentY, size))
            {
                //std::cout << "begin debugOutput!" << std::endl;
                //debugOutput(this->elementsOfArray);
                return;
            }
            this->addItems(array[currentX][currentY]);
        }
        step += (indexOfDimension % 2);
        indexOfDimension = (indexOfDimension + 1) % numberOfDimensions;
    }
}

QVector<int> Snake::recieveElementsOfArray()
{
    return this->elementsOfArray;
}
