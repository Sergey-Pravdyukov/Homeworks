#include "net.h"

Net::Net(std::vector <Computer*> computers, std::vector<std::vector<Computer*> > edges) :
    computers(computers),
    computersNet(edges) {}

int Net::getComputerIndex(Computer *computer) const
{
    const int notFound = -1;
    for (int i = 0; i < int(computers.size()); ++i)
        if (computer == this->computers[i])
            return i;
    return notFound;
}


