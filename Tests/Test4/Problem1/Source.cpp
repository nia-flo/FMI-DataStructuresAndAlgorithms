#include <iostream>
#include <queue>

using namespace std;

struct TaskBase
{
    long long startTime;
    long long duration;

    virtual bool operator<(const TaskBase& other) const = 0;
};

struct Task : TaskBase
{
    bool operator<(const TaskBase& other) const override;
};

struct WaitingTask : TaskBase
{
    WaitingTask(const Task& task);

    bool operator<(const TaskBase& other) const override;
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    priority_queue<Task> allTasks;
    for (int i = 0; i < N; i++)
    {
        Task task;
        cin >> task.duration;
        task.startTime = i;
        allTasks.push(task);
    }

    priority_queue<WaitingTask> waitingTasks;
    waitingTasks.push(allTasks.top());
    allTasks.pop();

    long long currentTime = waitingTasks.top().startTime;
    long long minTime = -1, maxTime = -1;
    while (!waitingTasks.empty())
    {
        while (!allTasks.empty() && allTasks.top().startTime <= currentTime)
        {
            waitingTasks.push(allTasks.top());
            allTasks.pop();
        }

        WaitingTask currentTask = waitingTasks.top();
        waitingTasks.pop();

        long long waitTime = currentTask.duration;
        if (currentTime > currentTask.startTime)
        {
            waitTime += currentTime - currentTask.startTime;
        }

        if (minTime == -1 || waitTime < minTime)
        {
            minTime = waitTime;
        }
        if (maxTime == -1 || waitTime > maxTime)
        {
            maxTime = waitTime;
        }

        currentTime = currentTask.startTime + waitTime;

        if (waitingTasks.empty() && !allTasks.empty())
        {
            currentTime = max(currentTime, allTasks.top().startTime);
            waitingTasks.push(WaitingTask(allTasks.top()));
            allTasks.pop();
        }
    }
    cout << minTime << ' ' << maxTime << '\n';

    return 0;
}

bool Task::operator<(const TaskBase& other) const
{
    return this->startTime > other.startTime;
}

WaitingTask::WaitingTask(const Task& task)
{
    this->startTime = task.startTime;
    this->duration = task.duration;
}

bool WaitingTask::operator<(const TaskBase& other) const
{
    return this->duration > other.duration;
}