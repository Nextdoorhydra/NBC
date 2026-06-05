#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

void print(vector<vector<int>> m)
{
    cout << "=============================" << endl;

    for (int r = 0, i = 1; r < m.size(); r++)
    {
        for (int c = 0; c < m[0].size(); c++)
        {
            cout << setw(2) << m[r][c] << ' ';
        }
        cout << endl;
    }
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<vector<int>> map(rows, vector<int>(columns, 0));

    for (int r = 0, i = 1; r < rows; r++)
        for (int c = 0; c < columns; c++)
            map[r][c] = i++;

    for (auto& q : queries)
    {
        vector<vector<int>> prevMap = map;
        int x1 = q[0] - 1, y1 = q[1] - 1, x2 = q[2] - 1, y2 = q[3] - 1;
        int minValue = INT_MAX;

        // ul -> ur
        for (int y = y1; y < y2; y++)
        {
            minValue = min(minValue, prevMap[x1][y]);
            map[x1][y + 1] = prevMap[x1][y];
        }

        // cout << "->" << endl;
        // print(map);

        // ru -> rd
        for (int x = x1; x < x2; x++)
        {
            minValue = min(minValue, prevMap[x][y2]);
            map[x + 1][y2] = prevMap[x][y2];
        }

        // cout << "rdown" << endl;
        // print(map);

        // dr -> dl
        for (int y = y2; y > y1; y--)
        {
            minValue = min(minValue, prevMap[x2][y]);
            map[x2][y - 1] = prevMap[x2][y];
        }

        // cout << "<-" << endl;
        // print(map);

        // ld -> lu
        for (int x = x2; x > x1; x--)
        {
            minValue = min(minValue, prevMap[x][y1]);
            map[x - 1][y1] = prevMap[x][y1];
        }

        // cout << "lup" << endl;
        // print(map);

        answer.push_back(minValue);
        prevMap = map;
    }

    return answer;
}

int main()
{
    solution(6, 6, { {2,2,5,4} , {3,3,6,6} , {5,1,6,3} });
    return 0;
}