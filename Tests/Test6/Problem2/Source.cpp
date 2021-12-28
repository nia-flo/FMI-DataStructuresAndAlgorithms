#include <iostream>
#include <vector>

using namespace std;

void MarkComponent(int currentNode, vector<vector<int>>& neighbours, vector<bool>& isComponentFound)
{
	isComponentFound[currentNode] = true;

	for (int i = 0; i < neighbours[currentNode].size(); i++)
	{
		if (!isComponentFound[neighbours[currentNode][i]])
		{
			MarkComponent(neighbours[currentNode][i], neighbours, isComponentFound);
		}
	}
}

int main()
{
	int testsCount;
	cin >> testsCount;

	for (int test = 0; test < testsCount; test++)
	{
		int nodesCount, edgesCount;
		cin >> nodesCount >> edgesCount;

		vector<vector<int>> neighbours(nodesCount);
		for (int i = 0; i < edgesCount; i++)
		{
			int edgeStart, edgeEnd;
			cin >> edgeStart >> edgeEnd;

			neighbours[edgeStart].push_back(edgeEnd);
			neighbours[edgeEnd].push_back(edgeStart);
		}

		int componentsCount = 0;
		vector<bool> isComponentFound(nodesCount, false);

		for (int i = 0; i < nodesCount; i++)
		{
			if (!isComponentFound[i])
			{
				componentsCount++;
				MarkComponent(i, neighbours, isComponentFound);
			}
		}

		cout << componentsCount << ' ';
	}

	return 0;
}