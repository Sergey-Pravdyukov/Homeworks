#pragma once

#include <virus.h>
#include <net.h>

/*!
 * \brief The TestVirus modified class for unit testing
 */
class TestVirus : public Virus
{
public:
    TestVirus() {}
    TestVirus(Computer *&computer);

    Computer* getUninfectedComputer(Net *&net) const;
};
