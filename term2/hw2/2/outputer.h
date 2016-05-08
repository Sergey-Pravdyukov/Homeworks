#pragma once

#include <fstream>
#include <iostream>
#include <cctype>

class Outputer
{
public:
    static void snakePrint(int &size, int **&array, std::ostream &fout);
private:
    /*!
     * \brief check going beyond the bounds of array
     */
    static bool check(const int &currentX, const int &currentY, const int &size);
};
