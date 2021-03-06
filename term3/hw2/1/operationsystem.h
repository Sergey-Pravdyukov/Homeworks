#pragma once

#include <climits>
#include <cmath>
#include <iostream>

/*!
 * \brief The OperationSystemType enum - describes avaliable operation systems
 */
enum OperationSystemType
{
    Windows,
    Mac,
    Linux
};

/*!
 * \brief The OperationSystem class - defines operation system for computer in net with virus within it
 */
class OperationSystem
{
public:
    OperationSystem() {}
    /*!
     * \brief constructor with fixed OperationSystemType
     */
    OperationSystem(OperationSystemType currentType);

    static const int operationSystemsAmount = 3;

    /*!
     * \brief probability to get virus from another computer in net
     */
    double infectionProbability = 0.0;
private:
    OperationSystemType type;

    const double linuxInfectionProbability = 0.7;
    const double macInfectionProbability = 0.5;
    const double windowsInfectioProbability = 0.3;
};
