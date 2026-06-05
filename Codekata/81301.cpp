#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s)
{
    string answer = "";
    string buf = "";

    unordered_map<string, char> dict = {
        {"zero" , '0'},
        {"one"  , '1'},
        {"two"  , '2'},
        {"three", '3'},
        {"four" , '4'},
        {"five" , '5'},
        {"six"  , '6'},
        {"seven", '7'},
        {"eight", '8'},
        {"nine" , '9'}
    };

    for (const auto& c : s)
    {
        if ('0' <= c && c <= '9')
        {
            answer.push_back(c);
        }
        else
        {
            buf.push_back(c);
        }

        if (dict.find(buf) != dict.end())
        {
            answer.push_back(dict[buf]);
            buf.clear();
        }
    }

    return stoi(answer);
}