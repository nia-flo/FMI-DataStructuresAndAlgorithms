#include <iostream>
#include <string>

using namespace std;

int main()
{
    string first, second;
    cin >> first >> second;

    int* substringLenght[2];
    substringLenght[0] = new int[first.size() + 1];
    substringLenght[1] = new int[first.size() + 1];
    for (int i = 0; i < first.size() + 1; i++)
    {
        substringLenght[0][i] = 0;
        substringLenght[1][i] = 0;
    }

    int maxSubstringLenght = 0;
    for (int i = 0; i < second.size(); i++)
    {
        for (int j = 0; j < first.size(); j++)
        {
            if (first[j] == second[i])
            {
                substringLenght[i % 2][j + 1] = substringLenght[(i + 1) % 2][j] + 1;
                if (substringLenght[i % 2][j + 1] > maxSubstringLenght)
                {
                    maxSubstringLenght = substringLenght[i % 2][j + 1];
                }
            }
            else
            {
                substringLenght[i % 2][j + 1] = 0;
            }
        }
    }

    cout << maxSubstringLenght << '\n';

    delete[] substringLenght[0];
    delete[] substringLenght[1];

    return 0;
}