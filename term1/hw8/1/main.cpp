#include <iostream>
#include <cstdio>

using namespace std;

void depthFirstSearch(int currentVertex, char alphabet[], bool edge[][26], int numberOfVertices, int &counter)
{
    alphabet[currentVertex] = char(counter + 'A');
    counter++;
    for (int to = 0; to < numberOfVertices; ++to)
    {
        if (edge[currentVertex][to] && alphabet[to] == '?')
        {
            depthFirstSearch(to, alphabet, edge, numberOfVertices, counter);
        }
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    freopen("input.txt", "r", stdin);
    const int maxSize = 26;
    int numberOfVertices = 0;
    int start = 0;
    int counter = 0;
    char alphabet[maxSize];
    bool edge[maxSize][maxSize];
    cin >> numberOfVertices >> start;
    --start;
    for (int from = 0; from < numberOfVertices; ++from)
    {
        for (int to = 0; to < numberOfVertices; ++to)
        {
            cin >> edge[from][to];
        }
    }
    for (int i = 0; i < numberOfVertices; ++i)
    {
        alphabet[i] = '?';
    }
    depthFirstSearch(start, alphabet, edge, numberOfVertices, counter);
    for (int i = 0; i < numberOfVertices; ++i)
    {
        cout << i + 1 << "-я вершина: " << alphabet[i] << endl;
    }
    return 0;
}
