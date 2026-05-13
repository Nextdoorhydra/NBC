#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

struct node {
    int value;
    vector<node>* next;
};

int recur(vector<vector<int>>& arr, pair<int, int> startPos, int sep, node answer)
{
    int c = startPos.first, r = startPos.second, nextSep = sep / 2;

    if (sep == 1)
    {
        return arr[r][c];
    }


    int r1 = recur(arr, make_pair(r, c), nextSep, answer);
    int r3 = recur(arr, make_pair(r + nextSep, c), nextSep, answer);
    int r2 = recur(arr, make_pair(r, c + nextSep), nextSep, answer);
    int r4 = recur(arr, make_pair(r + nextSep, c + nextSep), nextSep, answer);

    if (r1 && r2 && r3 && r4)
    {

        return 1;
    }
    else if (!r1 && !r2 && !r3 && !r4)
    {
        return 0;
    }
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;

    recur(arr, make_pair(0, 0), arr.size(), node());

    return answer;
}

int main()
{
    //solution(std::vector<std::vector<int>>{
    //    {1, 1, 1, 1},
    //    {1, 0, 0, 1},
    //    {1, 1, 0, 1},
    //    {1, 1, 1, 1},
    //    });
    solution(std::vector<std::vector<int>>{
    {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 1},
    {0, 1, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 1, 1, 1}
        });

    return 0;
}
