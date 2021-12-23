#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void Dijkstra(int startNode, vector<vector<pair<int, int>>>& neighbours, vector<long long>& distances) // .first is the shortest path lenght, .second is the paths count
{
	distances[startNode] = 0;

	queue<pair<long long, int>> toTraverse; // .first is the path length from startNode to this node, .second is the node
	toTraverse.push({ 0, startNode });

	while (!toTraverse.empty())
	{
		pair<long long, int> toTraverseFront = toTraverse.front();
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
				toTraverse.push({ distances[neighbours[current][i].first], neighbours[current][i].first });
			}
		}
	}
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

		neighbours[edgeStart].push_back({ edgeEnd, distance });
		neighbours[edgeEnd].push_back({ edgeStart, distance });
	}

	int K;
	cin >> K;

	vector<long long> distances(neighbours.size(), LLONG_MAX);
	for (int i = 0; i < K; i++)
	{
		int node;
		cin >> node;


		Dijkstra(node, neighbours, distances);
	}

	int Q;
	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		int node;
		cin >> node;

		cout << distances[node] << '\n';
	}

	return 0;
}