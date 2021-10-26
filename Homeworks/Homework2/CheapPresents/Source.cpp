#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& array, int start, int middle, int end)
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

void mergeSort(vector<int>& array, int start, int end)
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
	int n;
	cin >> n;

	vector<int> presents(n);
	for (int i = 0; i < n; i++)
	{
		cin >> presents[i];
	}

	mergeSort(presents, 0, n);

	int k;
	cin >> k;

	long long result = 0;
	for (int i = 0; i < k; i++)
	{
		result += presents[i];
	}

	cout << result << '\n';

	return 0;
}