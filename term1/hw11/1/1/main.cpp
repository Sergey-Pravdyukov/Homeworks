#include <iostream>

using namespace std;

bool isRealNumber(char number[])
{
	int state = 0;
	for (int i = 0; i < strlen(number); ++i)
	{
		switch (state)
		{
			case 0:
			{
				if (isdigit(number[i]))
				{
					state = 1;
				}
				else
				{
					return false;
				}
				break;
			}
			case 1:
			{
				if (isdigit(number[i]))
				{
					state = 1;
				}
				else
				{
					if (number[i] == '.')
					{
						state = 2;
					}
					else
					{
						return false;
					}
				}
				break;
			}
			case 2:
			{
				if (isdigit(number[i]))
				{
					state = 3;
				}
				else
				{
					return false;
				}
				break;
			}
			case 3:
			{
				if (isdigit(number[i]))
				{
					state = 3;
				}
				else
				{
					if (number[i] == 'E')
					{
						state = 4;
					}
					else
					{
						return false;
					}
				}
				break;
			}
			case 4:
			{
				if (number[i] == '-' || number[i] == '+')
				{
					state = 5;
				}
				else
				{
					if (isdigit(number[i]))
					{
						state = 6;
					}
					else
					{
						return false;
					}
				}
				break;
			}
			case 5:
			{
				if (isdigit(number[i]))
				{
					state = 6;
				}
				else
				{
					return false;
				}
				break;
			}
			case 6:
			{
				if (isdigit(number[i]))
				{
					state = 6;
				}
				else
				{
					return false;
				}
			}
		}
	}
	return (!(state == 2) && !(state == 4) && !(state == 5));
}

int main()
{
	setlocale(LC_ALL, "Rus");
	const int maxSize = int(1e2);
	char number[maxSize];
	cout << "Введите число: ";
	cin >> number;
	(isRealNumber(number)) ? cout << "К" : cout << "Нек";
	cout << "орректная запись вещественного числа" << endl;
	return 0;
}