#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    string buf = "";

    for (char c : s + ' ')
    {
        if (c == ' ')
        {
            if ('a' <= buf[0] && buf[0] <= 'z')
            {
                buf[0] += ('A' - 'a');
            }

            for (int i = 1; i < buf.size(); i++)
            {
                if ('A' <= buf[i] && buf[i] <= 'Z')
                {
                    buf[i] += ('a' - 'A');
                }
            }

            answer += buf + ' ';
            buf.clear();
        }
        else
            buf.push_back(c);
    }

    answer.pop_back();

    return answer;
}