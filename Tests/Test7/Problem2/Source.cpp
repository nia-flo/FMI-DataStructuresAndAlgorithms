#include <iostream>
#include <vector>

using namespace std;

bool DFS(int currentNode, int endNode, vector<vector<int>>& neighbours, vector<bool>& visited, int visitedNodesCount, int nodesInPath)
{
    if (!visited[currentNode])
    {
        visitedNodesCount++;
        visited[currentNode] = true;
    }

    if (visitedNodesCount > nodesInPath)
    {
        return false;
    }

    if (visitedNodesCount == nodesInPath)
    {
        return currentNode == endNode;
    }

    for (int i = 0; i < neighbours[currentNode].size(); i++)
    {
        if (DFS(neighbours[currentNode][i], endNode, neighbours, visited, visitedNodesCount + 1, nodesInPath))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int nodesCount, edgesCount;
    cin >> nodesCount >> edgesCount;

    vector<pair<pair<int, int>, int>> edges(edgesCount);
    for (int i = 0; i < edgesCount; i++)
    {
        cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int lenghtToDelete;
        cin >> lenghtToDelete;

        for (int j = 0; j < edgesCount; j++)
        {
            if (edges[j].second == lenghtToDelete)
            {
                swap(edges[j], edges[edgesCount - 1]);
                edgesCount--;
            }
        }
    }

    vector<vector<int>> neighbours(nodesCount);
    for (int i = 0; i < edgesCount; i++)
    {
        neighbours[edges[i].first.first].push_back(edges[i].first.second);
    }

    int queriesCount;
    cin >> queriesCount;

    for (int i = 0; i < queriesCount; i++)
    {
        int nodesInPath, start, end;
        cin >> nodesInPath >> start >> end;

        vector<bool> visited(nodesCount, false);
        cout << DFS(start, end, neighbours, visited, 0, nodesInPath);
    }
}