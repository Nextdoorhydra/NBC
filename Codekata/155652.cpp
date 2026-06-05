#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(string s, string skip, int index)
{
    string answer = "";
    set<char> skipSet;

    for (auto& c : skip)
        skipSet.insert(c);

    auto skipChar = [&skipSet](char c, int i) {
        while (i > 0)
        {
            i--;

            c = c + 1 <= 'z' ? c + 1 : 'a';

            if (skipSet.find(c) != skipSet.end()) i++;
        }
        return c;
        };

    for (auto& c : s)
    {
        answer.push_back(skipChar(c, index));
    }

    return answer;
}