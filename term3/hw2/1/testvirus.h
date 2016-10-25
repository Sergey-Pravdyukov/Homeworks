#pragma once

#include <virus.h>
#include <net.h>

class TestVirus : public Virus
{
public:
    TestVirus() {}
    TestVirus(Computer*& );

    Computer* getUninfectedComputer(Net *&) const;
};
