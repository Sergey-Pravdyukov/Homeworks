#include "virus.h"

#include <limits>

Virus::Virus(Computer *&computer)
{
    this->computer = computer;
    this->computer->wasInfected = true;
}

int Virus::tryInfectComputer(Net *&net)
{
    Computer *newComputer = this->getUninfectedComputer(net);
    if (computer == newComputer)
        return notInfected;
    computer = newComputer;
    computer->wasInfected = true;
    return net->getComputerIndex(computer);
}

bool infectionAccessibility(const Computer* computer)
{
    const double infectionProbability = (int(rand()) % 11) / 10.0;
    const double epsilon = std::numeric_limits<double>::epsilon();
    return (infectionProbability - computer->infectionProbability >= epsilon);
}

Computer* Virus::findUninfectedComputer(Net *&net) const
{
    const int index = net->getComputerIndex(computer);
    for (int j = 0; j < int(net->computersNet[index].size()); ++j)
        if (!net->computersNet[index][j]->wasInfected)
            return net->computersNet[index][j];
    return computer;
}

Computer* Virus::getUninfectedComputer(Net *&net) const
{
    if (!infectionAccessibility(computer))
        return computer;
    return this->findUninfectedComputer(net);
}
