#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool isCorrectDate(char date[])
{
    const int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = 0;
    int month = 0;
    int year = 0;
    if (date[0] != ' ')
    {
        return 0;
    }
    int power = 1;
    for (int i = 2; i >= 1; --i)
    {
        if ('0' <= date[i] && date[i] <= '9')
        {
            day += int(date[i] - '0') * power;
            power *= 10;
        }
        else
        {
            return 0;
        }
    }
    power = 1;
    if (date[3] != '.' || date[6] != '.')
    {
        return 0;
    }
    for (int i = 5; i >= 4; --i)
    {
        if ('0' <= date[i] && date[i] <= '9')
        {
            month += int(date[i] - '0') * power;
            power *= 10;
        }
        else
        {
            return 0;
        }
    }
    for (int i = 10; i >= 7; --i)
    {
        if ('0' <= date[i] && date[i] <= '9')
        {
            year = year * 10 + int(date[i] - '0');
        }
        else
        {
            return 0;
        }
    }
    if (date[11] != ' ')
    {
        return 0;
    }

    if (day <= months[month])
    {
        //cout << "month " << month << endl;
        return 1;
    }
    return 0;
}

void minimum(char result[], char date[])
{
    const int size = 12;
    int currentMinimum = 0;
    int current = 0;
    int power = 1;
    for (int i = 10; i >= 7; --i)
    {
        current += int(date[i] - '0') * power;
        currentMinimum += int(result[i] - '0') * power;
        power *= 10;
    }
    //cout << current << " " << currentMinimum << endl;
    power = 1;
    if (current < currentMinimum)
    {
        for (int i = 0; i < size; ++i) result[i] = date[i];
        return;
    }
    if (currentMinimum < current)
    {
        return;
    }
    current = 0;
    currentMinimum = 0;
    for (int i = 5; i >= 4; --i)
    {
        current += int(date[i] - '0') * power;
        currentMinimum += int(result[i] - '0') * power;
        power *= 10;
    }
    //cout << current << " " << currentMinimum << endl;
    if (current < currentMinimum)
    {
        for (int i = 0; i < size; ++i) result[i] = date[i];
        return;
    }
    if (currentMinimum < current)
    {
        return;
    }
    current = 0;
    currentMinimum = 0;
    power = 1;
    for (int i = 2; i >= 1; --i)
    {
        current += int(date[i] - '0') * power;
        currentMinimum += int(result[i] - '0') * power;
        power *= 10;
    }
    //cout << current << " " << currentMinimum << endl;
    if (current < currentMinimum)
    {
        for (int i = 0; i < size; ++i) result[i] = date[i];
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    freopen("in.txt", "r", stdin);
    const int size = 12;
    char date[size];
    char result[size] = {' ', '9', '9', '.', '9', '9', '.', '9', '9', '9', '9', ' '};
    for (int i = 0; i < size; ++i)
    {
        date[i] = '?';
    }
    char currentChar = '?';
    while ((currentChar = getc(stdin)) != EOF)
    {
        for (int i = 0; i < size - 1; ++i) date[i] = date[i + 1];
        date[size - 1] = currentChar;
        if (isCorrectDate(date))
        {
            //for (int j = 0; j < size; ++j) cout << date[j] << " ";
            //cout << endl;
            minimum(result, date);
        }
    }
    if (result[1] == '9')
    {
        cout << "В данном тексте нет корректных дат.";
    }
    else
    {
        cout << "Наименьшая дата: ";
        for (int i = 0; i < size; ++i)
        {
            cout << result[i];
        }
    }
    return 0;
}
