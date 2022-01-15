#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> input(N);
    unordered_map<int, int> used;
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
        used[input[i]]++;
    }

    for (int i = 0; i < input.size(); i++)
    {
        if (used[input[i]] == 1)
        {
            cout << input[i] << ' ';
        }
    }
    for (int i = 0; i < input.size(); i++)
    {
        if (used[input[i]] > 1)
        {
            cout << input[i] << ' ';
            used[input[i]] = 0;
        }
    }
    cout << '\n';

    return 0;
}
