#include <cstdio>
#include <iostream>

#include "fileoutput.h"

/*!
 * \brief FileOutput::FileOutput open file stream
 */

FileOutput::FileOutput()
{
    std::cout << "Please, press ENTER." << std::endl;
    freopen("output.txt", "w", stdout);
}
