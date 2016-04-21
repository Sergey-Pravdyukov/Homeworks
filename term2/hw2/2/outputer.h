#pragma once

class Outputer
{
public:
    /*!
     * \brief check going beyond the bounds of array
     */
    static bool check(int currentX, int currentY, int size);
    /*!
     * \brief output some elements in the line
     */
    static void output(int &step, int &index, int &currentX, int &currentY,
                       int **array, int x[], int y[], int size);
};
