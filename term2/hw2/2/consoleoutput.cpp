#include <iostream>

#include "consoleoutput.h"

enum {init, fileOutput, consoleOutput};

ConsoleOutput::ConsoleOutput(int **currentArray, int currentSize)
{
    array = currentArray;
    size = currentSize;
}

void ConsoleOutput::snake()
{
    int currentX = size / 2;
    int currentY = size / 2;
    int step = 1;
    int indexOfDimension = 0;
    const int numberOfDimensions = 4;

    int x[numberOfDimensions] = {1, 0, -1, 0};
    int y[numberOfDimensions] = {0, 1, 0, -1};
    std::cout << "Output of array bypass snake: " << std::endl;
    std::cout << array[currentX][currentY]<< " ";
    while (Outputer::check(currentX, currentY, size))
        Outputer::output(step, indexOfDimension, currentX, currentY, array, x, y, size);
}
