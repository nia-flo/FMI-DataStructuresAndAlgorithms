#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Student
{
    int row;
    int column;

    Student();
    Student(int row, int column);

    bool operator<(const Student& other) const;
    bool operator==(const Student& other) const;
};

int main()
{
    int rows, columns;
    cin >> rows >> columns;

    int time, studentsCount;
    cin >> time >> studentsCount;

    set<Student> sickStudents;
    for (int i = 0; i < studentsCount; i++)
    {
        Student student;
        cin >> student.row >> student.column;

        sickStudents.insert(student);
    }

    for (int i = 0; i < time; i++)
    {
        vector<Student> toAdd;
        for (set<Student>::iterator it = sickStudents.begin(); it != sickStudents.end(); it++)
        {
            if ((*it).row - 1 > 0)
            {
                toAdd.push_back(Student((*it).row - 1, (*it).column));
            }
            if ((*it).row + 1 <= rows)
            {
                toAdd.push_back(Student((*it).row + 1, (*it).column));
            }
            if ((*it).column - 1 > 0)
            {
                toAdd.push_back(Student((*it).row, (*it).column - 1));
            }
            if ((*it).column + 1 <= columns)
            {
                toAdd.push_back(Student((*it).row, (*it).column + 1));
            }
        }

        for (int j = 0; j < toAdd.size(); j++)
        {
            sickStudents.insert(toAdd[j]);
        }
    }

    cout << rows * columns - sickStudents.size() << '\n';

    return 0;
}

Student::Student()
{}

Student::Student(int row, int column)
{
    this->row = row;
    this->column = column;
}

bool Student::operator<(const Student& other) const
{
    return (this->row != other.row) ? (this->row < other.row) : (this->column < other.column);
}

bool Student::operator==(const Student& other) const
{
    return this->row == other.row && this->column == other.column;
}
