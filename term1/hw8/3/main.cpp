#include <iostream>

using namespace std;

void depthFirstSearch(int currentVertex, bool used[], bool edge[][100], int numberOfVertices)
{
    used[currentVertex] = 1;
    cout << currentVertex + 1 << " ";
    for (int to = 0; to < numberOfVertices; ++to)
    {
        if (!used[to] && edge[currentVertex][to])
        {
            depthFirstSearch(to, used, edge, numberOfVertices);
        }
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "������� ���������� ������: ";
    int numberOfVertices = 0;
    cin >> numberOfVertices;
    cout << "������� ������� ��������� �����: " << endl;
    const int maxSize = 1e2;
    bool used[maxSize];
    bool edge[maxSize][maxSize];
    for (int from = 0; from < numberOfVertices; ++from)
    {
        for (int to = 0; to < numberOfVertices; ++to)
        {
            cin >> edge[from][to];
        }
    }
    int counter = 0;
    for (int i = 0; i < numberOfVertices; ++i)
    {
        if (!used[i])
        {
            cout << "� " << ++counter << "-� ���������� ��������� �������: ";
            depthFirstSearch(i, used, edge, numberOfVertices);
            cout << endl;
        }
    }
    return 0;
}
