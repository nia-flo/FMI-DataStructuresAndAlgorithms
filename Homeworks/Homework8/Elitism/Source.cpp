#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(1);

    int N;
    cin >> N;

    priority_queue<int> smallerHalf; // biggest element on top
    priority_queue<int, std::vector<int>, std::greater<int> > biggerHalf; // smallest element on top
    double median;

    cin >> median;
    cout << median << '\n';

    smallerHalf.push(median);

    for (int i = 1; i < N; i++)
    {
        int input;
        cin >> input;

        if (input > median)
        {
            biggerHalf.push(input);
        }
        else
        {
            smallerHalf.push(input);
        }

        if (biggerHalf.size() == smallerHalf.size() + 2)
        {
            smallerHalf.push(biggerHalf.top());
            biggerHalf.pop();
        }
        else if (smallerHalf.size() == biggerHalf.size() + 2)
        {
            biggerHalf.push(smallerHalf.top());
            smallerHalf.pop();
        }

        if (biggerHalf.size() == smallerHalf.size())
        {
            median = (smallerHalf.top() + biggerHalf.top()) / 2.0;
        }
        else if (biggerHalf.size() > smallerHalf.size())
        {
            median = biggerHalf.top();
        }
        else
        {
            median = smallerHalf.top();
        }

        cout << median << '\n';
    }

    return 0;
}