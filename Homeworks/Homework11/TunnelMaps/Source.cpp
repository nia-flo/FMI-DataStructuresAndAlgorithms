#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int Dijkstra(int startNode, int endNode, vector<vector<pair<int, pair<int, int>>>>& neighbours, int maxTime)
{
    vector<vector<pair<int, int>>> results(neighbours.size()); // .first is the kgs, .second is the time

    results[startNode].push_back({ 0, 0 });

    priority_queue<pair<pair<int, int>, int>> toTraverse; // .first is {kgs, time} from startNode to this node, .second is the node
    toTraverse.push({ {0, 0}, startNode });

    int minKgs = INT_MAX;

    while (!toTraverse.empty())
    {
        pair<pair<int, int>, int> toTraverseTop = toTraverse.top();
        int current = toTraverseTop.second;
        pair<int, int> currentResult = toTraverseTop.first;
        toTraverse.pop();

        if (currentResult.first < minKgs)
        {
            for (int i = 0; i < neighbours[current].size(); i++)
            {
                int neighbour = neighbours[current][i].first;
                pair<int, int> newResult = { max(currentResult.first, neighbours[current][i].second.first), currentResult.second + neighbours[current][i].second.second };

                if (newResult.first < minKgs)
                {
                    if (neighbour == endNode && newResult.second < maxTime)
                    {
                        minKgs = newResult.first;
                    }

                    if (results[neighbour].size() == 0 && newResult.second < maxTime)
                    {
                        results[neighbour].push_back(newResult);
                        toTraverse.push({ newResult, neighbour });
                    }
                    else if (newResult.second < maxTime)
                    {
                        for (int j = 0; j < results[neighbour].size(); j++)
                        {
                            if (newResult.first <= results[neighbour][j].first && newResult.second <= results[neighbour][j].second)
                            {
                                results[neighbour][j] = newResult;
                                toTraverse.push({ newResult, neighbour });
                                break;
                            }
                            else if (newResult.first < results[neighbour][j].first || newResult.second < results[neighbour][j].second)
                            {
                                results[neighbour].push_back(newResult);
                                toTraverse.push({ newResult, neighbour });
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    if (minKgs == INT_MAX)
    {
        return -1;
    }

    return minKgs;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nodesCount, edgesCount, maxTime;
    cin >> nodesCount >> edgesCount >> maxTime;

    vector<vector<pair<int, pair<int, int>>>> neighbours(nodesCount); // .first is the neighbour node, .second is {kgs, time}
    for (int i = 0; i < edgesCount; i++)
    {
        int from, to, kgs, time;
        cin >> from >> to >> kgs >> time;

        neighbours[from - 1].push_back({ to - 1, {kgs, time} });
    }

    cout << Dijkstra(0, nodesCount - 1, neighbours, maxTime) << '\n';

    return 0;
}