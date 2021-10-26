#include <iostream>
#include <algorithm>

#define MIN_PLAYER_NUMBER 1

using namespace std;

int main()
{
	int N;
	cin >> N;

	int* array = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> array[i];
		if (array[i] < MIN_PLAYER_NUMBER)
		{
			i--;
			N--;
		}
	}

	sort(array, array + N);

	int missingNumber = MIN_PLAYER_NUMBER; // min missing player number

	for (int i = 0; i < N; i++)
	{
		if (missingNumber < array[i])
		{
			break;
		}

		if (missingNumber == array[i])
		{
			missingNumber++;
		}
	}

	cout << missingNumber << '\n';

	delete[] array;

	return 0;
}