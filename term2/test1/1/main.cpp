#include <iostream>

#include "queue.h"

using namespace std;

const int init = -1;

enum {isExit, isEnqueue, isDequeue};

void outputAvaliableOperations()
{
    cout << "Input one of this operation: " << endl
         << isExit << " - exit" << endl
         << isEnqueue << " - enqueue" << endl
         << isDequeue << " - dequeue" << endl;
}

int main()
{
    int typeOfOperation = init;
    Queue<int> *currentQueue = new Queue<int>();
    while (typeOfOperation != isExit)
    {
        outputAvaliableOperations();
        cin >> typeOfOperation;
        switch (typeOfOperation)
        {
        case isEnqueue:
        {
            cout << "Input added value: ";
            int value = init;
            cin >> value;
            currentQueue->enqueue(value);
            break;
        }
        case isDequeue:
        {
            Queue<int>::QueueElement removedElement = currentQueue->degueue();
            cout << "Value: " << removedElement.value << endl
                 << "Key: " << removedElement.key << endl << endl;
            break;
        }
        }
    }
    return 0;
}
