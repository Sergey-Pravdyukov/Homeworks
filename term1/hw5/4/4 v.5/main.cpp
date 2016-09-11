#include <iostream>
#include <fstream>
#include <cstring>
#include "phonebook.h"

using namespace std;

void outputAvaliableOperations()
{
	cout << "0 - выйти" << endl 
		<< "1 - добавить запись (имя и телефон)" << endl
		<< "2 - найти телефон по имени" << endl
		<< "3 - найти имя по телефону" << endl
		<< "4 - сохранить текущие данные в файл" << endl << endl;
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
		cout << "Введите тип операции: ";
		cin >> type;
		switch (type)
		{
			case add:
			{
				cout << "Введите имя и номер нового контакта: ";
				cin >> name >> number;
				addToPhonebook(&currentQueue, name, number);
				cout << "Новый контакт добавлен." << endl;
				break;
			}
			case findByName:
			{
				cout << "Введите имя контакта: ";
				cin >> name;
				haveOutput(&currentPhonebook);
				isFindByName(&currentPhonebook, name);
				break;
			}
			case findByNumber:
			{
				cout << "Введите номер контакта: ";
				cin >> number;
				isFindByNumber(&currentPhonebook, number);
				break;
			}
			case saveInFile:
			{
				save(&currentPhonebook, &currentQueue);
				cout << "Изменения сохранены." << endl;
				break;
			}
		}
	}
	return 0;
}
