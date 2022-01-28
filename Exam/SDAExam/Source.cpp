#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int startNode, vector<vector<int>>& neighbours, vector<int>& distance)
{
    queue<int> toTraverse;
    toTraverse.push(startNode);

    distance[startNode] = 0;

    while (!toTraverse.empty())
    {
        int currentNode = toTraverse.front();
        toTraverse.pop();

        for (int i = 0; i < neighbours[currentNode].size(); i++)
        {
            if (distance[neighbours[currentNode][i]] == -1)
            {
                distance[neighbours[currentNode][i]] = distance[currentNode] + 6;
                toTraverse.push(neighbours[currentNode][i]);
            }
        }
    }
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
            int from, to;
            cin >> from >> to;

            neighbours[from - 1].push_back(to - 1);
            neighbours[to - 1].push_back(from - 1);
        }

        int startNode;
        cin >> startNode;
        startNode--;

        vector<int> distance(nodesCount, -1);
        BFS(startNode, neighbours, distance);

        for (int i = 0; i < nodesCount; i++)
        {
            if (i != startNode)
            {
                cout << distance[i] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}