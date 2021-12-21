#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int BFS(int startNode, int endNode, map<int, vector<int>>& neighbours)
{
	map<int, bool> visited;

	queue<pair<int, int>> toTraverse; // .first is a node, .second is the path length from startNode to this node
	toTraverse.push({ startNode, 0 });

	while (!toTraverse.empty())
	{
		pair<int, int> current = toTraverse.front();
		toTraverse.pop();

		if (current.first == endNode)
		{
			return current.second;
		}

		visited[current.first] = true;

		for (int i = 0; i < neighbours[current.first].size(); i++)
		{
			if (!visited[neighbours[current.first][i]])
			{
				toTraverse.push({ neighbours[current.first][i] , current.second + 1 });
			}
		}
	}

	return -1;
}

int main()
{
	int edgesCount;
	cin >> edgesCount;

	map<int, vector<int>> neighbours;
	for (int i = 0; i < edgesCount; i++)
	{
		int edgeStart, edgeEnd;
		cin >> edgeStart >> edgeEnd;

		neighbours[edgeStart].push_back(edgeEnd);
	}

	int pathStart, pathEnd;
	cin >> pathStart >> pathEnd;

	int shortestPath = BFS(pathStart, pathEnd, neighbours);
	if (shortestPath == -1)
	{
		cout << "There isn't a path between " << pathStart << " and " << pathEnd << '\n';
	}
	else
	{
		cout << "The shortest path between " << pathStart << " and " << pathEnd << " is " << shortestPath << '\n';
	}
}