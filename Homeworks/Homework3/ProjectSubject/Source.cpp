#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Team
{
    int knowledge;
    int id;
};

bool compare(const Team& first, const Team& second)
{
    return first.knowledge < second.knowledge;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> subjects(n);
    for (int i = 0; i < n; i++)
    {
        cin >> subjects[i];
    }

    vector<Team> teams(m);
    for (int i = 0; i < m; i++)
    {
        cin >> teams[i].knowledge;
        teams[i].id = i;
    }

    sort(subjects.begin(), subjects.end());
    sort(teams.begin(), teams.end(), compare);

    vector<int> next(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int lastNext = i + 1;
        next[i] = lastNext;
        while (i > 0 && subjects[i - 1] == subjects[i])
        {
            next[i - 1] = lastNext;
            i--;
        }
    }

    vector<int> result(m);
    int subjectsIndex = 0;
    for (int i = 0; i < m; i++)
    {
        while (next[subjectsIndex] < n &&
            abs(subjects[subjectsIndex] - teams[i].knowledge) > abs(subjects[next[subjectsIndex]] - teams[i].knowledge))
        {
            subjectsIndex = next[subjectsIndex];
        }

        result[teams[i].id] = subjects[subjectsIndex];
    }

    for (int i = 0; i < m; i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
}