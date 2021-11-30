#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Operator
{
    static int operatorsCount;

    int clientsCount;
    int time;
    int index;

    Operator();
};

bool compare(const Operator& first, const Operator& second)
{
    if (first.clientsCount != second.clientsCount)
    {
        return first.clientsCount > second.clientsCount;
    }

    return first.index < second.index;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<Operator> operators(K);
    for (int i = 0; i < N; i++)
    {
        int callTime, callDuration;
        cin >> callTime >> callDuration;

        for (int j = 0; j < K; j++)
        {
            if (operators[(i + j) % K].time <= callTime)
            {
                operators[(i + j) % K].time = callTime + callDuration;
                operators[(i + j) % K].clientsCount++;
                break;
            }
        }
    }

    sort(operators.begin(), operators.end(), compare);

    int maxClientsCount = operators[0].clientsCount;
    for (int i = 0; i < K && operators[i].clientsCount == operators[0].clientsCount; i++)
    {
        cout << operators[i].index << ' ';
    }
    cout << '\n';

    return 0;
}

int Operator::operatorsCount = 0;

Operator::Operator()
{
    this->clientsCount = 0;
    this->time = 0;
    this->index = this->operatorsCount;
    this->operatorsCount++;
}