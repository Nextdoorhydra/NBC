#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int recur(vector<vector<int>>& arr, pair<int, int> startPos, int sep)
{
    int c = startPos.first, r = startPos.second, nextSep = sep / 2;

    if (sep == 0)
    {
        return arr[r][c];
    }
    else if (arr[r][c] == 0
        && arr[r][c + nextSep] == 0
        && arr[r + nextSep][c] == 0
        && arr[r + nextSep][c + nextSep] == 0)
    {
        return 0;
    }
    else if (arr[r][c] == 1
        && arr[r][c + nextSep] == 1
        && arr[r + nextSep][c] == 1
        && arr[r + nextSep][c + nextSep] == 1)
    {
        return 1;
    }

    cout << '(' << r << ", " << c << ')' << endl;

    recur(arr, make_pair(r, c), nextSep);
    recur(arr, make_pair(r, c + nextSep), nextSep);
    recur(arr, make_pair(r + nextSep, c), nextSep);
    recur(arr, make_pair(r + nextSep, c + nextSep), nextSep);
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;

    recur(arr, make_pair(0, 0), arr.size());

    return answer;
}

int main()
{
    solution(vector<vector<int>>{{1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 1, 1, 1}});

    return 0;
}
