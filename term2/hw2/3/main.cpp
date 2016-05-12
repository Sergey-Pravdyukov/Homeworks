#include <iostream>

#include "list.h"
#include "listoflists.h"
#include "listcomparator.h"

using namespace std;

enum
{
    haveExit,
    haveAddList,
    haveOutputListOfLists,
    haveCompare,
    init
};
enum
{
    notFound,
    isEqual,
    firstLess,
    secondLess
};

void operations()
{
    cout << endl << haveExit << " - exit" << endl
         << haveAddList << " - add List" << endl
         << haveOutputListOfLists << " - output list of lists" << endl;
}

int main()
{
    int typeOfOperation = init;
    ListOfLists *currentListOfLists = new ListOfLists();
    while (typeOfOperation != haveExit)
    {
        operations();
        cout << endl << "Input type of operation: ";
        cin >> typeOfOperation;       
        switch(typeOfOperation)
        {
        case haveAddList:
        {
            cout << endl << "Input size of list: ";
            const int sizeInit = 0;
            int currentSize = sizeInit;
            cin >> currentSize;
            cout << endl << "Input list: ";
            const int valueInit = 0;
            int value = valueInit;
            List *currentList = new List();
            for (int i = 0; i < currentSize; ++i)
            {
                cin >> value;
                currentList->add(value);
            }
            currentListOfLists->add(currentList);
            break;
        }
        case haveOutputListOfLists:
        {
            cout << endl << "Output all added lists: " << endl;
            currentListOfLists->debugOutput();
            break;
        }
        }
    }
    delete currentListOfLists;
    cout << "End." << endl;
    return 0;
}
