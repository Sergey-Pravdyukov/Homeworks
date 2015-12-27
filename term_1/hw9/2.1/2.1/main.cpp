#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

struct String
{
	char *data;
	int size;
};

String createString(int size, int capacity)
{
	String newString = { nullptr, size };
	return newString;
}

void input(String &currentString)
{
	const int capacity = int(1e3);
	char *newString = new char[capacity];
	cin.getline(newString, capacity);
	currentString.size = strlen(newString);
	currentString.data = newString;
}

void calculatePrimePower(unsigned long long primeNumberInPower[], String firstString)
{
	const int primeNumber = 37;
	primeNumberInPower[0] = 1;
	for (int i = 1; i < firstString.size; ++i)
	{
		primeNumberInPower[i] = primeNumberInPower[i - 1] * primeNumber;
	}
}

void haveHashOfFirstString(unsigned long long hashOfFirstString[],
	unsigned long long primeNumberInPower[], String firstString)
{
	hashOfFirstString[0] = 0;
	for (int i = 0; i <= firstString.size; ++i)
	{
		hashOfFirstString[i] = primeNumberInPower[i] * firstString.data[i];
		if (i)
		{
			hashOfFirstString[i] += hashOfFirstString[i - 1];
		}
	}
}

void haveHashOfSecondString(unsigned long long &hashOfSecondString,
	unsigned long long primeNumberInPower[], String secondString)
{
	for (int i = 0; i < secondString.size; ++i)
	{
		hashOfSecondString += primeNumberInPower[i] * secondString.data[i];
	}
}

void debugOutput(String currentString)
{
	for (int i = 0; i < currentString.size; ++i)
	{
		cout << currentString.data[i];
	}
}

bool isFindSubstring(String firstString, String secondString, unsigned long long hashOfFirstString[],
	unsigned long long hashOfSecondString, unsigned long long primeNumberInPower[])
{
	bool result = false;
	for (int i = 0; i + secondString.size - 1 < firstString.size; ++i)
	{
		unsigned long long currentHash = hashOfFirstString[i + secondString.size - 1];
		if (i)
		{
			currentHash -= hashOfFirstString[i - 1];
		}
		if (currentHash == hashOfSecondString * primeNumberInPower[i])
		{
			if (result == false)
			{
				cout << "Строка ";
				debugOutput(secondString);
				cout << " является подстрокой строки ";
				debugOutput(firstString);
				cout << " в позициях ";
			}
			result = true;
			cout << i + 1 << " ";
		}
	}
	return result;
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	const int size = 0;
	const int capacity = int(1e3);
	String firstString = createString(size, capacity);
	String secondString = createString(size, capacity);
	cout << "Введите строку: ";
	input(firstString);
	cout << "Введите подстроку: ";
	input(secondString);
	unsigned long long primeNumberInPower[capacity];
	calculatePrimePower(primeNumberInPower, firstString);
	unsigned long long hashOfFirstString[capacity];
	haveHashOfFirstString(hashOfFirstString, primeNumberInPower, firstString);
	unsigned long long hashOfSecondString = 0;
	haveHashOfSecondString(hashOfSecondString, primeNumberInPower, secondString);
	if (!isFindSubstring(firstString, secondString, hashOfFirstString, hashOfSecondString, primeNumberInPower))
	{
		cout << "Строка ";
		debugOutput(secondString);
		cout << " не является подстрокой строки ";
		debugOutput(firstString);
	}
	cout << endl;
	return 0;
}
/*
asdasdffsdfgdhfghjfjhgkjgkfjgdhghasdasdffsdfgdhfghjfjhgkjgkfjgdhghasdasdffsdfgdhfghjfjhgkjgkfjgdhghasdasdffsdfgdhfghjfjhgkjgkfjgdhghasdasdffsdfgdhfghjfjhgkjgkfjgdhghasdasdffsdfgdhfghjfjhgkjgkfjgdhghasdasdffsdfgdhfghjfjhgkjgkfjgdhghasdasdffsdfgdhfghjfjhgkjgkfjgdhghasdasdffsdfgdhfghjfjhgkjgkfjgdhghasdasdffsdfgdhfghjfjhgkjgkfjgdhgh
asdasdffsdfgdhfghjfjhgkjgkfjgdhgh
*/