#include <iostream>
#include <list>
#include <vector>

#define MIN_SEQUENCE_LENGHT 3

using namespace std;

struct Ball
{
    static int ballsCount;

    int index;
    int colour;
    int seqLenght;
    list<Ball>::iterator seqStart;
    list<Ball>::iterator seqEnd;

    Ball(int colour);

    bool operator==(int index) const;
    bool operator==(const Ball& ball) const;
};

void addBall(list<Ball>& balls, Ball& newBall)
{
    balls.push_back(newBall);

    list<Ball>::iterator newBallIt = balls.end();
    newBallIt--;

    (*newBallIt).seqLenght = 1;

    int seqLenght = 1;
    list<Ball>::iterator ball;
    for (ball = newBallIt; ball != balls.begin() && (*ball).colour == newBall.colour; ball--)
    {
        (*ball).seqEnd = newBallIt;
        (*ball).seqLenght = seqLenght;
        seqLenght++;
    }

    if ((*ball).colour == newBall.colour)
    {
        (*ball).seqEnd = newBallIt;
        (*newBallIt).seqStart = ball;
        (*ball).seqLenght = seqLenght;
    }
    else
    {
        ball++;
        (*newBallIt).seqStart = ball;
    }
}

void SetSeqEnds(list<Ball>& balls, list<Ball>::iterator& currBall)
{
    list<Ball>::iterator prevBall = currBall;
    if (prevBall != balls.begin())
    {
        prevBall--;
    }

    list<Ball>::iterator nextBall = currBall;
    nextBall++;

    list<Ball>::iterator prevSeqEnd = currBall, nextSeqStart = currBall, nextSeqEnd = currBall;
    if ((*prevBall).colour == (*currBall).colour)
    {
        (*currBall).seqStart = (*prevBall).seqStart;

        if (nextBall != balls.end() && (*nextBall).colour == (*currBall).colour)
        {
            prevSeqEnd = (*nextBall).seqEnd;
            nextSeqStart = (*prevBall).seqStart;
            (*currBall).seqEnd = (*nextBall).seqEnd;
            nextSeqEnd = (*currBall).seqEnd;
        }
        else
        {
            prevSeqEnd = currBall;
            nextSeqStart = nextBall;
            if (nextBall == balls.end())
            {
                nextSeqEnd = nextBall;
            }
            else
            {
                nextSeqEnd = (*nextBall).seqEnd;
            }
            (*currBall).seqEnd = currBall;
        }
    }
    else if (nextBall != balls.end() && (*nextBall).colour == (*currBall).colour)
    {
        (*currBall).seqStart = currBall;
        (*currBall).seqEnd = (*nextBall).seqEnd;
        prevSeqEnd = prevBall;
        nextSeqStart = currBall;
        nextSeqEnd = (*nextBall).seqEnd;
    }
    else
    {
        (*currBall).seqStart = currBall;
        (*currBall).seqEnd = currBall;
        prevSeqEnd = prevBall;
        nextSeqStart = nextBall;
        if (nextBall == balls.end())
        {
            nextSeqEnd = nextBall;
        }
        else
        {
            nextSeqEnd = (*nextBall).seqEnd;
        }
    }

    int seqLenght = 1;
    list<Ball>::iterator ball;
    for (ball = nextSeqEnd; ball != nextBall; ball--)
    {
        (*ball).seqStart = nextSeqStart;
        (*ball).seqLenght = seqLenght;
        seqLenght++;
    }
    if (ball != balls.end())
    {
        (*ball).seqStart = nextSeqStart;
        (*ball).seqLenght = seqLenght;
        seqLenght++;
    }

    if (nextBall == balls.end() || (*nextBall).colour != (*currBall).colour)
    {
        seqLenght = 1;
    }
    (*currBall).seqLenght = seqLenght;
    seqLenght++;

    if ((*prevBall).colour != (*currBall).colour)
    {
        seqLenght = 1;
    }

    if (prevBall == currBall)
    {
        return;
    }

    for (ball = prevBall; ball != balls.begin() && (*ball).colour == (*prevBall).colour; ball--)
    {
        (*ball).seqEnd = prevSeqEnd;
        (*ball).seqLenght = seqLenght;
        seqLenght++;
    }
    if ((*ball).colour == (*prevBall).colour)
    {
        (*ball).seqEnd = prevSeqEnd;
        (*ball).seqLenght = seqLenght;
    }
}

int remove(list<Ball>& balls, list<Ball>::iterator& middleBall)
{
    list<Ball>::iterator start = (*middleBall).seqStart;
    bool isSeqFromStart = start == balls.begin();

    list<Ball>::iterator end = (*middleBall).seqEnd;
    end++;
    bool isSeqToEnd = end == balls.end();

    if ((*start).seqLenght < MIN_SEQUENCE_LENGHT)
    {
        return 0;
    }

    list<Ball>::iterator startCopy = start;
    if (start != balls.begin())
    {
        startCopy--;
    }

    int ballsCount = start->seqLenght;
    balls.erase(start, end);

    if (!isSeqFromStart)
    {
        SetSeqEnds(balls, startCopy);
    }
    else if (!isSeqToEnd)
    {
        SetSeqEnds(balls, end);
    }

    if (isSeqFromStart || isSeqToEnd)
    {
        return ballsCount;
    }

    if ((*startCopy).colour == (*end).colour)
    {
        (*end).seqStart = (*startCopy).seqStart;
        (*startCopy).seqEnd = (*end).seqEnd;
        return ballsCount + remove(balls, end);
    }

    return ballsCount;
}

int addBall(list<Ball>& balls, vector<list<Ball>::iterator>& ballsByIndex, Ball& newBall, int index)
{
    if (balls.empty())
    {
        return -1;
    }

    list<Ball>::iterator prevBall = ballsByIndex[index];
    if (prevBall == balls.begin()) {
        return -1;
    }
    prevBall++;

    list<Ball>::iterator currBall = balls.insert(prevBall, newBall);
    ballsByIndex.push_back(currBall);

    SetSeqEnds(balls, currBall);

    return remove(balls, currBall);
}

void print(list<Ball>& balls)
{
    if (balls.empty())
    {
        cout << "-1\n";
        return;
    }

    for (Ball ball : balls)
    {
        cout << ball.colour << ' ';
    }
    cout << '\n';
}

int main()
{
    int N;
    cin >> N;

    list<Ball> balls;
    vector<list<Ball>::iterator> ballsByIndex;
    for (int i = 0; i < N; i++)
    {
        int colour;
        cin >> colour;

        Ball newBall(colour);

        addBall(balls, newBall);
        ballsByIndex.push_back(balls.end());
        ballsByIndex[ballsByIndex.size() - 1]--;
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int index, colour;
        cin >> index >> colour;

        Ball newBall(colour);

        int result = addBall(balls, ballsByIndex, newBall, index);
        if (result == -1)
        {
            cout << "Game Over\n";
        }
        else
        {
            cout << result << '\n';
        }
    }

    print(balls);

    return 0;
}

int Ball::ballsCount = 0;

Ball::Ball(int colour)
{
    this->colour = colour;
    this->index = this->ballsCount;
    this->ballsCount++;
}

bool Ball::operator==(int index) const
{
    return this->index == index;
}

bool Ball::operator==(const Ball& ball) const
{
    return this->index == ball.index;;
}
