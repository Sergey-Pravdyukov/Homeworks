#include <iostream>
#include "tree.h"

using namespace std;

void avaliableOperations()
{
	cout << "0 - �����" << endl
		<< "1 - �������� ��������" << endl
		<< "2 - ������� ��������" << endl
		<< "3 - ��������� �� ���������������" << endl
		<< "4 - ������� � ������������ �������" << endl
		<< "5 - ������� � ��������� �������" << endl
		<< "6 - ���������� �����" << endl;
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	Tree currentTree = { nullptr, 0 };
	int type = -1;
	while (type != 0)
	{
		avaliableOperations();
		cout << "������� ��� ��������: ";
		cin >> type;
		enum { exit, add, remove, exists, ascending, descending, debug };
		switch (type)
		{
		case add:
		{
			int value = 0;
			cout << "������� �������� ������������ ��������: ";
			cin >> value;
			addValue(&currentTree, value);
			break;
		}
		case remove:
		{
			int value = 0;
			cout << "������� �������� ���������� ��������: ";
			cin >> value;
			TreeNode removedVertex = removeValue(&currentTree, value);
			break;
		}
		case exists:
		{
			int value = 0;
			cout << "������� ��������: ";
			cin >> value;
			cout << "������� " << value;
			bool result = isExists(&currentTree, value);
			(result) ? cout << " ����������� " : cout << " �� ����������� ";
			cout << "���������" << endl;
			break;
		}
		case ascending:
		{
			cout << "�������� �������� ��������� � ������������ �������: ";
			printAscending(currentTree.root);
			cout << endl;
			break;
		}
		case descending:
		{
			cout << "�������� �������� ��������� � ��������� �������: ";
			printDescending(currentTree.root);
			cout << endl;
			break;
		}
		case debug:
		{
			cout << "���������� �����: ";
			debugOutput(currentTree.root);
			cout << endl;
			break;
		}
		}
	}
	cout << "����� ���������� ��������.";
	return 0;
}
