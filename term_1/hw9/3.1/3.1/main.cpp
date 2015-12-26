#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int haveFindMinimumEdge(int numberOfVerteces, bool used[], int minimumEdge[])
{
    int vertex = -1;
	for (int i = 0; i < numberOfVerteces; ++i)
	{
		if (!used[i] && (vertex == -1 || minimumEdge[i] < minimumEdge[vertex]))
        {
            vertex = i;
        }
    }
    return vertex;
}

void relax(int numberOfVerteces, int edge[][100], int minimumEdge[],
           int indexOfVertexFrom[], int vertex, bool used[])
{
    for (int to = 0; to < numberOfVerteces; ++to)
    {
        if (edge[vertex][to] && edge[vertex][to] < minimumEdge[to] && !used[to])
        {
            minimumEdge[to] = edge[vertex][to];
            indexOfVertexFrom[to] = vertex;
        }
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
	ifstream in("input.txt");
    const int maxSize = int(1e2);
    int infinity = int(1e9);
    int numberOfVerteces = 0;
    in >> numberOfVerteces;
    int edge[maxSize][maxSize];
    bool used[maxSize];
	for (int i = 0; i < numberOfVerteces; ++i)
	{
		used[i] = 0;
	}
    for (int from = 0; from < numberOfVerteces; ++from)
    {
        for (int to = 0; to < numberOfVerteces; ++to)
        {
            in >> edge[from][to];
        }
    }
    int minimumEdge[maxSize];
    int indexOfVertexFrom[maxSize];
    for (int i = 0; i < numberOfVerteces; ++i)
    {
        minimumEdge[i] = infinity;
        indexOfVertexFrom[i] = -1;
    }
    minimumEdge[0] = 0;
    int numberOfEdges = 0;
    for (int i = 0; i < numberOfVerteces; ++i)
    {
        int vertex = haveFindMinimumEdge(numberOfVerteces, used, minimumEdge);
        if (minimumEdge[vertex] == infinity)
        {
            cout << "������������ ����.";
            return 0;
        }
        used[vertex] = 1;
        relax (numberOfVerteces, edge, minimumEdge, indexOfVertexFrom, vertex, used);
    }
    int sumOfEdges = 0;
    for (int vertex = 0; vertex < numberOfVerteces; ++vertex)
    {
        sumOfEdges += minimumEdge[vertex];
    }
    cout << "��� ������ ����� ���������� ����������� �c��� ���� " << sumOfEdges << endl;
    return 0;
}

/*

5
0 6 7 0 4
6 0 3 6 2
7 3 0 9 8
0 6 9 0 11
4 2 8 11 0

5
2 3 4 1 5
2 3 1 4 5
2 3 4 5 1
2 1 3 4 5
2 3 4 5 6

*/