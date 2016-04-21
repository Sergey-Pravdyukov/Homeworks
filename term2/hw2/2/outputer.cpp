#include <iostream>

#include "outputer.h"

bool Outputer::check(int currentX, int currentY, int size)
{
    return (0 <= currentX && currentX < size &&
            0 <= currentY && currentY < size);
}

void Outputer::output(int &step, int &index, int &currentX, int &currentY,
                      int **array, int x[], int y[], int size)
{
    for (int i = 0; i < step; ++i)
    {
        currentX += x[index];
        currentY += y[index];
        if (check(currentX, currentY, size))
            std::cout << array[currentX][currentY] << " ";
        else
            return;
    }
    step += (index % 2);
    index = (index + 1) % 4;
}
