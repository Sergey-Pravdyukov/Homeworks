#include <iostream>
#include <string>
#include <cstring>

using namespace std;

enum {firstBrackets, transitionFromFirstBrackets, secondBracketsWithoutDot, dotInSecondBrackets, lastLetter };

bool isLetter(char currentChar)
{
	return ('A' <= currentChar && currentChar <= 'Z');
}

bool isDigit(char currentChar)
{
	return ('0' <= currentChar && currentChar <= '9');
}

bool isFirstCheck(char currentChar)
{
	const int sizeOfDictionary = 5;
	const char dictionary[sizeOfDictionary] = { '.', '_', '%', '+', '-' };
	for (int i = 0; i < sizeOfDictionary; ++i)
	{
		if (isDigit(currentChar) || isLetter(currentChar) || dictionary[i] == currentChar)
		{
			return true;
		}
	}
	return false;
}

bool isSecondCheck(char currentChar)
{
	return (isDigit(currentChar) || currentChar == '-');
}

bool isFindExpression(char string[])
{
	int state = 0;
	for (int i = 0; i < int(strlen(string)); i++)
	{
		
		switch (state)
		{
			case firstBrackets:
			{
				if (isFirstCheck(string[i]))
				{
					state = transitionFromFirstBrackets;
				}
				else
				{
					return false;
				}
				break;
			}
			case transitionFromFirstBrackets:
			{
				if (isFirstCheck(string[i]))
				{
					state = transitionFromFirstBrackets;
				}
				else
				{
					if (string[i] == '@')
					{
						state = secondBracketsWithoutDot;
					}
					else
					{
						return false;
					}
				}
				break;
			}
			case secondBracketsWithoutDot:
			{
				if (isLetter(string[i]))
				{
					state = lastLetter;
				}
				else
				{
					if (isSecondCheck(string[i]))
					{
						state = dotInSecondBrackets;
					}
					else
					{
						return false;
					}
				}
				break;
			}
			case dotInSecondBrackets:
			{
				if (string[i] == '.')
				{
					state = secondBracketsWithoutDot;
				}
				else
				{
					return false;
				}
				break;
			}
			case lastLetter:
			{
				if (string[i] == '.')
				{
					state = secondBracketsWithoutDot;
				}
				else
				{
					return false;
				}
				break;
			}
		}
	}
	return (state == lastLetter);
}

void main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите строку: ";
	const int maxSize = 100;
	char string[maxSize];
	cin >> string;
	cout << "Данная строка ";
	if (isFindExpression(string))
	{
		cout << " не ";
	}
	cout << "корректна." << endl;
}