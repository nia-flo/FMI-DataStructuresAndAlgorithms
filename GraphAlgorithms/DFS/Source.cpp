#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool DFS(int currentNode, int endNode, map<int, vector<int>>& neighbours, map<int, bool>& visited)
{
	if (currentNode == endNode)
	{
		return true;
	}

	visited[currentNode] = true;

	for (int i = 0; i < neighbours[currentNode].size(); i++)
	{
		if (!visited[neighbours[currentNode][i]])
		{
			if (DFS(neighbours[currentNode][i], endNode, neighbours, visited))
			{
				return true;
			}
		}
	}

	return false;
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

	map<int, bool> visited;
	if (DFS(pathStart, pathEnd, neighbours, visited))
	{
		cout << "There is a path between " << pathStart << " and " << pathEnd << '\n';
	}
	else
	{
		cout << "There isn't a path between " << pathStart << " and " << pathEnd << '\n';
	}
}