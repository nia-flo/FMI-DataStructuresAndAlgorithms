#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, vector<int>> BellmanFord(int startNode, int endNode, vector<vector<pair<int, int>>>& neighbours) // .first is the path lenght, .second is the path
{
	vector<int> distances(neighbours.size()), previous(neighbours.size());
	for (int i = 0; i < neighbours.size(); i++)
	{
		distances[i] = INT_MAX;
		previous[i] = -1;
	}
	distances[startNode] = 0;

	

	vector<int> path;
	for (int node = endNode; node != -1; node = previous[node])
	{
		path.push_back(node);
	}

	for (int i = 0; i < path.size() / 2; i++)
	{
		swap(path[i], path[path.size() - 1 - i]);
	}

	return { distances[endNode], path };
}

int main()
{
	int nodesCount, edgesCount;
	cin >> nodesCount >> edgesCount;

	vector<vector<pair<int, int>>> neighbours(nodesCount); // .first is the neighbour node, .second is the edge distance
	for (int i = 0; i < edgesCount; i++)
	{
		int edgeStart, edgeEnd, distance;
		cin >> edgeStart >> edgeEnd >> distance;

		neighbours[edgeStart - 1].push_back({ edgeEnd - 1, distance });
	}

	int pathStart, pathEnd;
	cin >> pathStart >> pathEnd;

	pair<int, vector<int>> shortestPath = BellmanFord(pathStart - 1, pathEnd - 1, neighbours);
	if (shortestPath.first == -1)
	{
		cout << "There isn't a path between " << pathStart << " and " << pathEnd << '\n';
	}
	else
	{
		cout << "The shortest path between " << pathStart << " and " << pathEnd << " is " << shortestPath.first << '\n';
		cout << "The path is: " << shortestPath.second[0] + 1;
		for (int i = 1; i < shortestPath.second.size(); i++)
		{
			cout << " -> " << shortestPath.second[i] + 1;
		}
		cout << '\n';
	}
}