#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    vector<string> ss;
    string answer;
    string buf = "";
    s += ' ';
    int gap = 'a' - 'A';

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            ss.push_back(buf);
            buf.clear();
        }
        else
        {
            buf.push_back(s[i]);
        }
    }

    for (auto& _s : ss)
    {
        for (int i = 0; i < _s.size(); i++)
        {
            if (i % 2 == 0)
            {
                buf.push_back(_s[i] >= 'a' ? _s[i] - gap : _s[i]);
            }
            else
            {
                buf.push_back(_s[i] < 'a' ? _s[i] + gap : _s[i]);
            }
        }

        _s = buf;
        buf.clear();
    }


    for (auto& s : ss)
    {
        answer += s + ' ';
    }
    answer.pop_back();

    return answer;
}

// int main()
// {
//     solution("try hello world");
// }