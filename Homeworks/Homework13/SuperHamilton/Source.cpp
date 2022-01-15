#include <iostream>
#include <vector>
#include <string>

using namespace std;

int HamiltonPathsCount(int row, int column, vector<string>& map, vector<vector<bool>>& isVisited, int visitedCount, int roomsCount)
{
    if (map[row][column] == 'e')
    {
        return visitedCount == roomsCount;
    }

    int pathsCount = 0;

    // up
    if (row > 0 && map[row - 1][column] == '-' && !isVisited[row - 1][column])
    {
        isVisited[row - 1][column] = true;
        pathsCount += HamiltonPathsCount(row - 1, column, map, isVisited, visitedCount + 1, roomsCount);
        isVisited[row - 1][column] = false;
    }
    if (row > 0 && map[row - 1][column] == 'e' && visitedCount == roomsCount)
    {
        return 1;
    }

    // down
    if (row < map.size() - 1 && map[row + 1][column] == '-' && !isVisited[row + 1][column])
    {
        isVisited[row + 1][column] = true;
        pathsCount += HamiltonPathsCount(row + 1, column, map, isVisited, visitedCount + 1, roomsCount);
        isVisited[row + 1][column] = false;
    }
    if (row < map.size() - 1 && map[row + 1][column] == 'e' && visitedCount == roomsCount)
    {
        return 1;
    }

    // left
    if (column > 0 && map[row][column - 1] == '-' && !isVisited[row][column - 1])
    {
        isVisited[row][column - 1] = true;
        pathsCount += HamiltonPathsCount(row, column - 1, map, isVisited, visitedCount + 1, roomsCount);
        isVisited[row][column - 1] = false;
    }
    if (column > 0 && map[row][column - 1] == 'e' && visitedCount == roomsCount)
    {
        return 1;
    }

    // right
    if (column < map[0].size() - 1 && map[row][column + 1] == '-' && !isVisited[row][column + 1])
    {
        isVisited[row][column + 1] = true;
        pathsCount += HamiltonPathsCount(row, column + 1, map, isVisited, visitedCount + 1, roomsCount);
        isVisited[row][column + 1] = false;
    }
    if (column < map[0].size() - 1 && map[row][column + 1] == 'e' && visitedCount == roomsCount)
    {
        return 1;
    }

    return pathsCount;
}

int main() 
{
    int rows, columns;
    cin >> rows >> columns;

    vector<string> map(rows);
    int startRow, startColumn, roomsCount = 0;
    for (int i = 0; i < rows; i++)
    {
        cin >> map[i];

        for (int j = 0; j < columns; j++)
        {
            if (map[i][j] == 's')
            {
                startRow = i;
                startColumn = j;
            }
            else if (map[i][j] == '-')
            {
                roomsCount++;
            }
        }
    }

    vector<vector<bool>> isVisited(rows, vector<bool>(columns, false));
    cout << HamiltonPathsCount(startRow, startColumn, map, isVisited, 0, roomsCount) << '\n';

    return 0;
}
