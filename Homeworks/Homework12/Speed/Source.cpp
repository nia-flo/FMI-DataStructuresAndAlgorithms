#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
	static int minSpeed;
	static int maxSpeed;

	int from;
	int to;
	int speed;

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

void Kruskal(int nodesCount, vector<Edge>& edges, int start)
{
	vector<int> parents(nodesCount);
	for (int i = 0; i < nodesCount; i++)
	{
		parents[i] = i;
	}
	parents[edges[start].to] = edges[start].from;

	int minSpeed = edges[start].speed, maxSpeed = edges[start].speed;
	int usedEdges = 1;
	for (int i = start + 1; i < edges.size() && usedEdges < nodesCount - 1; i++)
	{
		if (find(edges[i].from, parents) != find(edges[i].to, parents))
		{
			usedEdges++;

			merge(edges[i].from, edges[i].to, parents);

			if (edges[i].speed < minSpeed)
			{
				minSpeed = edges[i].speed;
			}
			else if (edges[i].speed > maxSpeed)
			{
				maxSpeed = edges[i].speed;
			}
		}
	}

	if (usedEdges == nodesCount - 1 && ((Edge::minSpeed == -1 || maxSpeed - minSpeed < Edge::maxSpeed - Edge::minSpeed)
		|| (maxSpeed - minSpeed == Edge::maxSpeed - Edge::minSpeed && minSpeed < Edge::minSpeed)))
	{
		Edge::maxSpeed = maxSpeed;
		Edge::minSpeed = minSpeed;
	}
}

int main()
{
	int nodesCount, edgesCount;
	cin >> nodesCount >> edgesCount;

	vector<Edge> edges(edgesCount);
	for (int i = 0; i < edgesCount; i++)
	{
		cin >> edges[i].from >> edges[i].to >> edges[i].speed;
		edges[i].from--;
		edges[i].to--;
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i < edgesCount; i++)
	{
		Kruskal(nodesCount, edges, i);
	}

	cout << Edge::minSpeed << ' ' << Edge::maxSpeed << '\n';
}

int Edge::minSpeed = -1;
int Edge::maxSpeed = -1;

bool Edge::operator<(const Edge& other) const
{
	return this->speed < other.speed;
}