#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer = { 0, 0 };
    string buf = s;
    string buf2 = "";

    do
    {
        answer[0]++;
        string watch = buf;
        buf.clear();

        for (char c : watch)
        {
            if (c - '0' == 1)
                buf.push_back(c);
            else
                answer[1]++;
        }

        int len = buf.size();

        while (len > 0)
        {
            buf2 += to_string(len % 2);
            len /= 2;
        }

        reverse(buf2.begin(), buf2.end());
        buf = buf2;
        buf2.clear();
    } while (buf.size() > 1);

    return answer;
}

int main()
{
    solution("110010101001");
    return 0;
}