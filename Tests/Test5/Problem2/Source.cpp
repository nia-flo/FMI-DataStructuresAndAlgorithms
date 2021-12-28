#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main()
{
    int N;
    cin >> N;

    vector<int> input(N);
    map<int, int> occurrences;
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
        occurrences[input[i]]++;
    }

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (occurrences[input[i]] % 2 == 1)
        {
            sum += input[i];
        }
    }

    cout << sum << '\n';

    return 0;
}
