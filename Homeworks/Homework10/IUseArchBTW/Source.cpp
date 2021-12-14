#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

bool isInLoop(map<int, vector<int>>& parents, int end)
{
    queue<int> toTraverse;
    toTraverse.push(end);

    while (!toTraverse.empty())
    {
        int current = toTraverse.front();
        toTraverse.pop();

        for (int i = 0; i < parents[current].size(); i++)
        {
            if (parents[current][i] == end)
            {
                return true;
            }

            toTraverse.push(parents[current][i]);
        }
    }

    return false;
}

int main()
{
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int E;
        cin >> E;

        map<int, vector<int>> parents;
        bool hasLoop = false;
        for (int j = 0; j < E; j++)
        {
            int start, end;
            cin >> start >> end;

            parents[end].push_back(start);

            if (!hasLoop && isInLoop(parents, end))
            {
                hasLoop = true;
            }
        }

        cout << hasLoop << ' ';
    }
    cout << '\n';

    return 0;
}
