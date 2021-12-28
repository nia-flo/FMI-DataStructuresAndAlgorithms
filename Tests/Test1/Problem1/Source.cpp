#include <iostream>

using namespace std;

bool contains(int array[], int start, int end, int wanted)
{
	if (start == end)
	{
		return false;
	}

	int middle = (start + end) / 2;

	if (array[middle] == wanted)
	{
		return true;
	}

	if (wanted < array[middle])
	{
		return contains(array, start, middle, wanted);
	}

	return contains(array, middle + 1, end, wanted);
}

void positionLastElement(int array[], int elementsCount)
{
	for (int i = elementsCount - 1; i >= 0 && array[i + 1] < array[i]; i--)
	{
		swap(array[i + 1], array[i]);
	}
}

int main()
{
	int n;
	cin >> n;

	int* videos = new int[n];
	int uniqueNumbersCount = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> videos[uniqueNumbersCount];

		if (!contains(videos, 0, uniqueNumbersCount, videos[uniqueNumbersCount]))
		{
			positionLastElement(videos, uniqueNumbersCount);
			uniqueNumbersCount++;
		}
	}

	for (int i = 0; i < uniqueNumbersCount; i++)
	{
		cout << videos[i] << ' ';
	}

	delete[] videos;

	return 0;
}