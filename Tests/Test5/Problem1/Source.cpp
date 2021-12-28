#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() 
{
    int N;
    cin >> N;

    vector<string> input(N);
    map<string, int> occurrences;
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
        occurrences[input[i]]++;
    }

    for (int i = 0; i < N; i++)
    {
        cout << occurrences[input[i]] << ' ';
    }
    cout << '\n';

    return 0;
}
