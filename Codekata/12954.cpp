#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n)
{
    long long _x = x;
    vector<long long> answer;
    for (int i = 0; i < n; i++)
    {
        answer.push_back(_x);
        _x += x;
    }
    return answer;
}