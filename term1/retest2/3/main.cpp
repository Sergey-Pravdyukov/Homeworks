#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct Member
{
    int loyal;
    char* sirname;
};

int main()
{
    setlocale(LC_CTYPE, "rus");
    freopen("input.txt", "r", stdin);
    int k = 0;
    cin >> k;
    int loyal = 0;
    const int maxSize = 1e2;
    char sirname[maxSize];
    char space = '?';
    char charMinus = '?';
    Member person[maxSize];
    for (int i = 0; i < k; ++i)
    {
        cin >> loyal >> space >> charMinus >> space >> sirname;
        cout << sirname << endl;
        person[i].loyal = loyal;
        for (int j = 0; j < strlen(sirname); ++j)
        {
            person[i].sirname[j] = sirname[j];
            cout << sirname[j] << " " << person[i].sirname[j] << endl;
        }
    }
    for (int i = 0; i < k; ++i)
    {
        cout << person[i].loyal << " ";
        for (int j = 0; j < strlen(person[i].sirname); ++j)
        {
            cout << person[i].sirname[j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

6
1 - sdkfjslfj
3 - kjsdf
5 - fkjf
2 - sdfkjsf
4 - dfjs
3 - dfopipi

*/
