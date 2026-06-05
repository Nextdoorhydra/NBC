#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> babbling)
{
    int answer = 0;
    unordered_map<string, int> m = { {"aya", 3}, {"ye", 2}, {"woo", 3}, {"ma", 2} };
    string buf = "", last = "";

    for (auto& bab : babbling)
    {
        if (bab.size() <= 1) continue;

        buf.clear();
        last.clear();

        for (int i = 0; i < bab.size(); i++)
        {
            buf.push_back(bab[i]);

            if (last != buf && m.find(buf) != m.end())
            {
                last = buf;
                buf.clear();
            }
        }

        if (buf.size() == 0)
            answer++;
    }

    return answer;
}