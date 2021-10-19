#include <iostream>

using namespace std;

void insertionSort(int array[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int position;
		for (position = 0; position < i && array[position] < array[i]; position++) {}

		int lastElement = array[i];
		for (int j = position; j <= i; j++)
		{
			int buffer = array[j];
			array[j] = lastElement;
			lastElement = buffer;
		}
	}
}

int main()
{
	int array[] = { 10, 5, 3, 6, 1, 2, 7, 4, 9, 8 };

	insertionSort(array, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << ' ';
	}

	return 0;
}