#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> keys(N);
    for (int i = 0; i < N; i++)
    {
        cin >> keys[i];
    }

    vector<int> doors(N);
    for (int i = 0; i < N; i++)
    {
        cin >> doors[i];
    }

    map<int, int> foundKeysCount;
    int brokenDoorsCount = 0;
    for (int i = 0; i < N; i++)
    {
        foundKeysCount[keys[i]]++;

        if (foundKeysCount[doors[i]] == 0)
        {
            brokenDoorsCount++;
        }
        else
        {
            foundKeysCount[doors[i]]--;;
        }
    }

    cout << brokenDoorsCount << '\n';

    return 0;
}