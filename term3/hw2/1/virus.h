#pragma once

#include <computer.h>
#include <net.h>

/*!
 * \brief The Virus class - determines virus behaviour in the Net
 */
class Virus
{
public:
    Virus() {}
    /*!
     * \brief Virus's constructor originating from fixed Computer
     */
    Virus(Computer*&);

    /*!
     * \brief try to infect any uninfected computer int the Net
     * \return index of infected computer
     */
    int tryInfectComputer(Net*&);

    Computer *computer = nullptr;

    static const int notInfected = -1;
protected:
    /*!
     * \brief get uninfected computer from the Net
     * \return pointer to chosen computer
     */
    virtual Computer* getUninfectedComputer(Net*&) const;
};
