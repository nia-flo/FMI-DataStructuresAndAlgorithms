#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Match
{
public:
	void setId(int id);
	int getId() const;

	friend istream& operator>>(istream& stream, Match& match);
	friend bool compare(Match& first, Match& second);

private:
	int team1;
	int team2;
	double efficiency;
	int id;
};

bool compare(Match& first, Match& second)
{
	if (first.efficiency != second.efficiency)
	{
		return first.efficiency > second.efficiency;
	}

	return first.team1 > second.team1;
}

int main()
{
	int n;
	cin >> n;

	vector<Match> matches(n);
	for (int i = 0; i < n; i++)
	{
		cin >> matches[i];
		matches[i].setId(i + 1);
	}

	sort(matches.begin(), matches.end(), compare);

	for (int i = 0; i < n; i++)
	{
		cout << matches[i].getId() << ' ';
	}
	cout << '\n';

	return 0;
}

istream& operator>>(istream& stream, Match& match)
{
	stream >> match.team1 >> match.team2;

	match.efficiency = (match.team1 * match.team1) / (double) match.team2;

	return stream;
}

void Match::setId(int id)
{
	this->id = id;
}

int Match::getId() const
{
	return this->id;
}
