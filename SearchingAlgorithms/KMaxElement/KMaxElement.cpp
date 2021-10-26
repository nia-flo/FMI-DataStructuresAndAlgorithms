#include <iostream>

using namespace std;

int divide(int array[], int start, int end)
{
	int index = start;
	for (int i = start; i < end - 1; i++)
	{
		if (array[i] > array[end - 1])
		{
			swap(array[i], array[index]);
			index++;
		}
	}
	swap(array[end - 1], array[index]);

	return index;
}

//returns the k-th max element in the array
int search(int array[], int start, int end, int k)
{
	int middle = divide(array, start, end);

	if (middle - start + 1 == k)
	{
		return array[middle];
	}
	
	if (middle - start + 1 < k)
	{
		return search(array, middle + 1, end, k - middle - 1);
	}

	return search(array, start, middle, k);
}

int main()
{
	int array[] = { 1, 10, 6, 4, 8, 7, 3, 2, 5, 9 };

	cout << search(array, 0, 10, 1) << ' ' << search(array, 0, 10, 3) << '\n';

	return 0;
}