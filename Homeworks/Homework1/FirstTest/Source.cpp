#include <iostream>
#include <string>

using namespace std;

int main()
{
	string students;
	cin >> students;

	char lateStudent;
	cin >> lateStudent;

	int* distance = new int[students.size()]; // distance to late student's test type

	for (int i = 0; i < students.size(); i++)
	{
		distance[i] = -1;
	}

	for (int i = 0; i < students.size();)
	{
		if (students[i] == lateStudent)
		{
			distance[i] = 0;

			for (int j = i - 1; j >= 0 && (distance[j] == -1 || i - j < distance[j]); j--)
			{
				distance[j] = i - j;
			}

			int initialI = i;
			for (i++; i < students.size() && students[i] != lateStudent; i++)
			{
				distance[i] = i - initialI;
			}
		}
		else
		{
			i++;
		}
	}

	for (int i = 0; i < students.size(); i++)
	{
		cout << distance[i] << ' ';
	}
	cout << '\n';

	delete[] distance;

	return 0;
}