#include "output.h"

void Output::print()
{
    const bool toOutput = true;
    Snake *print = new Snake(toOutput);
    print->bypassSnake(size, array);
}
