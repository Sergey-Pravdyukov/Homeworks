#include <iostream>
#include <fstream>
#include <cstring>
#include "phonebook.h"

using namespace std;

void outputAvaliableOperations()
{
	cout << "0 - �����" << endl 
		<< "1 - �������� ������ (��� � �������)" << endl
		<< "2 - ����� ������� �� �����" << endl
		<< "3 - ����� ��� �� ��������" << endl
		<< "4 - ��������� ������� ������ � ����" << endl << endl;
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	ifstream in("phonebook.txt");
	const int maxSizeOfName = int(1e2);
	const int maxSizeOfNumber = int(2e1);
	char name[maxSizeOfName];
	char number[maxSizeOfNumber];
	Phonebook currentPhonebook = { nullptr, nullptr, 0 };
	Phonebook currentQueue = { nullptr, nullptr, 0 };
	while (!in.eof())
	{
		in >> name >> number;
		addToPhonebook(&currentPhonebook, name, number);
	}
	in.close();
	ofstream out("phonebook.txt");
	int type = -1;
	enum { exit, add, findByName, findByNumber, saveInFile };
	while (type != exit)
	{
		outputAvaliableOperations();
		cout << "������� ��� ��������: ";
		cin >> type;
		switch (type)
		{
			case add:
			{
				cout << "������� ��� � ����� ������ ��������: ";
				cin >> name >> number;
				addToPhonebook(&currentQueue, name, number);
				cout << "����� ������� ��������." << endl;
				break;
			}
			case findByName:
			{
				cout << "������� ��� ��������: ";
				cin >> name;
				haveOutput(&currentPhonebook);
				isFindByName(&currentPhonebook, name);
				break;
			}
			case findByNumber:
			{
				cout << "������� ����� ��������: ";
				cin >> number;
				isFindByNumber(&currentPhonebook, number);
				break;
			}
			case saveInFile:
			{
				save(&currentPhonebook, &currentQueue);
				cout << "��������� ���������." << endl;
				break;
			}
		}
	}
	return 0;
}
