#include "testvirus.h"
#include "virus.h"

TestVirus::TestVirus(Computer *&computer) : Virus(computer) {}

Computer* TestVirus::getUninfectedComputer(Net*& net) const
{
    const int index = net->getComputerIndex(computer);
    for (int j = 0; j < int(net->computersNet[index].size()); ++j)
        if (!net->computersNet[index][j]->wasInfected)
            return net->computersNet[index][j];
    return computer;
}
