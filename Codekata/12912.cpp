#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int a, int b)
{
    if (a == b) return a;

    long long answer = 0;
    int x, y;

    x = min(a, b);
    y = max(a, b);

    for (long long i = x; i <= y; i++)
    {
        answer += i;
    }

    return answer;
}