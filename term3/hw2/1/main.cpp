#include <iostream>
#include <vector>
#include <ctime>

#include "computer.h"
#include "net.h"
#include "virus.h"
#include "nettest.h"
#include "testvirus.h"

using namespace std;

enum OperationType
{
    init,
    infect,
    getStatus,
    haveExit
};

void operationsOutput()
{
    cout << "init - " << init << endl
         << "infect - " << infect << endl
         << "get status - " << getStatus << endl
         << "exit - " << haveExit << endl;
}

int main()
{
    NetTest test;
    QTest::qExec(&test);

//    srand(time(NULL));
//    int computersAmount = 0;
//    int edgesAmount = 0;
//    cout << "input computers and edges between it amounts: " << endl;
//    cin >> computersAmount >> edgesAmount;
//    vector <vector<Computer*> > edges;
//    vector <Computer*> computers;

//    for (int i = 0; i < computersAmount; ++i)
//    {
//        const OperationSystemType OSType = OperationSystemType(rand() % OperationSystem::operationSystemsAmount);
//        computers.push_back(new Computer(OSType));
//        vector <Computer*> computer;
//        edges.push_back(computer);
//    }

//    cout << "infection probability for each computer: " << endl;
//    for (int i = 0; i < computersAmount; ++i)
//        cout << computers[i]->operationSystem.infectionProbability << " ";
//    cout << endl;

//    cout << "input " << edgesAmount << " edges between computers: " << endl;
//    for (int i = 0; i < edgesAmount; ++i)
//    {
//        int from = 0;
//        int to = 0;
//        cin >> from >> to;
//        edges[from].push_back(computers[to]);
//        edges[to].push_back(computers[from]);
//    }

//    Net *net = new Net(computers, edges);
//    int virusIndex = rand() % computers.size();
//    cout << "Computer #" << virusIndex << " is a source of virus." << endl;
//    TestVirus *virus = new TestVirus(computers[virusIndex]);
//    int type = init;
//    while (type != haveExit)
//    {
//        operationsOutput();
//        cout << "Input operation type: ";
//        cin >> type;
//        switch (type)
//        {
//        case infect:
//        {
//            int infectedComputerIndex = virus->tryInfectComputer(net);
//            if (infectedComputerIndex == Virus::notInfected)
//                cout << "Failed to infect computer" << endl;
//            else
//                cout << "Computer #" << infectedComputerIndex << " was infected successfully" << endl;
//            break;
//        }
//        case getStatus:
//        {
//            cout << "Net status: " << endl;
//            for (int i = 0; i < int(net->computers.size()); ++i)
//            {
//                cout << "Computer #" << i << " ";
//                if (!net->computers[i]->wasInfected)
//                    cout << "un";
//                cout << "infected" << endl;
//            }
//            break;
//        }
//        }
//    }
//    computers.clear();
//    edges.clear();
//    delete net;
//    delete virus;
    return 0;
}

/*

4 4
0 2
0 3
1 2
1 3

*/


