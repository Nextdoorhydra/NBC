#include <string>
#include <vector>
#include <utility>
#include <map>

using namespace std;

// 모든 달은 28일
// + 6달이 폐기 날짜; -1일까지 유효
vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    map<char, int> dic;
    int index = 0;

    for (auto& s : terms)
    {
        string day = "";
        auto iter = s.begin() + 2;
        while (iter != s.end())
        {
            day.push_back(*iter);
            iter++;
        }

        dic[s[0]] = stoi(day);
    }

    auto parser = [](const string& s) {
        vector<int> parse;
        string buf = "";

        for (char c : s)
        {
            if (c == ' ')
            {
                parse.push_back(stoi(buf));
                buf.clear();
                break;
            }
            else if (c == '.')
            {
                parse.push_back(stoi(buf));
                buf.clear();
            }
            else
            {
                buf.push_back(c);
            }
        }

        return make_pair(parse, s.back());
        };

    auto convert_to_day = [](const vector<int>& s) {
        int year_to_day = s[0] * 12 * 28;
        int month_to_day = s[1] * 28;
        int day = s[2];

        return year_to_day + month_to_day + day;
        };

    vector<int> _today = parser(today + ' ').first;
    int __today = convert_to_day(_today);

    for (auto& s : privacies)
    {
        index++;

        auto parse = parser(s);
        vector<int> day = parse.first;
        char key = parse.second;

        day[1] += dic[key];

        if (__today >= convert_to_day(day))
        {
            answer.push_back(index);
        }
    }

    return answer;
}