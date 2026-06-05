#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;

    int xcnt = 0, nxcnt = 0;
    char target = ' ';

    for (auto& c : s)
    {
        if (xcnt == 0)
        {
            xcnt++;
            nxcnt = 0;
            target = c;
            continue;
        }

        if (c == target)
        {
            xcnt++;
        }
        else
        {
            nxcnt++;
        }

        if (xcnt == nxcnt)
        {
            answer++;
            xcnt = 0;
        }
    }

    return answer + (xcnt != 0 ? 1 : 0);
}