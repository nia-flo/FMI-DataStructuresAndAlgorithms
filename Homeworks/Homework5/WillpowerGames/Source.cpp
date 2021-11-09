#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> players(N);
	for (int i = 0; i < N; i++)
	{
		cin >> players[i];
	}

	vector<int> days(N);
	int hungrierPlayer = players[0];
	stack<int> playerIndex;

	playerIndex.push(0);
	for (int i = 1; i < N; i++)
	{
		if (players[i - 1] < players[i])
		{
			days[i] = 1;
		}
		else
		{
			days[i] = 0;
		}

		if (players[i] < hungrierPlayer)
		{
			hungrierPlayer = players[i];
		}

		while (!playerIndex.empty())
		{
			int currPlayerIndex = playerIndex.top();

			if (players[currPlayerIndex] < players[i])
			{
				break;
			}

			playerIndex.pop();

			if (players[i] > hungrierPlayer)
			{
				if (days[currPlayerIndex] + 1 > days[i])
				{
					days[i] = days[currPlayerIndex] + 1;
				}
			}
		}

		playerIndex.push(i);
	}

	int gameDays = days[0];
	for (int i = 1; i < N; i++)
	{
		if (days[i] > gameDays)
		{
			gameDays = days[i];
		}
	}

	cout << gameDays << '\n';

	return 0;
}