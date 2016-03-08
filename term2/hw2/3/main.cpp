#include <iostream>

#include "list.h"
#include "listoflists.h"

using namespace std;

enum {haveExit, haveAddList, haveOutputListOfLists};
const int init = -1;

void operations()
{
    cout << endl << haveExit << " - exit" << endl <<
            haveAddList << " - add List" << endl <<
            haveOutputListOfLists << " - output list of lists" << endl;
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
            int currentSize = init;
            cin >> currentSize;
            cout << endl << "Input list: ";
            int value = init;
            List currentList = List();
            for (int i = 0; i < currentSize; ++i)
            {
                cin >> value;
                currentList.add(value);
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
    return 0;
}
