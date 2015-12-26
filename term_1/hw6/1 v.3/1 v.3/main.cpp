#include <iostream>
#include "tree.h"

using namespace std;

void avaliableOperations()
{
	cout << "0 - выход" << endl
		<< "1 - добавить значение" << endl
		<< "2 - удалить значение" << endl
		<< "3 - проверить на прринадлежность" << endl
		<< "4 - вывести в возрастающем порядке" << endl
		<< "5 - вывести в убывающем порядке" << endl
		<< "6 - отладочный вывод" << endl;
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	Tree currentTree = { nullptr, 0 };
	int type = -1;
	while (type != 0)
	{
		avaliableOperations();
		cout << "Введите тип операции: ";
		cin >> type;
		enum { exit, add, remove, exists, ascending, descending, debug };
		switch (type)
		{
		case add:
		{
			int value = 0;
			cout << "Введите значение добавляемого элемента: ";
			cin >> value;
			addValue(&currentTree, value);
			break;
		}
		case remove:
		{
			int value = 0;
			cout << "Введите значение удаляемого элемента: ";
			cin >> value;
			TreeNode removedVertex = removeValue(&currentTree, value);
			break;
		}
		case exists:
		{
			int value = 0;
			cout << "Введите значение: ";
			cin >> value;
			cout << "Элемент " << value;
			bool result = isExists(&currentTree, value);
			(result) ? cout << " принадлежит " : cout << " не принадлежит ";
			cout << "множеству" << endl;
			break;
		}
		case ascending:
		{
			cout << "Элементы текущего множества в возрастающем порядке: ";
			printAscending(currentTree.root);
			cout << endl;
			break;
		}
		case descending:
		{
			cout << "Элементы текущего множества в убывающем порядке: ";
			printDescending(currentTree.root);
			cout << endl;
			break;
		}
		case debug:
		{
			cout << "Отладочный вывод: ";
			debugOutput(currentTree.root);
			cout << endl;
			break;
		}
		}
	}
	cout << "Конец выполнения операций.";
	return 0;
}
