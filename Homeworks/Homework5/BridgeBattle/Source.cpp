#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	stack<int> bridge;
	for (int i = 0; i < N; i++)
	{
		int fighter;
		cin >> fighter;

		if (fighter < 0)
		{
			while (!bridge.empty() && bridge.top() > 0 && -fighter > bridge.top())
			{
				bridge.pop();
			}

			if (bridge.empty() || bridge.top() < 0)
			{
				bridge.push(fighter);
			}
			else if (bridge.top() == -fighter)
			{
				bridge.pop();
			}
		}
		else
		{
			bridge.push(fighter);
		}
		
	}

	vector<int> result;
	while (!bridge.empty())
	{
		result.push_back(bridge.top());
		bridge.pop();
	}

	for (int i = result.size() - 1; i >= 0; i--)
	{
		cout << result[i] << ' ';
	}
	cout << '\n';

	return 0;
}