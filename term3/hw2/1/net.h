#pragma once

#include "computer.h"

#include <vector>

/*!
 * \brief The Net class describes Net with a Virus within
 */
class Net
{
public:
    Net() {}
    Net(std::vector <Computer*> computers, std::vector <std::vector<Computer*> > edges);

    std::vector <Computer*> computers;
    std::vector <std::vector <Computer*> > computersNet;

    /*!
     * \brief get computer index from computers vector
     * \return index of fixed computer
     */
    int getComputerIndex(Computer *computer) const;
};
