#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    vector<int> answer;
    map<char, int> m;

    for (auto& key : keymap)
    {
        int cnt = 0;
        for (auto& c : key)
        {
            cnt++;

            if (m.find(c) != m.end())
            {
                m[c] = min(m[c], cnt);
            }
            else if (m.find(c) == m.end())
            {
                m[c] = cnt;
            }
        }
    }

    for (auto& t : targets)
    {
        int mv = 0;

        for (auto& c : t)
        {
            if (m.find(c) == m.end())
            {
                mv = -1;
                break;
            }

            mv += m[c];
        }

        answer.push_back(mv);
    }

    return answer;
}