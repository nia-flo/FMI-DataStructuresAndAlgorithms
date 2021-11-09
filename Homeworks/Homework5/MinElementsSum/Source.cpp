#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, d;
    cin >> N >> d;

    vector<long long> input(N);
    vector<int> minElementIdx(N);
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];

        if (i < d)
        {
            if (i == 0 || input[i] < input[minElementIdx[i - 1]])
            {
                minElementIdx[i] = i;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (input[i] < input[minElementIdx[j]])
                    {
                        minElementIdx[j] = i;
                    }
                }
            }
            else
            {
                minElementIdx[i] = minElementIdx[i - 1];
            }
        }
        else
        {
            if (minElementIdx[i - 1] <= i - d || input[i] < input[minElementIdx[i - 1]])
            {
                minElementIdx[i] = i;
                for (int j = 1; j < d; j++)
                {
                    if (input[i - j] < input[minElementIdx[i]])
                    {
                        minElementIdx[i] = i - j;
                    }
                }
            }
            else
            {
                minElementIdx[i] = minElementIdx[i - 1];
            }
        }
    }

    long long minElementsSum = 0;
    for (int i = d - 1; i < N; i++)
    {
        minElementsSum += input[minElementIdx[i]];
    }

    cout << minElementsSum << '\n';

    return 0;
}