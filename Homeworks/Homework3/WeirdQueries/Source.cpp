#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Query
{
    long long maxSum;
    int maxNumber;
    int id;

    bool operator<(const Query& other) const;
};

int findNumbersCount(const vector<long long>& sums, int start, int end, long long maxSum, int lastNumberIndex)
{
    if (start == end)
    {
        return 0;
    }

    int middle = (start + end) / 2;

    long long currSum = sums[lastNumberIndex];
    if (middle > 0)
    {
        currSum -= sums[middle - 1];
    }

    if (currSum == maxSum)
    {

        return lastNumberIndex - middle + 1;
    }

    if (currSum > maxSum)
    {
        return findNumbersCount(sums, middle + 1, end, maxSum, lastNumberIndex);
    }

    long long leftSum = sums[lastNumberIndex];
    if (middle - 1 > 0)
    {
        leftSum -= sums[middle - 2];
    }

    if (middle == start || leftSum > maxSum)
    {
        return lastNumberIndex - middle + 1;
    }

    return findNumbersCount(sums, start, middle, maxSum, lastNumberIndex);
}

int main()
{
    int numbersCount, queriesCount;
    cin >> numbersCount >> queriesCount;

    vector<int> numbers(numbersCount);
    for (int i = 0; i < numbersCount; i++)
    {
        cin >> numbers[i];
    }

    vector<Query> queries(queriesCount);
    for (int i = 0; i < queriesCount; i++)
    {
        cin >> queries[i].maxSum >> queries[i].maxNumber;
        queries[i].id = i;
    }

    sort(numbers.begin(), numbers.end());
    sort(queries.begin(), queries.end());

    vector<long long> sums(numbersCount);
    sums[0] = numbers[0];
    for (int i = 1; i < numbersCount; i++)
    {
        sums[i] = numbers[i] + sums[i - 1];
    }

    vector<int> results(queriesCount);
    int lastNumberIndex = 0;
    for (int i = 0; i < queriesCount; i++)
    {
        while (lastNumberIndex + 1 < numbersCount && numbers[lastNumberIndex + 1] <= queries[i].maxNumber)
        {
            lastNumberIndex++;
        }

        results[queries[i].id] = findNumbersCount(sums, 0, lastNumberIndex + 1, queries[i].maxSum, lastNumberIndex);
    }

    for (int i = 0; i < queriesCount; i++)
    {
        cout << results[i] << '\n';
    }

    return 0;
}

bool Query::operator<(const Query& other) const
{
    return this->maxNumber < other.maxNumber;
}
