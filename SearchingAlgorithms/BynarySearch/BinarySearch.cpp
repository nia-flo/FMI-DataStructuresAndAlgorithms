#include <iostream>

using namespace std;

//the array must be sorted
//returns the position of the wanted element in the array or -1 if the element is not found 
int searchIterative(int array[], int size, int wanted)
{
	int start = 0, end = size;

	while (start != end)
	{
		int middle = (start + end) / 2;

		if (wanted == array[middle])
		{
			return middle;
		}

		if (wanted < array[middle])
		{
			end = middle;
		}
		else
		{
			start = middle + 1;
		}
	}

	return -1;
}

//the array must be sorted
//returns the position of the wanted element in the array or -1 if the element is not found 
int searchRecursive(int array[], int start, int end, int wanted)
{
	if (start == end)
	{
		return -1;
	}

	int middle = (start + end) / 2;

	if (wanted == array[middle])
	{
		return middle;
	}

	if (wanted < array[middle])
	{
		return searchRecursive(array, start, middle, wanted);
	}

	return searchRecursive(array, middle + 1, end, wanted);
}

int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << searchRecursive(array, 0, 10, 3) << ' ' << searchRecursive(array, 0, 10, 33) << '\n';
	cout << searchIterative(array, 10, 3) << ' ' << searchIterative(array, 10, 33) << '\n';

	return 0;
}