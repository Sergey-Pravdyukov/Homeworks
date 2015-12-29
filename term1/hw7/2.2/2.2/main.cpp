#include <iostream>
#include "string.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");
	const int capacity = int(1e3);
	const int size = 0;
	String currentString = createString(size, capacity);
	enum {exit ,create, remove, copy, addString, compare, lenght, empty, substring, convert, init};
	int type = init;
	while (type != exit)
	{
		cout << "0 - �����" << endl 
			<< "1 - ������� ������" << endl
			<< "2 - ������� ������" << endl
			<< "3 - ���������� ������" << endl
			<< "4 - �������� ������" << endl
			<< "5 - �������� ������" << endl
			<< "6 - ��������� ����� ������" << endl
			<< "7 - �������� �� ��������" << endl
			<< "8 - ��������� ���������" << endl
			<< "9 - �������������� � char*" << endl;
		cout << "������� ����� ��������: ";
		cin >> type;
		switch (type)
		{
			case create:
			{
				cout << "������� ������: ";
				input(&currentString);
				cout << "������ �������." << endl << endl;
				break;
			}
			case remove:
			{
				deleteString(&currentString);
				cout << "������ �������." << endl << endl;
				break;
			}
			case copy:
			{
				String cloneString = clone(&currentString, 0, sizeOfString(&currentString));
				cout << "������ �����������." << endl << endl;
				break;
			}
			case addString:
			{
				cout << "������� ������: ";
				input(&currentString);
				cout << "������ ���������" << endl << endl;
				break;
			}
			case compare:
			{
				cout << "������� ������: ";
				bool equalStrings = isEqual(&currentString);
				cout << "��������� ������ ";
				if (!equalStrings)
				{
					cout << "�� ";
				}
				cout << "����� ������" << endl << endl;
				break;
			}
			case lenght:
			{
				cout << "����� ������� ������: " << sizeOfString(&currentString) << endl << endl;
				break;
			}
			case empty:
			{
				cout << "������� ������ ";
				if (isEmpty(&currentString))
				{
					cout << "�� ";
				}
				cout << "������." << endl << endl;
				break;
			}
			case substring:
			{
				if (!isEmpty(&currentString))
				{
					cout << "��������� ��������� ����������." << endl << endl;
					break;
				}
				cout << "������� ��� ����� � ��������� �� 1 �� " << sizeOfString(&currentString) << ": ";
				int left = 0;
				int right = 0;
				cin >> left >> right;
				String newString = clone(&currentString, left - 1, right - 1);
				cout << "��������� � " << left << "-�� �� " << right << "-� ������: ";
				cout << endl << endl;
				debugOutput(&currentString);
				break;
			}
			case convert:
			{
				char* convertedString = transformation(&currentString);
				cout << "������ ������������� � char*." << endl << endl;
				break;
			}
		}
	}
	cout << "����� ������.";
	return 0;
}