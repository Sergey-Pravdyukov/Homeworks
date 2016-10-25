#include "operationsystem.h"

OperationSystem::OperationSystem(OperationSystemType currentType)
{
    switch (currentType)
    {
    case Mac:
    {
        infectionProbability = MacInfectionProbability;
        break;
    }
    case Linux:
    {
        infectionProbability = LinuxInfectionProbability;
        break;
    }
    case Windows:
    {
        infectionProbability = WindowsInfectioProbability;
        break;
    }
    }
}
