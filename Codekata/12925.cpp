#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            answer = 10 * answer + s[i] - '0';
    }

    answer = s[0] == '-' ? answer * -1 : answer;

    return answer;
}