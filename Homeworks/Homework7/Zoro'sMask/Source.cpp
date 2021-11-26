#include <iostream>
#include <set>
#include <vector>

using namespace std;

class MaskContainer
{
public:
	void add(int n);
	int submasksCount() const;

private:
	set<int> submasks;

	vector<bool> decimalToBinary(int n);
	int binaryToDecimal(vector<bool>& binaryN);
	void add(vector<bool>& binaryN, int index);
};

int main() 
{
	MaskContainer masks;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		masks.add(input);
	}

	cout << masks.submasksCount() << '\n';
    return 0;
}

void MaskContainer::add(int n)
{
	vector<bool> binaryN = this->decimalToBinary(n);

	this->add(binaryN, 0);
}

int MaskContainer::submasksCount() const
{
	return this->submasks.size();
}

vector<bool> MaskContainer::decimalToBinary(int n)
{
	vector<bool> binaryN;
	while (n != 0)
	{
		binaryN.push_back(n % 2 == 1);
		n /= 2;
	}

	return binaryN;
}

int MaskContainer::binaryToDecimal(vector<bool>& binaryN)
{
	int result = 0, multiplier = 1;
	for (int i = 0; i < binaryN.size(); i++)
	{
		if (binaryN[i])
		{
			result += multiplier;
		}

		multiplier *= 2;
	}

	return result;
}

void MaskContainer::add(vector<bool>& binaryN, int index)
{
	if (index == binaryN.size())
	{
		this->submasks.insert(this->binaryToDecimal(binaryN));
		return;
	}

	if (binaryN[index] == 1)
	{
		binaryN[index] = 0;
		this->add(binaryN, index + 1);
		binaryN[index] = 1;
	}

	this->add(binaryN, index + 1);
}
