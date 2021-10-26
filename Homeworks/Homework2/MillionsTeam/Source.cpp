#include <iostream>
#include <string>

using namespace std;

void merge(string& players, int start, int middle, int end)
{
	if (start == middle || middle == end)
	{
		return;
	}

	int* result = new int[end - start];

	int idx1 = start, idx2 = middle, i = 0;
	for (; idx1 < middle && idx2 < end; i++)
	{
		if (players[idx1] < players[idx2])
		{
			result[i] = players[idx1];
			idx1++;
		}
		else
		{
			result[i] = players[idx2];
			idx2++;
		}
	}

	for (; idx1 < middle; i++)
	{
		result[i] = players[idx1];
		idx1++;
	}

	for (; idx2 < end; i++)
	{
		result[i] = players[idx2];
		idx2++;
	}

	for (int i = start; i < end; i++)
	{
		players[i] = result[i - start];
	}

	delete[] result;
}

void mergeSort(string& players, int start, int end)
{
	if (start + 1 == end)
	{
		return;
	}

	int middle = (start + end) / 2;
	mergeSort(players, start, middle);
	mergeSort(players, middle, end);
	merge(players, start, middle, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string numbers, smallLetters, bigLetters;
	for (int i = 0; i < n; i++)
	{
		char input;
		cin >> input;

		if (input >= '0' && input <= '9')
		{
			numbers += input;
		}
		else if (input >= 'a' && input <= 'z')
		{
			smallLetters += input;
		}
		else
		{
			bigLetters += input;
		}
	}

	mergeSort(numbers, 0, numbers.size());
	mergeSort(smallLetters, 0, smallLetters.size());
	mergeSort(bigLetters, 0, bigLetters.size());

	cout << numbers << smallLetters << bigLetters << '\n';

	return 0;
}
