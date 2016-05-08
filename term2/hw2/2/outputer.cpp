#include "outputer.h"

bool Outputer::check(const int &currentX, const int &currentY, const int &size)
{
    return (0 <= currentX && currentX < size &&
            0 <= currentY && currentY < size);
}

void Outputer::snakePrint(int &size, int **&array, std::ostream &fout)
{
    const int numberOfDimensions = 4;
    int currentX = size / 2;
    int currentY = size / 2;
    int step = 1;
    int indexOfDimension = 0;
    int x[numberOfDimensions] = {1, 0, -1, 0};
    int y[numberOfDimensions] = {0, 1, 0, -1};
    fout << "Output of array bypass snake: " << std::endl;
    //std::cout << array[currentX][currentY] << " ";
    fout << array[currentX][currentY] << std::endl;
    while (Outputer::check(currentX, currentY, size))
    {
        for (int i = 0; i < step; ++i)
        {
            currentX += x[indexOfDimension];
            currentY += y[indexOfDimension];
            if (check(currentX, currentY, size))
            {
                //std::cout << array[currentX][currentY] << " ";
                fout << array[currentX][currentY] << std::endl;
            }
            else
                return;
        }
        step += (indexOfDimension % 2);
        indexOfDimension = (indexOfDimension + 1) % numberOfDimensions;
    }
}
