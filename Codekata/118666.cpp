#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(vector<string> survey, vector<int> choices)
{
    vector<string> types = {
        "RCJA",
        "RCJN",
        "RCMA",
        "RCMN",
        "RFJA",
        "RFJN",
        "RFMA",
        "RFMN",
        "TCJA",
        "TCJN",
        "TCMA",
        "TCMN",
        "TFJA",
        "TFJN",
        "TFMA",
        "TFMN",
    };

    // 성격 유형이 같으면 사전 순
    map<string, int> m{
        { "R", 0 },
        { "T", 0 },
        { "C", 0 },
        { "F", 0 },
        { "J", 0 },
        { "M", 0 },
        { "A", 0 },
        { "N", 0 },

        { "RCJA", 0 },
        { "RCJN", 0 },
        { "RCMA", 0 },
        { "RCMN", 0 },
        { "RFJA", 0 },
        { "RFJN", 0 },
        { "RFMA", 0 },
        { "RFMN", 0 },
        { "TCJA", 0 },
        { "TCJN", 0 },
        { "TCMA", 0 },
        { "TCMN", 0 },
        { "TFJA", 0 },
        { "TFJN", 0 },
        { "TFMA", 0 },
        { "TFMN", 0 },
    };

    for (int i = 0; i < survey.size(); i++)
    {
        string first = to_string(survey[i][0]);
        string second = to_string(survey[i][1]);

        switch (choices[i])
        {
        case 1:
            m[second] += 3;
            break;
        case 2:
            m[second] += 2;
            break;
        case 3:
            m[second] += 1;
            break;
        case 4:
            break;
        case 5:
            m[first] += 1;
            break;
        case 6:
            m[first] += 2;
            break;
        case 7:
            m[first] += 3;
            break;
        }
    }

    for (auto& t : types)
    {
        int score = 0;

        for (auto& c : t)
        {
            score += m[to_string(c)];
        }

        m[t] = score;
    }

    sort(types.begin(), types.end(), [&](const string& s1, const string& s2) {
        if (m[s1] == m[s2])
            return s1 < s2;
        return m[s1] < m[s2];
        });

    return types[0];
}