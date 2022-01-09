#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
	int from;
	int to;
	int distance;

	bool operator<(const Edge& other) const;
};

int find(int node, vector<int>& parents)
{
	if (node != parents[node])
	{
		parents[node] = find(parents[node], parents);
	}

	return parents[node];
}

void merge(int firstNode, int secondNode, vector<int>& parents)
{
	if (parents[firstNode] != parents[secondNode])
	{
		parents[parents[firstNode]] = secondNode;
	}
}

vector<Edge> Kruskal(int nodesCount, vector<Edge>& edges)
{
	sort(edges.begin(), edges.end());

	vector<int> parents(nodesCount);
	for (int i = 0; i < nodesCount; i++)
	{
		parents[i] = i;
	}

	int usedEdges = 0;
	vector<Edge> minimalSpanningTree;
	for (int i = 0; i < edges.size() && usedEdges < nodesCount - 1; i++)
	{
		if (find(edges[i].from, parents) != find(edges[i].to, parents))
		{
			usedEdges++;
			merge(edges[i].from, edges[i].to, parents);
			minimalSpanningTree.push_back(edges[i]);
		}
	}

	return minimalSpanningTree;
}

int main()
{
	//nodes are 0, 1, .., N, where N is nodesCount

	int nodesCount, edgesCount;
	cin >> nodesCount >> edgesCount;

	vector<Edge> edges(edgesCount);
	for (int i = 0; i < edgesCount; i++)
	{
		cin >> edges[i].from >> edges[i].to >> edges[i].distance;
	}

	vector<Edge> minimalSpanningTree = Kruskal(nodesCount, edges);

	cout << "The minimal spanning tree is:\n";
	for (int i = 0; i < minimalSpanningTree.size(); i++)
	{
		cout << minimalSpanningTree[i].from << " - " << minimalSpanningTree[i].to << " -> " << minimalSpanningTree[i].distance << '\n';
	}
}

bool Edge::operator<(const Edge& other) const
{
	return this->distance < other.distance;
}