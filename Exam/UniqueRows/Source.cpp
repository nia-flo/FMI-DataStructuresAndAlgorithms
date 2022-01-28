#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;


int main() 
{
    int N, M;
    cin >> N >> M;

    map<string, int> occurancies;
    for (int i = 0; i < N; i++)
    {
        stringstream row;
        for (int i = 0; i < M; i++)
        {
            int input;
            cin >> input;

            row << input;
        }

        occurancies[row.str()]++;
    }

    int uniqueRowsCount = 0;
    for (map<string, int>::iterator it = occurancies.begin(); it != occurancies.end(); it++)
    {
        if ((*it).second == 1)
        {
            uniqueRowsCount++;
        }
    }

    cout << uniqueRowsCount << '\n';
    return 0;
}