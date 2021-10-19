#include <iostream>

using namespace std;

void merge(int array[], int start, int middle, int end)
{
	int* result = new int[end - start];

	int idx1 = start, idx2 = middle, i = 0;
	for (; idx1 < middle && idx2 < end; i++)
	{
		if (array[idx1] <= array[idx2])
		{
			result[i] = array[idx1];
			idx1++;
		}
		else
		{
			result[i] = array[idx2];
			idx2++;
		}
	}

	for (; idx1 < middle; i++)
	{
		result[i] = array[idx1];
		idx1++;
	}

	for (; idx2 < end; i++)
	{
		result[i] = array[idx2];
		idx2++;
	}

	for (int i = start; i < end; i++)
	{
		array[i] = result[i - start];
	}

	delete[] result;
}

void mergeSort(int array[], int start, int end)
{
	if (start + 1 == end)
	{
		return;
	}

	int middle = (start + end) / 2;
	mergeSort(array, start, middle);
	mergeSort(array, middle, end);
	merge(array, start, middle, end);
}

int main()
{
	int array[] = { 10, 5, 3, 6, 1, 2, 7, 4, 9, 8 };

	mergeSort(array, 0, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << ' ';
	}

	return 0;
}