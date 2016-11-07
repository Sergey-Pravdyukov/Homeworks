#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <vector>

#include "net.h"
#include "virus.h"
#include "testvirus.h"

class NetTest : public QObject
{
   Q_OBJECT
public:
   explicit NetTest(QObject *parent = 0) : QObject(parent) {}

private:
    TestVirus* virus;
    Net* net;
    std::vector <std::vector<Computer*> > edges;
    std::vector <Computer*> computers;

private slots:
    void init()
    {
        net = new Net();
        virus = new TestVirus();
    }

    void cleanup()
    {
        delete net;
        delete virus;
        computers.clear();
        edges.clear();
    }

    void testOneComputer()
    {
        Computer* computer = new Computer(Linux);
        computers.push_back(computer);
        virus = new TestVirus(computer);
        edges.push_back(computers);
        net = new Net(computers, edges);
        QVERIFY(virus->tryInfectComputer(net) == Virus::notInfected);
    }

    void testTwoComputers()
    {
        Computer* sourceComputer = new Computer(Windows);
        Computer* targetComputer = new Computer(Mac);
        virus = new TestVirus(sourceComputer);
        edges.push_back(computers);
        edges.push_back(computers);
        computers.push_back(sourceComputer);
        computers.push_back(targetComputer);
        edges[0].push_back(computers[1]);
        edges[1].push_back(computers[0]);
        net = new Net(computers, edges);
        QVERIFY(virus->tryInfectComputer(net) == 1);
        QVERIFY(virus->tryInfectComputer(net) == Virus::notInfected);
    }

    void testSimplePath()
    {
        const int computersAmount = 10;
        const int edgesAmount = computersAmount - 1;
        Computer* sourceComputer = new Computer(Linux);
        virus = new TestVirus(sourceComputer);
        edges.push_back(computers);
        computers.push_back(sourceComputer);
        for (int i = 1; i < computersAmount; ++i)
        {
            Computer* newComputer = new Computer(Linux);
            std::vector <Computer*> computer;
            edges.push_back(computer);
            computers.push_back(newComputer);
        }
        for (int i = 0; i < edgesAmount; ++i)
        {
            edges[i].push_back(computers[i + 1]);
            edges[i + 1].push_back(computers[i]);
        }
        Net* net = new Net(computers, edges);
        for (int i = 0; i < computersAmount - 1; ++i)
            QVERIFY(virus->tryInfectComputer(net) == i + 1);
    }
};
