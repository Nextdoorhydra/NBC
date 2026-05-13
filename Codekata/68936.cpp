#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <utility>
#include <memory>

using namespace std;

struct node {
    int value = -1;
    vector<unique_ptr<node>> child;
};

int recur(vector<vector<int>>& arr, pair<int, int> startPos, int sep, node& answer)
{
    int c = startPos.second, r = startPos.first, nextSep = sep / 2;

    if (sep == 1)
    {
        answer.value = arr[r][c];
        return arr[r][c];
    }

    answer.child.push_back(std::make_unique<node>());
    answer.child.push_back(std::make_unique<node>());
    answer.child.push_back(std::make_unique<node>());
    answer.child.push_back(std::make_unique<node>());

    int r1 = recur(arr, make_pair(r, c), nextSep, *answer.child[0]);
    int r2 = recur(arr, make_pair(r, c + nextSep), nextSep, *answer.child[1]);
    int r3 = recur(arr, make_pair(r + nextSep, c), nextSep, *answer.child[2]);
    int r4 = recur(arr, make_pair(r + nextSep, c + nextSep), nextSep, *answer.child[3]);

    if (r1 == 1 && r2 == 1 && r3 == 1 && r4 == 1)
    {
        answer.value = 1;
        return 1;
    }
    else if (!r1 && !r2 && !r3 && !r4)
    {
        answer.value = 0;
        return 0;
    }

    return -1;
}

void count(node& answer, vector<int>& result)
{
    switch(answer.value)
    {
        case 0:
            result[0]++;
            return;
        case 1:
            result[1]++;
            return;
    }

    if (answer.child.size() == 0) return;

    count(*answer.child[0], result);
    count(*answer.child[1], result);
    count(*answer.child[2], result);
    count(*answer.child[3], result);
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    node quat;

    recur(arr, make_pair(0, 0), arr.size(), quat);
    count(quat, answer);

    return answer;
}

//int main()
//{
//    //solution(std::vector<std::vector<int>>{
//    //    {1, 1, 1, 1},
//    //    {1, 0, 1, 1},
//    //    {1, 0, 0, 1},
//    //    {1, 1, 1, 1},
//    //    });
//    solution(std::vector<std::vector<int>>{
//    {1, 1, 1, 1, 1, 1, 1, 1},
//    {0, 1, 1, 1, 1, 1, 1, 1},
//    {0, 0, 0, 0, 1, 1, 1, 1},
//    {0, 1, 0, 0, 1, 1, 1, 1},
//    {0, 0, 0, 0, 0, 0, 1, 1},
//    {0, 0, 0, 0, 0, 0, 0, 1},
//    {0, 0, 0, 0, 1, 0, 0, 1},
//    {0, 0, 0, 0, 1, 1, 1, 1}
//        });
//
//    return 0;
//}
