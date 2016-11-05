#include "testvirus.h"
#include "virus.h"

TestVirus::TestVirus(Computer *&computer) : Virus(computer) {}

Computer* TestVirus::getUninfectedComputer(Net*& net) const
{
    return findUninfectedComputer(net);
}
