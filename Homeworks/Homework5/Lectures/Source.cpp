#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define LETTERS_COUNT 26
# define NUMBERS_COUNT 10

using namespace std;

class Symbol
{
public:
	static int toInt(char c); 

	Symbol();

	int getCount() const;
	int getPosition() const;
	
	void setPosition(int position);

	Symbol& operator++(int);

private:
	int count;
	int position;
};

int main()
{
	Symbol symbolsCount[2 * LETTERS_COUNT + NUMBERS_COUNT] = {};

	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		int curr = Symbol::toInt(input[i]);

		symbolsCount[curr]++;
		symbolsCount[curr].setPosition(i);
	}
	
	vector<int> result;
	for (int i = 0; i < 2 * LETTERS_COUNT + NUMBERS_COUNT; i++)
	{
		if (symbolsCount[i].getCount() == 1)
		{
			result.push_back(symbolsCount[i].getPosition());
		}
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << ' ';
	}
	cout << '\n';

	return 0;
}

int Symbol::toInt(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return c - 'a';
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return c - 'A' + LETTERS_COUNT;
	}
	
	return c - '0' + 2 * LETTERS_COUNT;
}

Symbol::Symbol()
{
	this->count = 0;
}

int Symbol::getCount() const
{
	return this->count;
}

int Symbol::getPosition() const
{
	return this->position;
}

void Symbol::setPosition(int position)
{
	this->position = position;
}

Symbol& Symbol::operator++(int)
{
	this->count++;

	return *this;
}
