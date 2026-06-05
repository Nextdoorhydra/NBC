#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<int> food)
{
    string answer = "";
    deque<int> dq;

    dq.push_back(0);

    for (int i = food.size() - 1; i >= 0; i--)
    {
        while (food[i] >= 2)
        {
            dq.push_front(i);
            dq.push_back(i);
            food[i] -= 2;
        }
    }

    while (!dq.empty())
    {
        answer += to_string(dq.front());
        dq.pop_front();
    }

    return answer;
}