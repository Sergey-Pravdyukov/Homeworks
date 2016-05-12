#include "output.h"

void Output::print()
{
    QVector<int> recordSnakeCrawing = Snake::bypassSnake(size, array);
    std::cout << "Output of array bypass snake: ";
    for (int i = 0; i < recordSnakeCrawing.size(); ++i)
        std::cout << recordSnakeCrawing[i] << " ";
}
