#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define MOD 1000000007

using namespace std;

pair<long long, int> Dijkstra(int startNode, int endNode, vector<vector<pair<int, int>>>& neighbours) // .first is the shortest path lenght, .second is the paths count
{
    vector<long long> distances(neighbours.size(), LLONG_MAX);
    vector<int> pathsCount(neighbours.size(), 0);

    distances[startNode] = 0;
    pathsCount[startNode] = 1;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> toTraverse; // .first is the path length from startNode to this node, .second is the node
    toTraverse.push({ 0, startNode });

    while (!toTraverse.empty())
    {
        pair<long long, int> toTraverseFront = toTraverse.top();
        if (toTraverseFront.first != distances[toTraverseFront.second])
        {
            toTraverse.pop();
            continue;
        }

        int current = toTraverseFront.second;
        toTraverse.pop();

        for (int i = 0; i < neighbours[current].size(); i++)
        {
            if (distances[current] + neighbours[current][i].second < distances[neighbours[current][i].first])
            {
                distances[neighbours[current][i].first] = distances[current] + neighbours[current][i].second;
                pathsCount[neighbours[current][i].first] = pathsCount[current];
                toTraverse.push({ distances[neighbours[current][i].first], neighbours[current][i].first });
            }
            else if (distances[current] + neighbours[current][i].second == distances[neighbours[current][i].first])
            {
                pathsCount[neighbours[current][i].first] = (pathsCount[neighbours[current][i].first] + pathsCount[current]) % MOD;
            }
        }
    }

    if (pathsCount[endNode] == 0)
    {
        return { -1, 0 };
    }

    return { distances[endNode], pathsCount[endNode] };
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nodesCount, edgesCount;
    cin >> nodesCount >> edgesCount;

    vector<vector<pair<int, int>>> neighbours(nodesCount); // .first is the neighbour node, .second is the edge distance
    for (int i = 0; i < edgesCount; i++)
    {
        int edgeStart, edgeEnd, distance;
        cin >> edgeStart >> edgeEnd >> distance;

        neighbours[edgeStart - 1].push_back({ edgeEnd - 1, distance });
    }

    pair<long long, int> shortestPath = Dijkstra(0, nodesCount - 1, neighbours);
    cout << shortestPath.first << ' ' << shortestPath.second << '\n';

    return 0;
}