#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class DateTime
{
public:
    void setId(long long id);
    long long getId() const;

    DateTime& operator=(const DateTime& other);

    friend istream& operator>> (istream& stream, DateTime& dateTime);
    friend bool compare(DateTime& first, DateTime& second);

private:
    int hours;
    int minutes;
    int seconds;
    int day;
    int month;
    int year;
    long long id;
};

bool compare(DateTime& first, DateTime& second)
{
    if (first.year != second.year)
    {
        return first.year < second.year;
    }

    if (first.month != second.month)
    {
        return first.month < second.month;
    }

    if (first.day != second.day)
    {
        return first.day < second.day;
    }

    if (first.hours != second.hours)
    {
        return first.hours < second.hours;
    }

    if (first.minutes != second.minutes)
    {
        return first.minutes < second.minutes;
    }

    if (first.seconds != second.seconds)
    {
        return first.seconds < second.seconds;
    }
        
    return first.id < second.id;
}

int main()
{
    int n;
    cin >> n;

    vector<DateTime> loggs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> loggs[i];
        loggs[i].setId(i + 1);
    }

    sort(loggs.begin(), loggs.end(), compare);

    for (int i = 0; i < n; i++)
    {
        cout << loggs[i].getId() << '\n';
    }
    return 0;
}

void DateTime::setId(long long id)
{
    this->id = id;
}

long long DateTime::getId() const
{
    return this->id;
}

DateTime& DateTime::operator=(const DateTime& other)
{
    this->year = other.year;
    this->month = other.month;
    this->day = other.day;
    this->hours = other.hours;
    this->minutes = other.minutes;
    this->seconds = other.seconds;
    this->id = other.id;

    return *this;
}

istream& operator>>(istream& stream, DateTime& dateTime)
{
    string time, date;
    stream >> time >> date;

    //time format is HH:MM:SS 

    dateTime.hours = (time[0] - '0') * 10 + time[1] - '0';
    dateTime.minutes = (time[3] - '0') * 10 + time[4] - '0';
    dateTime.seconds = (time[6] - '0') * 10 + time[7] - '0';
    
    //date format is DD.MM.YYYY

    dateTime.day = (date[0] - '0') * 10 + date[1] - '0';
    dateTime.month = (date[3] - '0') * 10 + date[4] - '0';
    dateTime.year = 0;
    for (int i = 6; i < 10; i++)
    {
        dateTime.year *= 10;
        dateTime.year += date[i] - '0';
    }

    return stream;
}
