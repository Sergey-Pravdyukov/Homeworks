#pragma once

#include "operationsystem.h"

/*!
 * \brief The Computer class describes any computer in a Net with Virus
 */
class Computer
{
public:
    Computer() {}
    /*!
     * \brief Computer's constructor with fixed OperationSystem
     */
    Computer(const OperationSystem& operationSystem) : operationSystem(operationSystem) {}

    bool wasInfected = false;

    const double infectionProbability = operationSystem.infectionProbability;
private:
    OperationSystem operationSystem;
};

