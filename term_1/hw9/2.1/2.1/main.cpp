#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void input(char firstString[], char secondString[])
{
	ifstream in("input.txt");
	in >> firstString;
	in >> secondString;
	in.close();
}

void calculatePrimePower(unsigned long long primeNumberInPower[], char firstString[])
{
	const int primeNumber = 37;
	primeNumberInPower[0] = 1;
	for (int i = 1; i < strlen(firstString); ++i)
	{
		primeNumberInPower[i] = primeNumberInPower[i - 1] * primeNumber;
	}
}

void haveHashOfFirstString(unsigned long long hashOfFirstString[], 
	unsigned long long primeNumberInPower[], char firstString[])
{
	hashOfFirstString[0] = 0;
	for (int i = 0; i <= strlen(firstString); ++i)
	{
		hashOfFirstString[i] = primeNumberInPower[i] * firstString[i];
		if (i)
		{
			hashOfFirstString[i] += hashOfFirstString[i - 1];
		}
	}
}

void haveHashOfSecondString(unsigned long long &hashOfSecondString,
	unsigned long long primeNumberInPower[], char secondString[])
{
	for (int i = 0; i < strlen(secondString); ++i)
	{
		hashOfSecondString += primeNumberInPower[i] * secondString[i];
	}
}

bool isFindSubstring(char firstString[], char secondString[], unsigned long long hashOfFirstString[],
	unsigned long long hashOfSecondString, unsigned long long primeNumberInPower[])
{
	bool result = false;
	for (int i = 0; i + strlen(secondString) - 1 < strlen(firstString); ++i)
	{
		unsigned long long currentHash = hashOfFirstString[i + int(strlen(secondString)) - 1];
		if (i)
		{
			currentHash -= hashOfFirstString[i - 1];
		}
		if (currentHash == hashOfSecondString * primeNumberInPower[i])
		{
			if (result == false)
			{
				cout << "—трока " << secondString << " €вл€етс€ подстрокой строки " << firstString << " в позици€х ";
			}
			result = true;
			cout << i + 1 << " ";
		}
	}
	return result;
}

void output(char currentString[])
{
	for (int i = 0; i < strlen(currentString); ++i)
	{
		cout << currentString[i];
	}
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	const int maxSize = 1e2;
	char firstString[maxSize];
	char secondString[maxSize];
	input(firstString, secondString);
	unsigned long long primeNumberInPower[maxSize];
	calculatePrimePower(primeNumberInPower, firstString);
	unsigned long long hashOfFirstString[maxSize];
	haveHashOfFirstString(hashOfFirstString, primeNumberInPower, firstString);
	unsigned long long hashOfSecondString = 0;
	haveHashOfSecondString(hashOfSecondString, primeNumberInPower, secondString);
	if (!isFindSubstring(firstString, secondString, hashOfFirstString, hashOfSecondString, primeNumberInPower))
	{
		cout << "—трока " << secondString << " не €вл€етс€ подстрокой строки " << firstString;
	}
	cout << endl;
	return 0;
}