#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right)
{
    int answer = 0;

    for (int i = left; i <= right; i++)
    {
        int n = 0;

        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                n++;
        }

        answer += i * (n % 2 == 0 ? 1 : -1);
    }

    return answer;
}