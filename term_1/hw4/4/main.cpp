#include <iostream>
#include "sortedList.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    int type = -1;
    const int infinity = int(1e9);
    List currentList = {nullptr, nullptr, 0};
    add(&currentList, infinity);
    add(&currentList, -infinity);
    output(&currentList);
    enum {exit, addValue, removeValue, outputList};
    while (type != exit)
    {
        cout << "Введите вид операции: ";
        cin >> type;
        int value = 0;
        switch (type)
        {
            case exit:
            {
                cout << "Конец работы." << endl;
                break;
            }
            case addValue:
            {
                cout << "Введите значение добавляемого элемента: ";
                cin >> value;
                add(&currentList, value);
                break;
            }
            case removeValue:
            {
                cout << "Введите значение удаляемого элемента: ";
                cin >> value;
                remove(&currentList, value);
                break;
            }
            case outputList:
            {
                cout << "Сортированный список: ";
                output(&currentList);
                cout << endl;
                break;
            }
        }
    }
    return 0;
}
