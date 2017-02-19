#include "output.h"

void Output::out()
{
    QVector<int> recordSnakeCrawing = Snake::bypassSnake(size, array);
    this->print(recordSnakeCrawing);
}
