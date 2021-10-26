#include <iostream>

using namespace std;

inline unsigned long long cube(unsigned long long n)
{
    return n * n * n;
}

inline unsigned long long sqrt(unsigned long long n)
{
    if (n <= 1)
    {
        return n;
    }

    unsigned long long start = 1, end = n < 2000000 ? n / 2 : 2000000, result;
    while (start <= end)
    {
        unsigned long long middle = (start + end) / 2;
        unsigned long long middleSquare = middle * middle;

        if (middleSquare == n)
        {
            return middle;
        }

        if (middleSquare < n)
        {
            start = middle + 1;
            result = middle;
        }
        else
            end = middle - 1;
    }

    return result;
}

unsigned long long solve(unsigned long long min, unsigned long long max, unsigned long long points)
{
    if (points < 8)
    {
        return points;
    }

    unsigned long long middle = (min + max) / 2;
    unsigned long long middleCube = cube(middle);

    if (middleCube == points)
    {
        return 1;
    }

    if (middleCube > points)
    {
        return solve(min, middle, points);
    }

    if (cube(middle + 1) > points)
    {
        unsigned long long remainingPoints = points - middleCube;
        return 1 + solve(1, sqrt(remainingPoints), remainingPoints);
    }

    return solve(middle + 1, max, points);
}

int main()
{
    unsigned long long points;
    cin >> points;

    cout << solve(1, sqrt(points), points) << '\n';

    return 0;
}