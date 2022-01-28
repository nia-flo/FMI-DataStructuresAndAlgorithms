#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solve(int node, map<int, vector<int>>& neighbours, map<int, int>& results)
{
    if (results.find(node) != results.end())
    {
        return results[node];
    }

    results[node] = 0;
    for (int i = 0; i < neighbours[node].size(); i++)
    {
        results[node] += solve(neighbours[node][i], neighbours, results) + neighbours[node][i];
    }

    return results[node];
}

int main() 
{
    int edgesCount, queriesCount;
    cin >> edgesCount >> queriesCount;

    map<int, vector<int>> neighbours;
    for (int i = 0; i < edgesCount; i++)
    {
        int from, to;
        cin >> from >> to;

        neighbours[from].push_back(to);
    }

    map<int, int> results;
    for (int i = 0; i < queriesCount; i++)
    {
        int node;
        cin >> node;

        cout << solve(node, neighbours, results) << '\n';
    }

    return 0;
}
