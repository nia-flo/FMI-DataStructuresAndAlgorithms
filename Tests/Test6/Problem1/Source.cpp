#include <iostream>
#include <vector>

using namespace std;

void MarkComponent(int currentNode, int componentMark, vector<vector<int>>& neighbours, vector<int>& components)
{
	components[currentNode] = componentMark;

	for (int i = 0; i < neighbours[currentNode].size(); i++)
	{
		if (components[neighbours[currentNode][i]] == -1)
		{
			MarkComponent(neighbours[currentNode][i], componentMark, neighbours, components);
		}
	}
}

int main() 
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

    int nodesCount, edgesCount;
    cin >> nodesCount >> edgesCount;

    vector<vector<int>> neighbours(nodesCount); 
    for (int i = 0; i < edgesCount; i++)
    {
        int edgeStart, edgeEnd;
        cin >> edgeStart >> edgeEnd;

        neighbours[edgeStart - 1].push_back(edgeEnd - 1);
		neighbours[edgeEnd - 1].push_back(edgeStart - 1);
    }

	vector<int> components(nodesCount, -1);
	int componentsCount = 0;
	for (int i = 0; i < nodesCount; i++)
	{
		if (components[i] == -1)
		{
			componentsCount++;
			MarkComponent(i, componentsCount, neighbours, components);
		}
	}

	int queriesCount;
	cin >> queriesCount;

	for (int i = 0; i < queriesCount; i++)
	{
		int from, to;
		cin >> from >> to;

		cout << (components[from - 1] == components[to - 1]) << ' ';
	}

    return 0;
}