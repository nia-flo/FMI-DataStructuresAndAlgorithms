#include <iostream>
#include <vector>

using namespace std;

long long findResult(unsigned long long start, unsigned long long end, vector<unsigned long long>& cooks, unsigned long long pancakes)
{
    if (start == end)
    {
        return start;
    }

    unsigned long long middle = (start + end) / 2;

    unsigned long long currentPancakes = 0;
    for (unsigned long long i = 0; i < cooks.size(); i++)
    {
        currentPancakes += middle / cooks[i];
    }

    if (currentPancakes < pancakes)
    {
        return findResult(middle + 1, end, cooks, pancakes);
    }

    return findResult(start, middle, cooks, pancakes);
}

int main()
{
    unsigned long long pancakes, cooksCount;
    cin >> pancakes >> cooksCount;

    vector<unsigned long long> cooks(cooksCount);
    unsigned long long cycleTime = -1;
    for (unsigned long long i = 0; i < cooksCount; i++)
    {
        cin >> cooks[i];

        if (cooks[i] > cycleTime)
        {
            cycleTime = cooks[i];
        }
    }

    unsigned long long pancakesPerFullCycle = 0;
    for (unsigned long long i = 0; i < cooksCount; i++)
    {
        pancakesPerFullCycle += cycleTime / cooks[i];
    }

    unsigned long long cycles = pancakes / pancakesPerFullCycle;
    unsigned long long madePancakes = cycles * pancakesPerFullCycle;

    unsigned long long start, end;

    if (madePancakes == pancakes)
    {
        start = (cycles - 1) * cycleTime;
        end = cycles * cycleTime;
    }
    else
    {
        start = cycles * cycleTime;
        end = (cycles + 1) * cycleTime;
    }

    cout << findResult(start, end, cooks, pancakes) << '\n';

    return 0;
}