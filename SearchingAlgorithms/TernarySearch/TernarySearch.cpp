#include <iostream>

using namespace std;

//the array must be sorted
//returns the position of the wanted element in the array or -1 if the element is not found 
int searchIterative(int array[], int size, int wanted)
{
	int start = 0, end = size;

	while (start != end)
	{
		int leftMiddle = (2 * start + end) / 3;

		if (array[leftMiddle] == wanted)
		{
			return leftMiddle;
		}

		int rightMiddle = (start + 2 * end) / 3;

		if (array[rightMiddle] == wanted)
		{
			return rightMiddle;
		}

		if (wanted < array[leftMiddle])
		{
			end = leftMiddle;
		}
		else if (wanted > array[rightMiddle])
		{
			start = rightMiddle + 1;
		}
		else
		{
			start = rightMiddle + 1;
			end = leftMiddle;
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

	int leftMiddle = (2 * start + end) / 3;

	if (array[leftMiddle] == wanted)
	{
		return leftMiddle;
	}

	int rightMiddle = (start + 2 * end) / 3;

	if (array[rightMiddle] == wanted)
	{
		return rightMiddle;
	}

	if (wanted < array[leftMiddle])
	{
		return searchRecursive(array, start, leftMiddle, wanted);
	}

	if (wanted > array[rightMiddle])
	{
		return searchRecursive(array, rightMiddle + 1, end, wanted);
	}

	return searchRecursive(array, leftMiddle + 1, rightMiddle, wanted);
}

int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << searchRecursive(array, 0, 10, 3) << ' ' << searchRecursive(array, 0, 10, 33) << '\n';
	cout << searchIterative(array, 10, 3) << ' ' << searchIterative(array, 10, 33) << '\n';

	return 0;
}