#include "output.h"

void Output::print()
{
    const bool toOutput = true;
    Snake *print = new Snake(toOutput);
    print->bypassSnake(size, array);
}

void Output::out(const QString &stringForOutput)
{
    std::cout << stringForOutput.toStdString() << " ";
}
