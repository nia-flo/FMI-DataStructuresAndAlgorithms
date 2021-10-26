#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Demon
{
	int defence;
	int attack;

	Demon() {}
	Demon(int defence, int attack);

	bool operator>(const Demon& other) const;
	bool operator<(const Demon& other) const;
};

bool compare(const Demon& first, const Demon& second)
{
	if (first.attack != second.attack)
	{
		return first.attack < second.attack;
	}

	return first.defence < second.defence;
}

int find(const vector<Demon>& demons, int start, int end, Demon wanted)
{
	if (start == end)
	{
		return start;
	}

	int middle = (start + end) / 2;

	if (!(demons[middle] < wanted))
	{
		return find(demons, start, middle, wanted);
	}
		
	return find(demons, middle + 1, end, wanted);
}

int longestDemonSubsequence(const vector<Demon>& demons)
{
	vector<Demon> sequenceEnd;

	sequenceEnd.push_back(demons[0]);
	for (int i = 1; i < demons.size(); i++)
	{
		if (demons[i] > sequenceEnd[sequenceEnd.size() - 1])
		{
			sequenceEnd.push_back(demons[i]);
		}
		else
		{
			sequenceEnd[find(sequenceEnd, 0, sequenceEnd.size(), demons[i])] = demons[i];
		}
	}

	return sequenceEnd.size();
}

int main()
{
	int n;
	cin >> n;

	vector<Demon> demons(n);
	for (int i = 0; i < n; i++)
	{
		cin >> demons[i].defence >> demons[i].attack;
	}

	sort(demons.begin(), demons.end(), compare);

	cout << longestDemonSubsequence(demons);

	return 0;
}

Demon::Demon(int defence, int attack)
{
	this->defence = defence;
	this->attack = attack;
}

bool Demon::operator>(const Demon& other) const
{
	return this->defence > other.defence && this->attack > other.attack;
}

bool Demon::operator<(const Demon& other) const
{
	return other > *this;
}
