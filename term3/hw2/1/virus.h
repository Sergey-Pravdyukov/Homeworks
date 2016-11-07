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
    Virus(Computer *&computer);

    /*!
     * \brief try to infect any uninfected computer in the Net
     * \return index of infected computer
     */
    int tryInfectComputer(Net *&net);

    static const int notInfected = -1;
protected:
    /*!
     * \brief findUninfectedComputer
     * \return each uninfected computer in the Net, otherwise source computer for current step
     */
    Computer* findUninfectedComputer(Net *&net) const;
    /*!
     * \brief get uninfected computer from the Net
     * \return pointer to chosen computer
     */
    virtual Computer* getUninfectedComputer(Net *&net) const;
private:
    Computer *computer = nullptr;
};
