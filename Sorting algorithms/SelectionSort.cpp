#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
	int buffer = *a;
	*a = *b;
	*b = buffer;
}

void selectionSort(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int minIdx = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIdx])
			{
				minIdx = j;
			}
		}

		swap(array[i], array[minIdx]);
	}
}

int main()
{
	int array[] = { 10, 5, 3, 6, 1, 2, 7, 4, 9, 8 };

	selectionSort(array, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << ' ';
	}

	return 0;
}