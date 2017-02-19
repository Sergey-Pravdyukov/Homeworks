#include <iostream>
#include <fstream>

using namespace std;

struct City
{
	int index;
	int lenght;
};

void isFindNearestUnvisitedVertex(int numberOfVerteces, int distance[],
	int &nearestUnvisitedVertex, bool used[],
	bool &isFindUnvisited, int &indexOfUnvisitedVertex)
{
	for (int i = 0; i < numberOfVerteces; ++i)
	{
		if (!used[i] && nearestUnvisitedVertex > distance[i])
		{
			isFindUnvisited = 1;
			indexOfUnvisitedVertex = i;
			nearestUnvisitedVertex = distance[i];
		}
	}
}

void haveRelax(int numberOfVerteces, bool used[], int indexOfUnvisitedVertex,
	int edge[][100], int nearestUnvisitedVertex, int distance[])
{
	used[indexOfUnvisitedVertex] = 1;
	for (int to = 0; to < numberOfVerteces; ++to)
	{
		if (edge[indexOfUnvisitedVertex][to] != 0 &&
			nearestUnvisitedVertex + edge[indexOfUnvisitedVertex][to] < distance[to])
		{
			distance[to] = nearestUnvisitedVertex + edge[indexOfUnvisitedVertex][to];
		}
	}
}

void dijkstra(int start, int finish, int edge[][100], int numberOfVerteces)
{
	const int maxSize = 100;
	const int infinity = 1e9;
	int distance[maxSize];
	for (int i = 0; i < maxSize; ++i)
	{
		distance[i] = infinity;
	}
	distance[start] = 0;
	bool isFindUnvisited = 1;
	bool used[maxSize];
	for (int i = 0; i < numberOfVerteces; ++i)
	{
		used[i] = 0;
	}
	City nearestCity[maxSize];
	int numberOfVisitedCities = 0;
	while (isFindUnvisited)
	{
		isFindUnvisited = 0;
		int nearestUnvisitedVertex = infinity;
		int indexOfUnvisitedVertex = infinity;
		isFindNearestUnvisitedVertex(numberOfVerteces, distance,
			nearestUnvisitedVertex, used,
			isFindUnvisited, indexOfUnvisitedVertex);
		if (isFindUnvisited)
		{
			nearestCity[numberOfVisitedCities++] = { indexOfUnvisitedVertex, distance[indexOfUnvisitedVertex] };
			haveRelax(numberOfVerteces, used, indexOfUnvisitedVertex, edge,
				nearestUnvisitedVertex, distance);
		}
	}
	cout << "Кратчайшее растояние между " << start + 1 << "-м и " << finish + 1
		<< "-м городом равно " << distance[finish] << endl;
	cout << "Города в порядке обхода: " << endl;
	for (int i = 0; i < numberOfVerteces; ++i)
	{
		cout << "Расстояние от 1-го до " << nearestCity[i].index + 1 << "-го города равно " << nearestCity[i].lenght << endl;
	}
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	int numberOfVerteces = 0;
	ifstream in("input.txt");
	in >> numberOfVerteces;
	const int maxSize = 100;
	const int infinity = 1e9;
	int edge[maxSize][maxSize];
	for (int i = 0; i < numberOfVerteces; ++i)
	{
		for (int j = 0; j < numberOfVerteces; ++j)
		{
			edge[i][j] = infinity;
		}
	}
	int numbersOfEdges = 0;
	in >> numbersOfEdges;
	for (int i = 0; i < numbersOfEdges; ++i)
	{
		int from = 0;
		int to = 0;
		int length = 0;
		in >> from >> to >> length;
		edge[from - 1][to - 1] = length;
		edge[to - 1][from - 1] = length;
	}
	int finish = 0;
	in >> finish;
	in.close();
	--finish;
	int start = 0;
	dijkstra(start, finish, edge, numberOfVerteces);
	return 0;
}

/*

6
8
1 4 7
2 3 5
3 5 4
1 5 6
4 6 7
3 6 2
2 4 8
1 3 3
4

*/