#include <iostream>

#include "list.h"
#include "listoflists.h"
#include "listcomparator.h"

using namespace std;

enum {haveExit, haveAddList, haveOutputListOfLists, haveCompare};
enum {notFound, isEqual, firstLess, secondLess};
const int init = -1;

void operations()
{
    cout << endl << haveExit << " - exit" << endl <<
            haveAddList << " - add List" << endl <<
            haveOutputListOfLists << " - output list of lists" << endl <<
            haveCompare << " - compare two lists" << endl;
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
        case haveCompare:
        {
            cout << endl << "Input size of first list: ";
            int firstSize = init;
            cin >> firstSize;
            cout << endl << "Input list: ";
            int value = init;
            List firstList = List();
            for (int i = 0; i < firstSize; ++i)
            {
                cin >> value;
                firstList.add(value);
            }
            cout << endl << "Input size of second list: ";
            int secondSize = init;
            cin >> secondSize;
            cout << endl << "Input list: ";
            List secondList = List();
            for (int i = 0; i < secondSize; ++i)
            {
                cin >> value;
                secondList.add(value);
            }
            int result = ListComparator::haveCompareLists(&firstList, &secondList, currentListOfLists);
            switch (result) {
            case notFound:
            {
                cout << "Any list not exists" << endl;
                break;
            }
            case isEqual:
            {
                cout << "Sizes of lists are equal" << endl;
                break;
            }
            case firstLess:
            {
                cout << "Size of the first list less than the second" << endl;
                break;
            }
            default:
                cout << "Size of the second list less than the first" << endl;
                break;
            }
            break;
        }
        }
    }
    return 0;
}
