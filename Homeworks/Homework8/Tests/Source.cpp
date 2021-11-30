#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TestBase
{
    long long submitTime;
    long long linesCode;

    virtual bool operator<(const TestBase& other) const = 0;
};

struct Test : TestBase
{
    bool operator<(const TestBase& other) const override;
};

struct WaitingTest : TestBase
{
    WaitingTest(const Test& test);

    bool operator<(const TestBase& other) const override;
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    priority_queue<Test> allTests;
    for (int i = 0; i < N; i++)
    {
        Test test;
        cin >> test.submitTime >> test.linesCode;
        allTests.push(test);
    }

    priority_queue<WaitingTest> waitingTests;
    waitingTests.push(allTests.top());
    allTests.pop();

    long long timesSum = 0;
    long long currentTime = 0;
    while (!waitingTests.empty())
    {
        while (!allTests.empty() && allTests.top().submitTime <= currentTime)
        {
            waitingTests.push(allTests.top());
            allTests.pop();
        }

        WaitingTest currentTest = waitingTests.top();
        waitingTests.pop();

        long long waitTime = currentTest.linesCode;
        if (currentTime > currentTest.submitTime)
        {
            waitTime += currentTime - currentTest.submitTime;
        }

        currentTime = currentTest.submitTime + waitTime;
        timesSum += waitTime;

        if (waitingTests.empty() && !allTests.empty())
        {
            currentTime = max(currentTime, allTests.top().submitTime);
            waitingTests.push(WaitingTest(allTests.top()));
            allTests.pop();
        }
    }

    cout << timesSum / N << '\n';

    return 0;
}

bool Test::operator<(const TestBase& other) const
{
    return this->submitTime > other.submitTime;
}

WaitingTest::WaitingTest(const Test& test)
{
    this->submitTime = test.submitTime;
    this->linesCode = test.linesCode;
}

bool WaitingTest::operator<(const TestBase& other) const
{
    return this->linesCode > other.linesCode;
}