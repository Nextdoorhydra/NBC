#include <string>
#include <vector>

using namespace std;

int solution(string t, string p)
{
    int answer = 0;
    long long target = stoll(p);

    auto start = t.begin();
    auto end = t.begin() + p.length();

    while (end != t.end() + 1)
    {
        string numS(start, end);
        long long num = stoll(numS);

        if (num <= target)
            answer++;

        start++;
        end++;
    }

    return answer;
}