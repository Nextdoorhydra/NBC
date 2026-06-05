#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    unordered_map<char, int> dic;

    for (const auto& c : s)
    {
        dic[c] = -1;
    }

    for (int i = 0; i < s.size(); i++)
    {
        int offset = dic[s[i]] == -1 ? -1 : i - dic[s[i]];
        answer.push_back(offset);

        dic[s[i]] = i;
    }

    return answer;
}