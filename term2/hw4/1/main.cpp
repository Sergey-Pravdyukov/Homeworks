#include <iostream>
#include <QString>
#include <QTextStream>

#include "hash.h"
#include "hashtable.h"

using namespace std;

enum hash {hashInit,
           hashH37,
           hashFAQ6,
           hashLy};
enum operation {operationExit,
                operationAdd,
                operationRemove,
                operationFind,
                operationStatistics,
                operationChooseHash,
                operationDebugOutput,
                operationInit};
void chooseHash()
{
    cout << endl << "Avaliable hash functions: " << endl
         << hashH37 << " - H37" << endl
         << hashFAQ6 << " - FAQ6" << endl
         << hashLy << " - Ly" << endl;
}

void chooseTypeOfOperation()
{
    cout << endl << "Avaliable operatons: " << endl
         << operationAdd << " - add" << endl
         << operationRemove << " - remove" << endl
         << operationFind << " - find" << endl
         << operationStatistics << " - statistics" << endl
         << operationChooseHash << " - choose hash" << endl
         << operationDebugOutput << " - debug output" << endl
         << operationExit << " - exit" << endl;
}

int main()
{
    const QString stringInit = "";
    const int primeNumber = 13;

    int hashType = hashInit;
    int size = primeNumber;
    int typeOfOperation = operationInit;

    chooseHash();
    cout << "Choose one of avaliable hash functions: ";
    cin >> hashType;

    HashTable *currentHashTable = new HashTable(size, hashType);

    while (typeOfOperation != operationExit)
    {
        chooseTypeOfOperation();
        cin >> typeOfOperation;
        switch (typeOfOperation)
        {
        case operationAdd:
        {
            cout << endl << "Input string: ";
            QTextStream qtin(stdin);
            QString currentString = stringInit;
            qtin >> currentString;
            currentHashTable->add(currentString);
            cout << "Current element added." << endl;
            break;
        }
        case operationRemove:
        {
            cout << endl <<"Input string: ";
            QTextStream qtin(stdin);
            QString currentString = stringInit;
            qtin >> currentString;
            HashElement removedElement = currentHashTable->remove(currentString);
            cout << "Current element ";
            (removedElement.hash == hashInit) ? cout << "not found." << endl
                                              : cout << "removed." << endl;
            break;
        }
        case operationFind:
        {
            cout << endl << "Input string: ";
            QTextStream qtin(stdin);
            QString currentString = stringInit;
            qtin >> currentString;
            bool haveFound = currentHashTable->find(currentString);
            cout << "Current element have ";
            if (!haveFound)
                cout << "not ";
            cout << "found." << endl;
            break;
        }
        case operationStatistics:
        {
            cout << endl << "Statistics: " << endl;
            currentHashTable->haveStatisctics();
            break;
        }
        case operationChooseHash:
        {
            chooseHash();
            cin >> hashType;
            currentHashTable->changeHash(hashType);
            cout << endl << "Hash changed." << endl;
            break;
        }
        case operationDebugOutput:
        {
            cout << endl << "Hash table: " << endl;
            currentHashTable->debugOutput();
            break;
        }
        default:
        {
            break;
        }
        }
    }
    return 0;
}
