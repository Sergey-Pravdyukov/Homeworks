#include <iostream>

using namespace std;

void depthFirstSearch(int vertex, int option, int used[], int numberOfStudents, bool matrixOfCheatings[][1000])
{
    used[vertex] = option;
    for (int to = 1; to <= numberOfStudents; ++to)
    {
        if (!used[to] && matrixOfCheatings[vertex][to])
        {
            depthFirstSearch(to, option, used, numberOfStudents, matrixOfCheatings);
        }
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    int numberOfStudents = 0;
    int numberOfCheatings = 0;
    const int maxSize = 1e3;
    bool matrixOfCheatings[maxSize][maxSize];
    int used[maxSize];
    cout << "Введите количество студентов: ";
    cin >> numberOfStudents;
    cout << "Введите количество списываний: ";
    cin >> numberOfCheatings;
    for (int i = 0; i < numberOfCheatings; ++i)
    {
        int to = 0;
        int from = 0;
        cout << "Введите номер списавшего студента: ";
        cin >> to;
        cout << to << "-й списал у ";
        cin >> from;
        matrixOfCheatings[from][to] = 1;
    }
    for (int i = 1; i <= numberOfStudents; ++i)
    {
        used[i] = 0;
    }
    used[1] = 1;
    used[2] = 2;
    used[3] = 3;
    int n = numberOfStudents;
    depthFirstSearch(1, 1, used, numberOfStudents, matrixOfCheatings);
    depthFirstSearch(2, 2, used, numberOfStudents, matrixOfCheatings);
    depthFirstSearch(3, 3, used, numberOfStudents, matrixOfCheatings);
    for (int i = 1; i <= numberOfStudents; ++i)
    {
        cout << i << "-й студент";
        (used[i]) ? cout << " сдал " << used[i] << "-й вариант" : cout << " не сделал домашнее задание";
        cout << endl;
    }
    return 0;
}
/*

7 3
4 1
6 5
5 3

*/
