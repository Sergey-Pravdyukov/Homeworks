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
		cout << "0 - выход" << endl 
			<< "1 - создать строку" << endl
			<< "2 - удалить строку" << endl
			<< "3 - копировать строку" << endl
			<< "4 - добавить строку" << endl
			<< "5 - сравнить строки" << endl
			<< "6 - вычислить длину строки" << endl
			<< "7 - проверка на путстоту" << endl
			<< "8 - выделение подстроки" << endl
			<< "9 - преобразование к char*" << endl;
		cout << "Введите номер операции: ";
		cin >> type;
		switch (type)
		{
			case create:
			{
				cout << "Введите строку: ";
				input(&currentString);
				cout << "Строка создана." << endl << endl;
				break;
			}
			case remove:
			{
				deleteString(&currentString);
				cout << "Строка удалена." << endl << endl;
				break;
			}
			case copy:
			{
				String cloneString = clone(&currentString, 0, sizeOfString(&currentString));
				cout << "Строка скопирована." << endl << endl;
				break;
			}
			case addString:
			{
				cout << "Введите строку: ";
				input(&currentString);
				cout << "Строка добавлена" << endl << endl;
				break;
			}
			case compare:
			{
				cout << "Введите строку: ";
				bool equalStrings = isEqual(&currentString);
				cout << "Введенная строка ";
				if (!equalStrings)
				{
					cout << "не ";
				}
				cout << "равна данной" << endl << endl;
				break;
			}
			case lenght:
			{
				cout << "Длина текущей строки: " << sizeOfString(&currentString) << endl << endl;
				break;
			}
			case empty:
			{
				cout << "Текущая строка ";
				if (isEmpty(&currentString))
				{
					cout << "не ";
				}
				cout << "пустая." << endl << endl;
				break;
			}
			case substring:
			{
				if (!isEmpty(&currentString))
				{
					cout << "Выделение подстроки невозможно." << endl << endl;
					break;
				}
				cout << "Введите два числа в диапазоне от 1 до " << sizeOfString(&currentString) << ": ";
				int left = 0;
				int right = 0;
				cin >> left >> right;
				String newString = clone(&currentString, left - 1, right - 1);
				cout << "Подстрока с " << left << "-го по " << right << "-й символ: ";
				cout << endl << endl;
				debugOutput(&currentString);
				break;
			}
			case convert:
			{
				char* convertedString = transformation(&currentString);
				cout << "Строка преобразована к char*." << endl << endl;
				break;
			}
		}
	}
	cout << "Конец работы.";
	return 0;
}