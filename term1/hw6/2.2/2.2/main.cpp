#include <iostream>
#include <locale>
#include "tree.h"
#include <cstdio>

using namespace std;

const int maxNumber = 300;

int main()
{
	setlocale(LC_ALL, "Rus");
	FILE *file = fopen("tree.txt", "r");
	if (file == nullptr)
	{
		cout << "Файл не найден" << endl;
		return 0;
	}
	Tree *tree = createTree();
	readTree(tree, file);
	fclose(file);
	printTree(tree);
	cout << endl;
	int calculation = calculateTree(tree);
	if (calculation == INT_MAX)
	{
		cout << "Деление на 0" << endl;
	}
	else
	{
		cout << "Результат вычисления обходом дерева: " << calculation << endl;
	}
	deleteTree(tree);
	return 0;
}