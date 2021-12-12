#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    if (K == 1)
    {
        map<int, int> animalsByKg;
        for (int i = 0; i < N; i++)
        {
            int animalKg;
            cin >> animalKg;
            animalsByKg[animalKg]++;
        }

        long long threesomesCount = 0;
        for (map<int, int>::iterator it = animalsByKg.begin(); it != animalsByKg.end(); it++)
        {
            for (int i = (*it).second - 2; i > 0; i--)
            {
                threesomesCount += ((i + 1) * i) / 2;
            }
        }

        cout << threesomesCount << '\n';

        return 0;
    }

    map<pair<int, int>, int> pairsCount;
    long long threesomesCount = 0;
    for (int i = 0; i < N; i++)
    {
        int animalKg;
        cin >> animalKg;

        pairsCount[{animalKg, -1}]++;

        if (animalKg % K == 0)
        {
            int secondKg = animalKg / K;

            if (pairsCount[{secondKg, -1}] > 0)
            {
                pairsCount[{secondKg, animalKg}] += pairsCount[{secondKg, -1}];
            }

            if (secondKg % K == 0)
            {
                threesomesCount += pairsCount[{secondKg / K, secondKg}];
            }
        }
    }

    cout << threesomesCount << '\n';

    return 0;
}