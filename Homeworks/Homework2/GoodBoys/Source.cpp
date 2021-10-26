#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Boy
{
public:
	void setId(int id);
	int getId() const;

	friend istream& operator>>(istream& stream, Boy& boy);
	friend bool compare(Boy& first, Boy& second);

private:
	int discDiameter;
	int lapTime;
	double efficiency;
	int id;
};

bool compare(Boy& first, Boy& second)
{
	if (first.efficiency != second.efficiency)
	{
		return first.efficiency > second.efficiency;
	}

	return first.discDiameter > second.discDiameter;
}

int main()
{
	int n;
	cin >> n;

	vector<Boy> boys(n);
	for (int i = 0; i < n; i++)
	{
		cin >> boys[i];
		boys[i].setId(i + 1);
	}

	sort(boys.begin(), boys.end(), compare);

	for (int i = 0; i < n; i++)
	{
		cout << boys[i].getId() << ' ';
	}
	cout << '\n';

	return 0;
}

istream& operator>>(istream& stream, Boy& boy)
{
	stream >> boy.discDiameter >> boy.lapTime;

	boy.efficiency = (boy.discDiameter * boy.discDiameter) / (4.0 * boy.lapTime);

	return stream;
}

void Boy::setId(int id)
{
	this->id = id;
}

int Boy::getId() const
{
	return this->id;
}
