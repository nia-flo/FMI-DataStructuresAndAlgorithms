#include <iostream>

using namespace std;

//returns the position of the wanted element in the array or -1 if the element is not found 
int search(int array[], int size, int wanted)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == wanted)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	int array[] = { 1, 3, 6, 4, 7, 2, 9, 0 };

	cout << search(array, 8, 6) << ' ' << search(array, 8, 5) << '\n';

	return 0;
}