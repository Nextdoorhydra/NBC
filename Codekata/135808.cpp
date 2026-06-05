#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

int solution(int k, int m, vector<int> score)
{
    int answer = 0;
    sort(score.begin(), score.end());
    stack<int> apple;

    for (int i : score)
    {
        apple.push(i);
    }

    while (apple.size() >= m)
    {
        int minPrice = INT_MAX;

        for (int i = 0; i < m; i++)
        {
            minPrice = min(minPrice, apple.top());
            apple.pop();
        }

        answer += minPrice * m;
    }

    return answer;
}