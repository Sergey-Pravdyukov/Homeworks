#include "operationsystem.h"

OperationSystem::OperationSystem(OperationSystemType currentType)
{
    switch (currentType)
    {
    case Mac:
    {
        infectionProbability = macInfectionProbability;
        break;
    }
    case Linux:
    {
        infectionProbability = linuxInfectionProbability;
        break;
    }
    case Windows:
    {
        infectionProbability = windowsInfectioProbability;
        break;
    }
    }
}
