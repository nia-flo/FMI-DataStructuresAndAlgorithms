#include <iostream>
#include <string>

using namespace std;

int main()
{
	string word;
	cin >> word;

	int N; // letters count
	cin >> N;

	char symbol;
	cin >> symbol;

	int wordsCount = N / word.size();
	int remainingLetters = N % word.size();

	int result = 0;
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == symbol)
		{
			result += wordsCount;
			if (i < remainingLetters)
			{
				result++;
			}
		}
	}

	cout << result << '\n';

	return 0;
}