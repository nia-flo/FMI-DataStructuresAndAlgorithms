#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
	int buffer = *a;
	*a = *b;
	*b = buffer;
}

void bubbleSort(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}

int main()
{
	int array[] = { 10, 5, 3, 6, 1, 2, 7, 4, 9, 8 };

	bubbleSort(array, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << ' ';
	}

	return 0;
}