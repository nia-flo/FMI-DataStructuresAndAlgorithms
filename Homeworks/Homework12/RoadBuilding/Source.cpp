#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
    static int edgesCount;

    int id;
    int from;
    int to;
    long long effort;
    long long profit;

    Edge();

    bool operator<(const Edge& other) const;
};

vector<Edge> Prim(int nodesCount, vector<vector<Edge>>& neighbours)
{
    vector<bool> isConnected(nodesCount, false);
    int connectedNodesCount = 1;

    priority_queue<Edge> edges;

    isConnected[0] = true;
    for (int i = 0; i < neighbours[0].size(); i++)
    {
        edges.push(neighbours[0][i]);
    }

    vector<Edge> minimalSpanningTree;
    while (connectedNodesCount < nodesCount)
    {
        Edge current = edges.top();
        edges.pop();

        if (!isConnected[current.to])
        {
            minimalSpanningTree.push_back(current);
            isConnected[current.to] = true;
            connectedNodesCount++;
            for (int i = 0; i < neighbours[current.to].size(); i++)
            {
                edges.push(neighbours[current.to][i]);
            }
        }
    }

    return minimalSpanningTree;
}

int main()
{
    int nodesCount, edgesCount;
    cin >> nodesCount >> edgesCount;

    vector<vector<Edge>> neighbours(nodesCount);
    for (int i = 0; i < edgesCount; i++)
    {
        Edge edge;
        cin >> edge.from >> edge.to >> edge.effort >> edge.profit;
        edge.from--;
        edge.to--;

        neighbours[edge.from].push_back(edge);

        swap(edge.from, edge.to);
        neighbours[edge.from].push_back(edge);
    }

    vector<Edge> minimalSpanningTree = Prim(nodesCount, neighbours);
    for (int i = 0; i < minimalSpanningTree.size(); i++)
    {
        cout << minimalSpanningTree[i].id << '\n';
    }
}

int Edge::edgesCount = 0;

Edge::Edge()
{
    this->edgesCount++;
    this->id = this->edgesCount;
}

bool Edge::operator<(const Edge& other) const
{
    if (this->effort != other.effort)
    {
        return this->effort > other.effort;
    }

    return this->profit < other.profit;
}
