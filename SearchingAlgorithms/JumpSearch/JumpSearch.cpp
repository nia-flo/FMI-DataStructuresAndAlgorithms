#include <iostream>
#include <cmath>

using namespace std;

//returns the position of the wanted element in the array or -1 if the element is not found 
int linearSearch(int array[], int start, int end, int wanted)
{
	for (int i = start; i < end; i++)
	{
		if (array[i] == wanted)
		{
			return i;
		}
	}

	return -1;
}

//the array must be sorted
//returns the position of the wanted element in the array or -1 if the element is not found 
int jumpSearch(int array[], int size, int wanted)
{
	int idx = 0, step = sqrt(size);
	while (idx < size && array[idx] < wanted)
	{
		idx += step;
	}

	return linearSearch(array, max(idx - size, 0), min(idx, size), wanted);
}

int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << jumpSearch(array, 10, 3) << ' ' << jumpSearch(array, 10, 33) << '\n';

	return 0;
}