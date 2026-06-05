#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;
    map<string, int> suspect;
    map<string, set<string>> reportWho;

    for (auto& id : id_list)
    {
        suspect[id] = 0;
        reportWho[id] = {};
    }

    for (auto& r : report)
    {
        vector<string> parse;
        string buf = "";
        r += ' ';

        for (char c : r)
        {
            if (c == ' ')
            {
                parse.push_back(buf);
                buf.clear();
                continue;
            }

            buf.push_back(c);
        }

        string reporter = parse[0];
        string reported = parse[1];

        if (reportWho[reporter].find(reported) == reportWho[reporter].end()) suspect[reported]++;
        reportWho[reporter].insert(reported);
    }

    for (auto& id : id_list)
    {
        int score = 0;

        for (auto& who : reportWho[id])
        {
            score += suspect[who] >= k ? 1 : 0;
        }

        answer.push_back(score);
    }

    return answer;
}

// int main()
// {
//     solution({ "con", "ryan" }, { "ryan con", "ryan con", "ryan con", "ryan con" }, 3);
//     return 0;
// }