#include <iostream>

using namespace std;

int divide(int array[], int start, int end)
{
	int lastIdx = start;
	for (int i = start; i < end - 1; i++)
	{
		if (array[i] < array[end - 1])
		{
			swap(array[i], array[lastIdx]);
			lastIdx++;
		}
	}
	swap(array[lastIdx], array[end - 1]);

	return lastIdx;
}

void quickSort(int array[], int start, int end)
{
	if (start == end)
	{
		return;
	}

	int middle = divide(array, start, end);

	quickSort(array, start, middle);
	quickSort(array, middle + 1, end);
}

int main()
{
	int array[] = { 10, 5, 3, 6, 1, 2, 7, 4, 9, 8 };

	quickSort(array, 0, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << ' ';
	}

	return 0;
}