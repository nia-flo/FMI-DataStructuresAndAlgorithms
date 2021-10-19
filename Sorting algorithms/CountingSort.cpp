#include <iostream>

#define MAX_NUMBER 1000

using namespace std;

void countingSort(int array[], int size)
{
	int numbersCount[MAX_NUMBER] = {};

	for (int i = 0; i < size; i++)
	{
		numbersCount[array[i]]++;
	}

	int idx = 0;
	for (int i = 0; i < MAX_NUMBER; i++)
	{
		for (int j = 0; j < numbersCount[i]; j++)
		{
			array[idx] = i;
			idx++;
		}
	}
}

int main()
{
	int array[] = { 10, 5, 3, 6, 1, 2, 7, 4, 9, 8 };

	countingSort(array, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << ' ';
	}

	return 0;
}