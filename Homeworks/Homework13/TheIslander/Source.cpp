#include <iostream>
#include <vector>
#include <string>

using namespace std;

void DFS(int node, vector<vector<int>>& neighbours, vector<bool>& isVisited)
{
    isVisited[node] = true;

    for (int i = 0; i < neighbours[node].size(); i++)
    {
        if (!isVisited[neighbours[node][i]])
        {
            DFS(neighbours[node][i], neighbours, isVisited);
        }
    }
}

bool isConnected(vector<vector<int>>& neighbours)
{
    vector<bool> isVisited(neighbours.size(), false);
    DFS(0, neighbours, isVisited);

    for (int i = 0; i < neighbours.size(); i++)
    {
        if (!isVisited[i])
        {
            return false;
        }
    }

    return true;
}

string isEulerian(vector<vector<int>>& neighbours) {
    int odd = 0;
    for (int i = 0; i < neighbours.size(); i++)
    {
        if (neighbours[i].size() % 2 == 1)
        {
            odd++;
        }

    }

    if (odd == 0)
    {
        return "ecycle";
    }

    if (odd == 2)
    {
        return "epath";
    }

    return "none";
}


int main()
{
    int queriesCount;
    cin >> queriesCount;

    for (int q = 0; q < queriesCount; q++)
    {
        int nodesCount, edgesCount;
        cin >> nodesCount >> edgesCount;

        vector<vector<int>> neighbours(nodesCount);
        for (int i = 0; i < edgesCount; i++)
        {
            int edgeFrom, edgeTo;
            cin >> edgeFrom >> edgeTo;

            neighbours[edgeFrom].push_back(edgeTo);
            neighbours[edgeTo].push_back(edgeFrom);
        }

        if (!isConnected(neighbours))
        {
            cout << "none\n";
        }
        else
        {
            cout << isEulerian(neighbours) << '\n';
        }
    }

    return 0;
}
