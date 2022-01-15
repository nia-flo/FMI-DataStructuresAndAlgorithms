#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findDepth(int node, int nodeDepth, vector<vector<int>>& neighbours, vector<bool>& visited, int minimumDepth)
{
	visited[node] = true;
	if (nodeDepth > minimumDepth)
	{
		return minimumDepth + 1;
	}

	int depth = nodeDepth;
	for (int i = 0; i < neighbours[node].size(); i++)
	{
		if (depth > minimumDepth)
		{
			return minimumDepth + 1;
		}

		if (!visited[neighbours[node][i]])
		{
			depth = max(depth, findDepth(neighbours[node][i], nodeDepth + 1, neighbours, visited, minimumDepth));
		}
	}

	return depth;
}

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> neighbours(N);
	for (int i = 0; i < N - 1; i++)
	{
		int edgeFrom, edgeTo;
		cin >> edgeFrom >> edgeTo;

		neighbours[edgeFrom].push_back(edgeTo);
		neighbours[edgeTo].push_back(edgeFrom);
	}

	int minimumDepth = INT_MAX;
	vector<int> roots;
	for (int i = 0; i < N; i++)
	{
		vector<bool> visited(N, false);
		int currentDepth = findDepth(i, 0, neighbours, visited, minimumDepth);

		if (currentDepth < minimumDepth)
		{
			minimumDepth = currentDepth;
			roots.clear();
			roots.push_back(i);
		}
		else if (currentDepth == minimumDepth)
		{
			roots.push_back(i);
		}
	}

	for (int i = 0; i < roots.size(); i++)
	{
		cout << roots[i] << ' ';
	}
	cout << '\n';

	return 0;
}
